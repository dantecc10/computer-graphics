// Mi primer programa de graficaci�n
// Graficaci�n, primavera 2025



#include <GL/glut.h>
void inicializa(void) {
	glClearColor(1.1, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
}

void pinta(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Points
	//glBegin(GL_POINTS);
	//glVertex2i(10, 10);
	//glVertex2i(100, 100);
	
	// Lines
	glBegin(GL_LINES);
	glVertex2i(10, 10);
	glVertex2i(100, 100);
	
	glEnd();
	glFlush();
}

	
// Rutina de visualizaci�n
int main(int argc, char ** argv) {
	glutInitWindowSize(400, 400); // Tama�o de la ventana de visualizaci�n
	glutInit(&argc, argv);
	glutCreateWindow("Mi primer programa"); // Crea la ventana de visualizaci�n
	
	inicializa();
	glutDisplayFunc(pinta); // Pinta lo que ordene
	glutMainLoop(); // Espera �rdenes
	return 0;
}
