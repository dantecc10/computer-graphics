#include <GL/glut.h>
void inicializa(void) {
	glClearColor(1, 1, 1, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void pinta(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1);
	glPointSize(1);
	glColor3f(0, 0, 0);
	
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(4, 0xff22);
	glBegin(GL_LINES);
	
	glVertex2i(300, 330);
	glVertex2i(300, 280);
	
	glVertex2i(200, 400);
	glVertex2i(200, 350);
	
	glEnd();
	
	glDisable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	
	glVertex2i(200, 400);
	glVertex2i(300, 380);
	
	glVertex2i(200, 350);
	glVertex2i(300, 330);
	
	glVertex2i(200, 400);
	glVertex2i(200, 350);
	
	glVertex2i(300, 380);
	glVertex2i(300, 330);
	glEnd();
	glFlush();
}
	
	int main(int argc, char ** argv) {
		glutInitWindowSize(500, 500);
		glutInit(&argc, argv);
		glutCreateWindow("Mi primer programa");
		
		inicializa();
		glutDisplayFunc(pinta);
		glutMainLoop();
		return 0;
	}
	
	
