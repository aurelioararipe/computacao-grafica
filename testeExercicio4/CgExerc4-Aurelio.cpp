/* Código que representa
 * a animação de uma Casa 2D */

#include <GL/glut.h>
#include <iostream>
using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

/* Variaveis para controlar a Animação */
double pos_x = 0;
double passoX = 3;
double passoY = 0;
double pos_y = 0;
int key_pressed = 0;
double gravidade = 0.1;
double movNormal = 9;

void Desenha_Casa()
{

	glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(75, 75);
		glVertex2i(75, 225);
		glVertex2i(225, 225);
		glVertex2i(225, 75);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(0.5f, 0.5f, 1.0f);
		glVertex2i(75, 225);
		glVertex2i(150, 250);
		glVertex2i(225, 225);

	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 1.0f);
                glVertex2i(125, 80);
                glVertex2i(125, 175);
                glVertex2i(175, 175);
                glVertex2i(175, 80);

               glColor3f(1.0f, 1.0f, 1.0f);
               glVertex2i(185, 160);
               glVertex2i(185, 180);
               glVertex2i(215, 180);
               glVertex2i(215, 160);

	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);	
		glVertex2i(200, 160);
		glVertex2i(200, 180);
                glVertex2i(185, 170);
                glVertex2i(215, 170);
	glEnd();

}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    	/* Transformar para animar */
	glTranslatef(pos_x, pos_y, 0.0);

	Desenha_Casa();

	/* Executa os comandos OpenGL */
	glutSwapBuffers();
}

void GerenciaTeclado(unsigned char key, int x, int y)
{
	switch (key) {
		case 'w':
			key_pressed = 1;
	}

/* Necessário chamar toda vez que se faz uma alteração ou evento na janela 
* Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
	glutPostRedisplay();
}

//void Anima()			 /* Usada quando se usar glutIdleFunc() */
void Anima(int value)  /* Usada quando se usar glutTimerFunc() */
{
	
	if(key_pressed == 1){	
		passoY = movNormal - gravidade;
		pos_y += passoY;
		gravidade += 0.05;

		pos_x += passoX;
		passoX *= 0.995;
		if (pos_x > 275 || pos_x < -75){
			passoX = (-1)*1.2*passoX;
		}
			

		
		if (pos_y >= 250){
			gravidade = 0.9 * passoY;
			//passoY = 0;
			movNormal = 0;
		}
		if (pos_y <= -75){
			movNormal = -0.9 * passoY;
			//passoY = 0;
			gravidade = 0;
			
		}
	}
	glutPostRedisplay();
	glutTimerFunc(20, Anima, 1);
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, LARGURA, 0, ALTURA);
}

/* Programa Principal */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Animacao Casa 2D");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(GerenciaTeclado);
	Inicializa();
	glutTimerFunc(100, Anima, 1);
	glutMainLoop();
}

