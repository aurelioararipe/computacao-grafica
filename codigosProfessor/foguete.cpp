/* Código inicial no OpenGL */

#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

void Bico(){
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3i(120, 240, 0);
		glVertex3i(160, 320, 0);
		glVertex3i(200, 240, 0);
	glEnd();
}

void Corpo(){
	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3i(120, 40, 0);
		glVertex3i(200, 40, 0);
		glVertex3i(200, 240, 0);
		glVertex3i(120, 240, 0);
	glEnd();
}

void AsaEsquerda(){
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3i(60, 40, 0);
		glVertex3i(120, 40, 0);
		glVertex3i(120, 120, 0);
	glEnd();

}

void AsaDireita(){
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3i(200, 40, 0);
		glVertex3i(260, 40, 0);
		glVertex3i(200, 120, 0);
	glEnd();

}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	/* Carrega na matriz corrente a matriz identidade */

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

	//glTranslatef(200.0f, 150.0f, 0.0f);
	//glRotatef(20, 0.0f, 0.0f, 1.0f);
	//glScalef(1.5f, 1.5f, 1.0f);
	glPushMatrix();
	glTranslatef(200.0f, 150.f, 0.0f);
	Bico();
	glPopMatrix();
	Bico();
	glPushMatrix();
	glScalef(0.5f, 0.5f, 1.0f);
	Corpo();
	glPopMatrix();
	glRotatef(30, 0.0f, 0.0f, 1.0f);
	Bico();
	Corpo();
	AsaEsquerda();
	AsaDireita();

	/* Executa os comandos OpenGL */
	glFlush();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

/* Programa Principal */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Transformacoes");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}

