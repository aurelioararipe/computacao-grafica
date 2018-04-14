/* Código para a criação de projeções
 * perspectivas e ortonais no OpenGL.
 * Também é mostrado como especificar uma câmera */

#include <GL/glut.h>

#define LARGURA  600		/* Width */
#define ALTURA   600		/* Heigth */

void Desenha_Origem()
{
	/* Define a cor Azul (BLUE) */
	glColor3f(0.0, 0.0, 1.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);

	glBegin(GL_POINTS);
		glVertex3i(0, 0, 0);
	glEnd();
}

void Desenha_Eixos_Coordenados()
{
	/* Desenha Eixo +Y */
	glColor3f(1.0, 0.0, 0.0); /* RED */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, ALTURA/2, 0);
	glEnd();

	/* Desenha Eixo +X */
	glColor3f(0.0, 0.0, 1.0); /* BLUE */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(LARGURA/2, 0, 0);
	glEnd();

	/* Desenha Eixo +Z */
	glColor3f(0.0, 1.0, 0.0); /* GREEN */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 0, LARGURA/2);
	glEnd();

}

void Desenha_Cubo(int lado_cubo)
{
	/* Define a cor do desenho para cinza */
	glColor3f(0.0f, 0.0f, 0.0f);

	/* Desenha a face BASE do cubo */
	glBegin(GL_LINE_LOOP);
		glVertex3d(lado_cubo/2, 0, lado_cubo/2);
		glVertex3d(-lado_cubo/2, 0, lado_cubo/2);
		glVertex3d(-lado_cubo/2, 0, -lado_cubo/2);
		glVertex3d(lado_cubo/2, 0,-lado_cubo/2);
	glEnd();

	/* Desenha a face TOPO do cubo */
	glBegin(GL_LINE_LOOP);
		glVertex3d(lado_cubo/2, lado_cubo, lado_cubo/2);
		glVertex3d(-lado_cubo/2, lado_cubo, lado_cubo/2);
		glVertex3d(-lado_cubo/2, lado_cubo, -lado_cubo/2);
		glVertex3d(lado_cubo/2, lado_cubo,-lado_cubo/2);
	glEnd();

	/* Desenha linhas laterais frontais do cubo */
	glBegin(GL_LINES);
		glVertex3d(lado_cubo/2, 0, lado_cubo/2);
		glVertex3d(lado_cubo/2, lado_cubo, lado_cubo/2);
		glVertex3d(-lado_cubo/2, 0, lado_cubo/2);
		glVertex3d(-lado_cubo/2, lado_cubo,lado_cubo/2);
	glEnd();

	/* Desenha linhas laterais traseiras do cubo */
	glBegin(GL_LINES);
		glVertex3d(lado_cubo/2, 0, -lado_cubo/2);
		glVertex3d(lado_cubo/2, lado_cubo, -lado_cubo/2);
		glVertex3d(-lado_cubo/2, 0, -lado_cubo/2);
		glVertex3d(-lado_cubo/2, lado_cubo,-lado_cubo/2);
	glEnd();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    /* Especifica uma Câmera com:
     * olho = (0, 0, 30)
     * olhar = (0, 0, 0)
     * up = (0, 1, 0) */
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 30.0,		/* eye */
    		  0.0, 0.0, 0.0,		/* look */
    		  0.0, 1.0, 0.0);		/* up */

    /* Rotaciona os objetos para visualizar a 3 dimensão */
	glRotatef(20.0, 1.0, 0.0, 0.0); /* Rotaciona em torno do X */
	glRotatef(20.0, 0.0, 1.0, 0.0); /* Rotaciona em torno de Y */

	Desenha_Origem();
	Desenha_Eixos_Coordenados();
	Desenha_Cubo(6);

	/* Executa os comandos OpenGL */
	glFlush();
}

void Janela(int opcao)
{
	switch(opcao){
		case 0:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);
			//glFrustum(-10, 10, -10, 10, 24, 500);

			break;

		case 1:
			/* Especifica uma projeção Ortogonal */
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-10, 10, -10, 10, -50 ,50);
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
	glutAddMenuEntry("Perspectiva", 0);
	glutAddMenuEntry("Ortogonal", 1);

	/* Indica qual o botao que acionará o menu */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal (Default) */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -50, 50);
}

/* Programa Principal */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Projecoes e Camera");
	glutDisplayFunc(Desenha);
	Inicializa();
	CriarMenu();
	glutMainLoop();
}

