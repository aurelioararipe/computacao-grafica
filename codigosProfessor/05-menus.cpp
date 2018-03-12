/* Código exemplo para mostrar a criação de Menus */

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

	Desenha_linha();
	Desenha_triangulo();

	/* Executa os comandos OpenGL */
	glFlush();
}

void Janela(int opcao)
{
	switch(opcao){
		case 0:
			glutReshapeWindow(300, 200);
			break;

		case 1:
			glutPositionWindow(250,200);
			break;

		case 2:
			glutFullScreen();
			break;

		case 3:
			glutReshapeWindow(LARGURA, ALTURA);
			glutPositionWindow(100, 100);
			break;
	}

	/* Necessário chamar toda vez que se faz uma alteração ou evento na janela
	 * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
	glutPostRedisplay();
}

void CriarMenu()
{
	/* Cria um menu cujas as opções serão gerenciadas pela funcao "Janela" */
	glutCreateMenu(Janela);

	/* Cria entradas nesse menu */
	glutAddMenuEntry("Muda Tamanho", 0);
	glutAddMenuEntry("Muda Posicao", 1);
	glutAddMenuEntry("Tela Cheia", 2);
	glutAddMenuEntry("Original", 3);

	/* Indica qual o botao que acionará o menu */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
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
	CriarMenu();
	glutMainLoop();
}

