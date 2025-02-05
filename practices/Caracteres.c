// Plantilla graficacion en OpenGL

#include <GL/glut.h>

// Variables globales
GLint x = 300;
GLint y = 300;
GLubyte label[] = {'H', 'O', 'L', 'A'};

// Inicializacion
void inicializa (void) {
    glClearColor(0.1, 0.1, 0.1, 0.0); // Background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600); // Los datos deben coincidir con el tamaño de la ventana
}

void Trans2D(void) {
	GLint k;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.9, 0.9, 0.9);
	
	for (k = 0; k < 4; k++) {
		glRasterPos2i(x, y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, label[k]);
		x += 15;
	}
	
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'O');
	glFlush();	
}

// Main
int main (int argc, char** argv) {
    glutInitWindowSize(200, 150); // Los datos deben coincidir con gluOrtho2D
    glutInit(&argc, argv);

    glutCreateWindow("Plantilla");
    inicializa();
    glutDisplayFunc(Trans2D);
    glutMainLoop();
    return 0;
}