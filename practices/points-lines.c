#include <GL/glut.h>
void inicializa(void) {
	glClearColor(1.1, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
}

void pinta(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(10, 10);
	glVertex2i(100, 100);
	glEnd();
	glFlush();
}

	int main(int argc, char ** argv) {
		glutInitWindowSize(400, 400);
		glutInit(&argc, argv);
		glutCreateWindow("Mi primer programa");


		inicializa();

		glutDisplayFunc(pinta);
		glutMainLoop();
		return 0;
	}