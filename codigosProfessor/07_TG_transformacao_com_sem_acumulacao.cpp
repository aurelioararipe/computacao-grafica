/* Código inicial no OpenGL */

#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

void Desenha_quadrado_cor_vermelho()
{
	/* Define a cor do quadrado para azul */
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2i(200, 350);
		glVertex2i(200, 450);
		glVertex2i(300, 450);
		glVertex2i(300, 350);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(250, 400);
	glEnd();
}

void Desenha_quadrado_cor_verde()
{
	/* Define a cor do quadrado para verde */
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2i(200, 200);
		glVertex2i(200, 300);
		glVertex2i(300, 300);
		glVertex2i(300, 200);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(250, 250);
	glEnd();
}

void Desenha_quadrado_cor_azul()
{
	/* Define a cor do quadrado para azul */
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2i(200, 50);
		glVertex2i(200, 150);
		glVertex2i(300, 150);
		glVertex2i(300, 50);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(250, 100);
	glEnd();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	/* Carrega na matriz corrente a matriz identidade */

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

	/* P_vermelhor = (250, 400) */
	/* P_verde = (250, 250) */
	/* P_azul = (250, 100) */

	glTranslatef(250.0, 400.0, 0.0);
	glScalef(0.5, 0.5, 1.0);
	glTranslatef(-250.0, -400.0, 0.0);
	Desenha_quadrado_cor_vermelho();

	glPushMatrix();
	glLoadIdentity();

	glTranslatef(250.0, 250.0, 0.0);
	glRotatef(30.0, 0.0, 0.0, 1.0);
	glTranslatef(-250.0, -250.0, 0.0);
	Desenha_quadrado_cor_verde();

	glPopMatrix();

	glLoadIdentity();
	Desenha_quadrado_cor_azul();

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

