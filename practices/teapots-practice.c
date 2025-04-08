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

void teapot(int x_offset, int i, double r, double g, double b) // Se añade un parámetro para el desplazamiento
{
    glPushMatrix();               // Guardar la matriz de transformación actual
    glTranslated(x_offset, 0, 0); // Desplazar solo la tetera de la función
    glRotated(i, 0, 1, 0);
    glColor3f(r, g, b);
    glutWireTeapot(1.0); // Dibujar la tetera
    glPopMatrix();       // Restaurar la matriz original
}

void Pinta3D(void)
{
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    for (int i = 1; i <= 360; i++)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        teapot(-3, i, 1, 0, 0);
        teapot(0, i, 0, 1, 0);
        teapot(3, i, 0, 0, 1);
        usleep(5000);
        glFlush();
    }
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
