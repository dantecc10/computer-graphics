#include <GL/glut.h>

void inicializa(void) {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
};

//void PintaPoligono(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	//glPolygonMode(GL_FRONT, GL_LINE);
//	glPolygonMode(GL_FRONT, GL_POINT);
//	glBegin(GL_POLYGON);
//	glColor3f(0, 0, 1);
//	glVertex2i(200, 300);
//	glColor3f(0, 1, 0);
//	glVertex2i(100, 200);
//	glColor3f(1, 0, 1);
//	glVertex2i(150, 100);
//	glColor3f(0, 1, 1);
//	glVertex2i(250, 100);
//	glColor3f(1, 1, 0);
//	glVertex2i(300, 200);
//	
//	glEnd();
//	glFlush();
//}

void PintaPoligono(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	//glPolygonMode(GL_FRONT, GL_LINE);
	glColor3f(0, 0, 1);
	glPolygonMode(GL_FRONT, GL_FILL);
	glFrontFace(GL_CW);
	glBegin(GL_POLYGON);
	glVertex2i(200, 300);
	glVertex2i(300, 200);
	glVertex2i(250, 100);
	glVertex2i(150, 100);
	glVertex2i(100, 200);
	glEnd();
	
	glLineWidth(4.5);
	glColor3f(1, 1, 1);
	
	glPolygonMode(GL_FRONT, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2i(200, 300);
	glVertex2i(300, 200);
	glVertex2i(250, 100);
	glVertex2i(150, 100);
	glVertex2i(100, 200);
	glEnd();
	glFlush();
}

int main (int argc, char **argv) {
	glutInit (&argc, argv);
	glutInitWindowSize (400,400);
	glutCreateWindow ("Primitivas en OpenGL");
	inicializa();
	glutDisplayFunc(PintaPoligono);
	glutMainLoop();
	return 0;
}

