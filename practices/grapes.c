#include <GL/glut.h>
#include <unistd.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Color del fondo
    glMatrixMode(GL_MODELVIEW);
    // gluLookAt(-2, 0, 5, 0, 0, 0, 0, 1, 5);

    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 5);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 1, 15); // Perspectiva de la esfera
}

void falling_grape(int x_offset, int i, double r, double g, double b) // Se añade un parámetro para el desplazamiento
{
    glPushMatrix();               // Guardar la matriz de transformación actual
    glTranslated(x_offset, 0, 0); // Desplazar solo la tetera de la función
    // glRotated(i, 0, 1, 0);
    glScalef(.2, .25, .2);
    glColor3f(r, g, b);
    // glutWireTeapot(1.0); // Dibujar la tetera
    for (int i = 0; i < 35; i++)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glTranslated(0, -.5, 0);
        glutSolidSphere(1, 30, 30);
        glFlush();
        usleep(50000);
    }
    glPopMatrix(); // Restaurar la matriz original
}

void grape(char axis, double r, double g, double b)
{
    glPushMatrix();
    glColor3f(r, g, b);
    (axis == 'l') ? glTranslated(-.25, 0, 0) : glTranslated(.25, 0, 0);
    glScalef(.2, .25, .2);
    glutSolidSphere(1, 30, 30);
    glFlush();
    glPopMatrix();
}

void Pinta3D(void)
{
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    falling_grape(0, 0, 1, 0, 0);
    grape('l', 0, 1, 0);
    grape('r', 0, 1, 0);
    usleep(5000);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Programa Básico en 3D");
    init();
    glutDisplayFunc(Pinta3D);
    glutMainLoop();
    return 0;
}
