/* Código exemplo para mostrar a interacao entre
 * teclado e mouse no desenho de um quadrado */

#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

/* Coordenadas do retângulo e da windows (janela) */
GLfloat xf, yf, win;

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	/* Desenha um retângulo preenchido com a cor corrente */
	glBegin(GL_POLYGON);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(xf, 0.0f);
		glVertex2f(xf, yf);
		glVertex2f(0.0f, yf);
	glEnd();

	glFlush();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como preta */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    xf = 50.0f;
    yf = 50.0f;
    win = 250.0f;

    glOrtho(-win, win, -win, win, -1, 1);
}

/* Função callback chamada para gerenciar eventos de teclado */
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
		case 'R':
		case 'r':/* muda a cor corrente para vermelho */
			glColor3f(1.0f, 0.0f, 0.0f);
			break;

		case 'G':
		case 'g':/* muda a cor corrente para verde */
			glColor3f(0.0f, 1.0f, 0.0f);
			break;

		case 'B':
		case 'b':/* muda a cor corrente para azul */
			glColor3f(0.0f, 0.0f, 1.0f);
			break;

		case 'q':
			exit(1);
			break;
    }

    /* Necessário chamar toda vez que se faz uma alteração ou evento na janela
     * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
    glutPostRedisplay();
}

/* Função callback chamada para gerenciar eventos do mouse */
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN) {
			/* Troca o tamanho do retângulo, que vai do centro da
			 * janela até a posição onde o usuário clicou com o mouse */
			xf = ( (2 * win * x) / LARGURA) - win;
			yf = ( ( (2 * win) * (y-ALTURA) ) / -ALTURA) - win;
		}
    }

    /* Necessário chamar toda vez que se faz uma alteração ou evento na janela
     * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
    glutPostRedisplay();
}

/* Programa Principal */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(LARGURA, ALTURA);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Exemplo de Interacao");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(GerenciaTeclado);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}

