#include <GL/glut.h>
void inicializa(void) {
	glClearColor(1.1, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void init(void){
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 0, 200);
}
void estilodelinea(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2, 0x00ff);
	glBegin(GL_LINES);
	glVertex2i(25, 25);
	glVertex2i(150, 25);
	glEnd();
	glLineStipple(2, 0x0c0f);
	glBegin(GL_LINES);
	glVertex2i(25, 50);
	glVertex2i(150, 50);
	glEnd();
	glLineStipple(4, 0xff22);
	glBegin(GL_LINES);
	glVertex2i(25, 75);
	glVertex2i(150, 75);
	glEnd();
	glLineStipple(2, 0xaaaa);
	glBegin(GL_LINES);
	glVertex2i(25, 100);
	glVertex2i(150, 100);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glFlush();
}

void pinta(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5);
	
	glBegin(GL_LINE_STRIP);

	glVertex2i(10, 10);
	glVertex2i(100, 10);
	glVertex2i(10, 60);
	glVertex2i(100, 60);

	glEnd();
	
	
	glFlush();
}
	
	int main(int argc, char ** argv) {
		glutInitWindowSize(200, 200);
		glutInit(&argc, argv);
		glutCreateWindow("Mi primer programa");
		
		init();
		glutDisplayFunc(estilodelinea);
		glutMainLoop();
		return 0;
	}
	
	
