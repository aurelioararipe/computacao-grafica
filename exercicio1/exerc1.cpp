#include <GL/glut.h>

#define LARGURA 500
#define ALTURA 500

void Desenha1_triangulo()
{
	glBegin(GL_TRIANGLES);
		/* red green blue*/
		
	        glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(0,250);
		glVertex2i(500,250);
		glVertex2i(250,500);
	glEnd();

}


void Desenha2_triangulo_inverso_azul()
{
        glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);
	        glVertex2i(250,0);
		glColor3f(1.0f, 1.0f, 1.0f);
        	glVertex2i(0,250);
	        glVertex2i(500,250);
        glEnd();
}

void Desenha3_linha()
{
	glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.5f, 0.0f);
		glVertex2i(250,0);
		glVertex2i(350,330);
		glColor3f(0.0f, 0.8f, 0.0f);
		glVertex2i(150,200);
		glColor3f(0.0f, 1.0f, 0.0f);
	glEnd();	
}

void Desenho4_triangulo1()
{
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(250,250);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(500,250);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(250,500);
        glEnd();
}

void Desenho4_triangulo2()
{
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2i(500,500);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(500,250);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(250,500);
        glEnd();
}

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0,0,250,250);
	glScissor(0,0,250,250);
	glEnable(GL_SCISSOR_TEST);
	glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDisable(GL_SCISSOR_TEST);
        Desenha3_linha();
	
	glViewport(250,0,250,250);
	glScissor(250,0,250,250);
	glEnable(GL_SCISSOR_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDisable(GL_SCISSOR_TEST);
	Desenho4_triangulo1();
	Desenho4_triangulo2();

	glViewport(0,250,250,250);
	glScissor(0,250,250,250);
	glEnable(GL_SCISSOR_TEST);
	/*red, green, blue, alpha*/
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDisable(GL_SCISSOR_TEST);
	Desenha1_triangulo();

	glViewport(250,250,250,250);
	glScissor(250,250,250,250);
	glEnable(GL_SCISSOR_TEST);
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glDisable(GL_SCISSOR_TEST);
	Desenha1_triangulo();
       	Desenha2_triangulo_inverso_azul();

	glFlush();
}

void Inicializa(void)
{
	/*red, green, blue, alpha */
	/*glClearColor(1.0f, 0.0f, 0.0f, 0.0f);*/
	
	glOrtho(0, LARGURA, 0, ALTURA, -1, 1);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB);
        glutInitWindowSize (LARGURA, ALTURA);
        glutInitWindowPosition (100, 100);
        glutCreateWindow("Primeiro exercicio");
        glutDisplayFunc(Desenha);
        Inicializa();
        glutMainLoop();
}
