/* Código exemplo para criar duas Viewports */

#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

void Desenha_linha()
{
	/* Define a cor Vermelha (RED) */
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINES);
		glVertex2i(100, 100);		/* Coordenadas inicial da linha */
		glVertex2i(400, 400);		/* Coordenadas final da linha */
	glEnd();
}

void Desenha_triangulo()
{
	/* Define a cor do desenho para azul */
	glColor3f(0.0f, 0.0f, 1.0f);

	/* Desenha um triângulo na cor corrente */
	glBegin(GL_TRIANGLES);
		glVertex2i(300, 200);
		glVertex2i(350, 300);
		glVertex2i(400, 200);
	glEnd();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

	//glViewport(0, 0, 250, 250);
	Desenha_linha();

	//glViewport(250, 250, 250, 250);
	Desenha_triangulo();

	/* Executa os comandos OpenGL */
	glFlush();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

/* Programa Principal */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}

