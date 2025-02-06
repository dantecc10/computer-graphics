// Funcion que pinta un circulo
#include <GL/glut.h>
#include <math.h>

// Inicializacion
void inicializa (void) {

    glClearColor(0.1, 0.1, 0.1, 0.0); // Background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300, 300, -300, 300); // Los datos deben coincidir con el tamaño de la ventana

}

// Pintado
void circle (void) {

    glClear(GL_COLOR_BUFFER_BIT);
	
    double radio = 150.0;
    int n = 500;
    double teta, incremento, x, y;
    incremento = 2 * M_PI / n;
    glPointSize(4);

    for (int i = 0; i <= n; i++) {

        teta = i * incremento;
        x = radio * cos(teta);
        y = radio * sin(teta);

        glBegin(GL_POINTS);
			
			glColor3f(i / 255.0, 0, 255 - i / 511.0);
            glVertex2i(x, y);

        glEnd();
        
    }
	
    glFlush();

}

// Main
int main (int argc, char** argv) {

    glutInitWindowSize(600, 600); // Los datos deben coincidir con gluOrtho2D
    glutInit(&argc, argv);

    glutCreateWindow("Circulo");
    inicializa();
    glutDisplayFunc(circle);
    glutMainLoop();

    return 0;

}
