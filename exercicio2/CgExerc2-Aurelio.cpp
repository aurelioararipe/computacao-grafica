#include <GL/glut.h>

#define LARGURA 500
#define ALTURA 500

#define tx 30 //translação
#define ty 30
float graus = 0, grausAntebraco = 0;


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

	glBegin(GL_TRIANGLES);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2i(35, 230);
		glVertex2i(60, 230);
		glVertex2i(40, 260);		
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2i(20, 230);
		glVertex2i(115, 230);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(0.0f,0.0f,0.0f);
                glVertex2i(75, 230);
                glVertex2i(100, 230);
                glVertex2i(95, 260);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2i(40, 260);
		glVertex2i(30, 295);
	glEnd();

	glBegin(GL_LINES);
                glColor3f(0.0f,0.0f,0.0f);
	        glVertex2i(95, 260);
	        glVertex2i(105, 295);
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

void desenha_boneco(int flag)
{
	glClear(GL_COLOR_BUFFER_BIT);

	if(flag==0)
	{
		
		cabeca_boneco();
		olhos_boneco();
		boca_boneco();
		corpo_boneco();
	
		glPushMatrix();

		glTranslatef(115, 295, 0);
		glRotatef(graus, 0, 0, 1);
		glTranslatef(-115, -295, 0);

		if(graus == grausAntebraco)
		{
			braco_boneco();
			antebraco_boneco();
		}else
		{
			braco_boneco();
			
			glTranslatef(135, 197.5, 0);
	                glRotatef(grausAntebraco, 0, 0, 1);
	                glTranslatef(-135, -197.5, 0);
	                antebraco_boneco();
		}
	
		glPopMatrix();

	}else if(flag==1)//rotacao do braco completo
	{
		glPushMatrix();
				
		glTranslatef(115, 295, 0);
		glRotatef(graus, 0, 0, 1);
		glTranslatef(-115, -295, 0);
		braco_boneco();
		antebraco_boneco();

		glPopMatrix();

		glPushMatrix();	
		desenha_boneco(0);
	}else //rotacao do antebraco
	{

		glPushMatrix();
		
		glTranslatef(135, 197.5, 0);
		glRotatef(grausAntebraco, 0, 0, 1);
		glTranslatef(-135, -197.5, 0);
		antebraco_boneco();

		glPopMatrix();

		glPushMatrix();


		desenha_boneco(0);
	}
	glFlush();

}

void Desenha(void)
{
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	desenha_boneco(0);
	
	glFlush();
}

void SpecialKeys(int key, int x, int y)
{

        if(key == GLUT_KEY_UP)
	{
	       	glTranslatef(1, ty, 0);
		desenha_boneco(0);
				

	}else if(key == GLUT_KEY_DOWN)
	{
		glTranslatef(1, -ty, 0);
		desenha_boneco(0);
	}else if(key == GLUT_KEY_LEFT)
	{
		glTranslatef(-tx, 1, 0);
		desenha_boneco(0);
	}else if(key == GLUT_KEY_RIGHT)
	{
		glTranslatef(tx, 1, 0);
		desenha_boneco(0);
	}
}

void NormalKeys(unsigned char key, int x, int y)
{
        switch(key)
        {
		case 'a':
			glScalef(1.3, 1.3, 0);
			desenha_boneco(0);
                break;

		case 'd':
                        glScalef(0.8, 0.8, 0);
                        desenha_boneco(0);
                break;

		case 'r':
			graus = graus + 30;

			desenha_boneco(1);	
		break;

		case 'e':
			grausAntebraco = grausAntebraco + 10;

			desenha_boneco(2);
		break;
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
	glutKeyboardFunc(NormalKeys);
	glutSpecialFunc(SpecialKeys);
	Inicializa();
	glutMainLoop();
}
                  
