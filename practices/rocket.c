#include <GL/glut.h>
void inicializa(void) {
	glClearColor(0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 800, 0, 800);
}

void pinta(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN); // Une todos los puntos formando un cuadrado
	glColor3f(1, 1, 1);
	glVertex2i(300, 400);
	glVertex2i(500, 400);
	glVertex2i(500, 600);
	glVertex2i(300, 600);
	glEnd();
	
	glBegin(GL_TRIANGLE_FAN); // Une todos los puntos formando un cuadrado
	glVertex2i(300, 190);
	glVertex2i(500, 190);
	glVertex2i(500, 390);
	glVertex2i(300, 390);
	glEnd();
	
	glBegin(GL_TRIANGLES); // Genera triángulos
	// Wings
	glVertex2i(510, 340);
	glVertex2i(510, 190);
	glVertex2i(640, 190);
	
	glVertex2i(290, 340);
	glVertex2i(290, 190);
	glVertex2i(160, 190);
	glEnd();
	// Top
	glBegin(GL_TRIANGLES); // Genera triángulos
	glColor3f(1, 0, 0);
	glVertex2i(300, 610);
	glVertex2i(500, 610);
	glVertex2i(400, 783);
	
	// Engine 1
	glColor3f(.22, .2, .27);
	glVertex2i(325, 180);
	glVertex2i(305, 50);
	glVertex2i(345, 50);
	
	// Engine 2
	glVertex2i(375, 180);
	glVertex2i(355, 50);
	glVertex2i(395, 50);
	
	// Engine 3
	glVertex2i(425, 180);
	glVertex2i(405, 50);
	glVertex2i(445, 50);
	
	// Engine 4
	glVertex2i(475, 180);
	glVertex2i(455, 50);
	glVertex2i(495, 50);
	
	glColor3f(.9, .54, .18);
	// Fire 1
	glVertex2i(325, 5);
	glVertex2i(305, 45);
	glVertex2i(345, 45);
	
	// Fire 2
	glVertex2i(375, 5);
	glVertex2i(355, 45);
	glVertex2i(395, 45);
	
	// Fire 3
	glVertex2i(425, 5);
	glVertex2i(405, 45);
	glVertex2i(445, 45);
	
	// Fire 4
	glVertex2i(475, 5);
	glVertex2i(455, 45);
	glVertex2i(495, 45);
	
	glColor3f(.29, .7, .99);
	glVertex2i(325, 450);
	glVertex2i(475, 450);
	glVertex2i(400, 580);
	
	
	glEnd();
	glFlush();
}
	
	int main(int argc, char ** argv) {
		glutInitWindowSize(800, 800);
		glutInit(&argc, argv);
		glutCreateWindow("Mi primer programa");
		
		inicializa();
		glutDisplayFunc(pinta);
		glutMainLoop();
		return 0;
	}
	
