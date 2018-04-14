/* Código que representa
 * a animação de um quadrado 2D */

#include <GL/glut.h>
#include <iostream>
using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

/* Variaveis para controlar a Animação */
int pos_x = 0;
int passo = 1;
int pos_y = 0;
int key_pressed = 0;
double rot = 0.0;

void Desenha_Quadrado()
{
	/* Define a cor do desenho para cinza */
	glColor3f(0.5f, 0.5f, 1.0f);

	/* Desenha um triângulo na cor corrente */
	glBegin(GL_POLYGON);
		glVertex2i(100, 100);
		glVertex2i(100, 200);
		glVertex2i(200, 200);
		glVertex2i(200, 100);
	glEnd();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* Ponto Central Cubo (150, 150) */

    /* Transformar para animar */
    glTranslatef(pos_x, pos_y, 0.0);

    glTranslatef(150, 150, 0.0);
    glRotatef(rot, 0.0, 0.0, 1.0);
    glTranslatef(-150, -150, 0.0);

	Desenha_Quadrado();

	/* Executa os comandos OpenGL */
	glutSwapBuffers();
}

/* Função callback chamada para gerenciar eventos de teclado */
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
	pos_x += passo;
	//pos_y++;

	if(pos_x > 150 || pos_x < 0)
		passo = (-1)*passo;

	rot += 1.0;

	if(key_pressed == 1)
		pos_y += passo;

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
	glutCreateWindow("Animacao Quadrado 2D");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(GerenciaTeclado);
	Inicializa();
	glutTimerFunc(100, Anima, 1);
	//glutIdleFunc(Anima);
	glutMainLoop();
}

