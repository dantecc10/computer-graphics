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

void triangle(int x_offset) // Se añade un parámetro para el desplazamiento
{
    glPushMatrix();               // Guardar la matriz de transformación actual
    glTranslated(x_offset, 0, 0); // Desplazar solo el triángulo

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(-800, 0);
    glVertex2i(-760, 0);
    glVertex2i(-780, 40);
    glEnd();

    glPopMatrix(); // Restaurar la matriz original
}

void paint(int x_offset)
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();             // Dibujar ejes fijos
    triangle(x_offset); // Dibujar el triángulo desplazado
    glFlush();
}

void show(void)
{
    int limit = 800, start = -800;
    while (start < limit)
    {
        usleep(50000);
        glClear(GL_COLOR_BUFFER_BIT);
        paint(start); // Pasar la posición actual del triángulo
        start += 20;
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