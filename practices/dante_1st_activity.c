#include <GL/glut.h>
void inicializa(void) {
	glClearColor(1.1, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void pinta(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5);
	glPointSize(5);
	glBegin(GL_POINTS);
		glVertex2i(175, 225);
		glVertex2i(250, 225);
		glVertex2i(325, 225);
	glEnd();
	
	glBegin(GL_LINES);
		glVertex2i(250, 380);
		glVertex2i(270, 360);
		
		glVertex2i(270,360);
		glVertex2i(230,360);
		
		glVertex2i(260, 370);
		glVertex2i(240, 370);
	
		glVertex2i(250, 380);
		glVertex2i(230, 360);
		
		glVertex2i(270, 360);
		glVertex2i(270, 300);
	
		glVertex2i(230, 360);
		glVertex2i(230, 300);
	
		glVertex2i(100, 300);
		glVertex2i(400, 300);
		
		glVertex2i(400, 300);
		glVertex2i(420, 320);
		
		glVertex2i(420, 320);
		glVertex2i(450, 320);
		
		glVertex2i(450, 320);
		glVertex2i(430, 300);
		
		glVertex2i(450, 320);
		glVertex2i(430, 300);
		
		glVertex2i(430, 300);
		glVertex2i(400, 300);
		
		glVertex2i(100, 300);
		glVertex2i(100, 150);
		
		glVertex2i(100, 270);
		glVertex2i(400, 270);
		
		glVertex2i(400, 300);
		glVertex2i(400, 150);
		
		glVertex2i(400, 150);
		glVertex2i(100, 150);
	glEnd();
	glFlush();
}
	
	int main(int argc, char ** argv) {
		glutInitWindowSize(500, 500);
		glutInit(&argc, argv);
		glutCreateWindow("Dante Castelán Carpinteyro: Primera Actividad [Lapicera]");
		
		inicializa();
		glutDisplayFunc(pinta);
		glutMainLoop();
		return 0;
	}
	
