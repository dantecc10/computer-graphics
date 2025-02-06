// Funcion que pinta un circulo
#include <GL/glut.h>
#include <math.h>

// Inicializacion
void inicializa(void)
{

    glClearColor(0.1, 0.1, 0.1, 0.0); // Background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600); // Los datos deben coincidir con el tamaño de la ventana
}

// Pintado
// void circle(void)
//{
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1, 1, 1);
//    double radius = 150.0, theta, step, x = 300, y = 20;
//    int steps = 500;
//    step = 2 * M_PI / steps;
//    glPointSize(4);
//
//    glBegin(GL_POLYGON);
//    for (int i = 0; i <= steps; i++)
//    {
//
//        theta = i * step;
//        x = radius * cos(theta);
//        y = radius * sin(theta);
//
//        // glColor3f(i / 255.0, 0, 255 - i / 511.0);
//        glVertex2i(x, y);
//    }
//    glEnd();
//
//    glFlush();
//}

void circle(float cx, float cy, float radius, float color1, float color2, float color3)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Establecer el color de relleno
    glColor3f(color1, color2, color3);

    // Definir el número de pasos para dibujar el círculo
    int steps = 500;
    double step = 2 * M_PI / steps; // Incremento angular
    double theta, x, y;

    glPointSize(4);

    // Dibujar el círculo como un polígono
    glBegin(GL_POLYGON);
    for (int i = 0; i <= steps; i++)
    {
        theta = i * step;                  // Ángulo actual
        x = cx + radius * cos(theta); // Coordenada x del punto
        y = cy + radius * sin(theta); // Coordenada y del punto

        glVertex2f(x, y); // Añadir el punto al polígono
    }
    glEnd();

    glFlush();
}

void pinta(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    circle(600, 600, 100, 0.0, 0.0, 1.0); // Azul: (0.0, 0.0, 1.0)
}

// Main
int main(int argc, char **argv)
{

    glutInitWindowSize(600, 600); // Los datos deben coincidir con gluOrtho2D
    glutInit(&argc, argv);

    glutCreateWindow("Circulo");
    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();

    return 0;
}
