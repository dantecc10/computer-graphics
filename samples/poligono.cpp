
#include <GL/glut.h>

void inicializa(void) 
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,400,0,400);
}


void pinta(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	

	glPolygonMode(GL_FRONT,GL_FILL);
	glFrontFace(GL_CW);
	glBegin(GL_POLYGON);
	
	glVertex2i(200,300);
	glVertex2i(300,200);
	glVertex2i(250,100);
	glVertex2i(150,100);
	glVertex2i(100,200);
	glEnd();
	
	glLineWidth(4.5);
	glColor3f(0.0,0.0,0.0);
	
	glPolygonMode(GL_FRONT,GL_LINE);
	glBegin(GL_POLYGON);
	
	glVertex2i(200,300);
	glVertex2i(300,200);
	glVertex2i(250,100);
	glVertex2i(150,100);	
	glVertex2i(100,200);
	
	glEnd();
	
	glFlush();
}

int main (int argc, char **argv) {
	glutInitWindowSize(400,300);
	glutInit(&argc,argv);
	glutCreateWindow("Silla en perspectiva 3D en 2D");
	inicializa();
	glutDisplayFunc(pinta);
	glutMainLoop();
	return 0;
}
