#include <GL/glut.h>

#define LARGURA 500
#define ALTURA 500

int teclado = 0;


void cabeca_boneco()
{
        glBegin(GL_QUADS);
	/* red green blue*/
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2i(30, 300);
		glVertex2i(30, 375);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex2i(105, 375);
		glVertex2i(105, 300);
	glEnd();
}

void corpo_boneco()
{
	glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2i(20, 100);
		glVertex2i(20, 295);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex2i(115, 295);
		glVertex2i(115, 100);
	glEnd();
}	

void olhos_boneco()
{
	glPointSize(5);
	glBegin(GL_POINTS);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(57.5, 347.5);
		glVertex2f(77.5, 347.5);
	glEnd();
}

void boca_boneco()
{
	glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(57.5, 327.5);
		glVertex2f(61.5, 322.5);
		glVertex2f(65.5, 320.0);
		glVertex2f(69.5, 320.0);
		glVertex2f(73.5, 322.5);
		glVertex2f(77.5, 327.5);
	glEnd();
}

void braco_boneco()
{
	glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(115, 295);
		glVertex2f(115, 197.5);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(135, 197.5);
		glVertex2f(135, 295);
	glEnd();
}

void antebraco_boneco()
{
	glBegin(GL_QUADS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(115, 197.5);
		glVertex2f(115, 148.75);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(135, 148.75);
		glVertex2f(135, 197.5);
	glEnd();

}

void desenha_boneco()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	cabeca_boneco();
	olhos_boneco();
	boca_boneco();
	corpo_boneco();
	braco_boneco();
	antebraco_boneco();
	glFlush();
	
}

/*void gerenciaTeclado(unsigned char key, int x, int y)
{
	switch(key)
	{
		case ''
	}

}*/

void Desenha(void)
{
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*glTranslatef(150.0f, 250.0f ,0.0f);*/
	desenha_boneco();
	
	glFlush();
}

void SpecialKeys(int key, int x, int y)
{

        if(key == GLUT_KEY_UP)
	{
		 glTranslatef(150.0, 250.0, 0.0);
	}else if(key == GLUT_KEY_DOWN)
	{
		glTranslatef(1.0, -5.0, 0.0);
	}else if(key == GLUT_KEY_LEFT)
	{
		glTranslatef(-5.0, 1.0, 0.0);
	}else if(key == GLUT_KEY_RIGHT)
	{
		glTranslatef(5.0, 1.0, 0.0);
	}
}


void Inicializa(void)
{
	/*red, green, blue, alpha */
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
        glOrtho(0, LARGURA, 0, ALTURA, -1, 1);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Segundo exercicio");
	glutDisplayFunc(Desenha);
	glutSpecialFunc(SpecialKeys);
	Inicializa();
	glutMainLoop();
}
                  
