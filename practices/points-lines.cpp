// Mi primer programa de graficación
// Graficación, primavera 2025



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

	
// Rutina de visualización
int main(int argc, char ** argv) {
	glutInitWindowSize(400, 400); // Tamaño de la ventana de visualización
	glutInit(&argc, argv);
	glutCreateWindow("Mi primer programa"); // Crea la ventana de visualización
	
	inicializa();
	glutDisplayFunc(pinta); // Pinta lo que ordene
	glutMainLoop(); // Espera órdenes
	return 0;
}
