/* Código exemplo de primitivas. Desenho de polígonos
 * convexo, côncavo e não convexo */

#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

/* Coordenadas do polígono convexo (simples) */
GLint qt_points_poly_convex = 5;
GLint polygon_convex[][2] = {100, 250,
  							 200, 400,
							 300, 300,
							 350, 250,
							 250, 200};

/* Coordenadas do polígono NÃO convexo (não simples = complexo) */
GLint qt_points_poly_not_convex = 5;
GLint polygon_not_convex[][2] = {100, 250,
  							     200, 400,
							     300, 300,
							     250, 200,
							     350, 250};

/* Coordenadas do polígono côncavo (não convexo) */
GLint qt_points_poly_concavo = 5;
GLint polygon_concavo[][2] = {150, 150,
  							  200, 200,
							  250, 220,
							  300, 400,
							  400, 180};

void Desenha_linha()
{
	/* Define a cor Vermelha (RED) */
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINES);
		glVertex2i(100, 100);		/* Coordenadas inicial da linha */
		glVertex2i(400, 400);		/* Coordenadas final da linha */
	glEnd();
}

void Desenha_polygon_convex()
{
	/* Define a cor Azul (BLUE) */
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);

		for(int i = 0; i < qt_points_poly_convex; i++)
			glVertex2i(polygon_convex[i][0], polygon_convex[i][1]);
	glEnd();
}

void Desenha_polygon_not_convex()
{
	/* Define a cor Azul (BLUE) */
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);

		for(int i = 0; i < qt_points_poly_not_convex; i++)
			glVertex2i(polygon_not_convex[i][0], polygon_not_convex[i][1]);
	glEnd();
}

void Desenha_polygon_concavo()
{
	/* Define a cor Azul (BLUE) */
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);

		for(int i = 0; i < qt_points_poly_concavo; i++)
			glVertex2i(polygon_concavo[i][0], polygon_concavo[i][1]);
	glEnd();
}

void Desenha_triangulo()
{
	/* Define a cor do desenho para cinza */
	glColor3f(0.5f, 0.5f, 0.5f);

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

	//Desenha_polygon_convex();
	//Desenha_polygon_not_convex();
	//Desenha_polygon_concavo();

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

