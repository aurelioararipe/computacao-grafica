/* Código que representa a
 * a animação de um cubo 3D */

#include <GL/glut.h>

#define LARGURA  600		/* Width */
#define ALTURA   600		/* Heigth */

double rotationX = 20.0;
double rotationY = 20.0;

int last_press_x = 0;
int last_press_y = 0;

double rot = 0.0;

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

	/* Desenha Eixo -Y */
	glColor3f(1.0, 0.8, 0.8); /* RED claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, -ALTURA/2, 0);
	glEnd();

	/* Desenha Eixo +X */
	glColor3f(0.0, 0.0, 1.0); /* BLUE */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(LARGURA/2, 0, 0);
	glEnd();

	/* Desenha Eixo -X */
	glColor3f(0.8, 0.8, 1.0); /* BLUE claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(-LARGURA/2, 0, 0);
	glEnd();

	/* Desenha Eixo +Z */
	glColor3f(0.0, 1.0, 0.0); /* GREEN */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 0, LARGURA/2);
	glEnd();

	/* Desenha Eixo -Z */
	glColor3f(0.8, 1.0, 0.8); /* GREEN claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 0, -LARGURA/2);
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
	glRotatef(rotationY, 1.0, 0.0, 0.0); /* Rotaciona em torno do X */
	glRotatef(rotationX, 0.0, 1.0, 0.0); /* Rotaciona em torno de Y */

	Desenha_Origem();
	Desenha_Eixos_Coordenados();

	glRotated(rot, 0.0, 1.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);
    glutWireCube(6);
    //glutSolidCube(4);
	//glutWireSphere(4, 50, 50);
	//glutSolidSphere(4, 50, 50);
	glutWireCone(4.0, 8.0, 20, 20);
	glutWireTeapot(4);
	//glutWireTorus(1, 4, 20, 20);

	/* Executa os comandos OpenGL */
	//glFlush();
	glutSwapBuffers();
}

void Anima()			 /* Usada quando se usar glutIdleFunc() */
//void Anima(int value)  /* Usada quando se usar glutTimerFunc() */
{
	rot = rot + 2.0;
	if (rot > 360.0)
	  rot = rot - 360.0;

	glutPostRedisplay();
	//glutTimerFunc(30, Anima, 1);
}

/* Callback chamada quando o mouse é movido com
 * alguma tecla pressionada */
void Mouse_Motion(int x, int y)
{
	/* Se o mouse é movido para a esquerda, rotationX é decrementado
	 * caso contrário, aumentado. Mesma ideia para rotationY */
	rotationX += (double)(x - last_press_x);
	rotationY += (double)(y - last_press_y);

	last_press_x = x;
	last_press_y = y;

	glutPostRedisplay();
}

/* Callback chamada quando uma tecla é pressionada ou liberada */
void Mouse_Press(int button, int state, int x, int y)
{
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		/* Pega a posição atua do mouse */
		last_press_x = x;
		last_press_y = y;
	}
}

void Janela(int opcao)
{
	switch(opcao){
		case 0:
			/* Especifica uma projeção Perspective */
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Animacao Cubo 3D");
	glutDisplayFunc(Desenha);
	glutMouseFunc(Mouse_Press);
	glutMotionFunc(Mouse_Motion);
	Inicializa();
	CriarMenu();
	//glutTimerFunc(100, Anima, 1);
	glutIdleFunc(Anima);
	glutMainLoop();
}

