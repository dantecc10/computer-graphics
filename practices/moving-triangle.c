#include <GL/glut.h>
#include <math.h>
#include <unistd.h>

void initialize(void)
{
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-800, 800, -800, 800);
}

void axis()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(-800, 0);
    glVertex2i(800, 0);
    glVertex2i(0, -800);
    glVertex2i(0, 800);
    glEnd();
}

void triangle()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES); // Triángulo equilátero con y = 0, y primer vértice en x = -800
    glVertex2i(-800, 0);
    glVertex2i(-760, 0);
    glVertex2i(-780, 40);
    glEnd();
}

void show(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int limit = 1600, start = 0;
    // Mientras el triángulo no llegue al límite de la ventana en x = 800 se seguirá desplazando 20 unidades a la derecha cada 0.05 segundos sin mover el eje
    while (start < limit)
    {
        usleep(50000);
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        glPushMatrix();
        glTranslated(start, 0, 0);
        triangle();
        glPopMatrix();
        glFlush();
        start += 10;
    }
}

int main(int argc, char **argv)
{
    glutInitWindowSize(800, 800);
    glutInit(&argc, argv);
    glutCreateWindow("Castelán Carpinteyro Dante - Triangulo");
    glutInitWindowPosition(400, 100);
    initialize();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
