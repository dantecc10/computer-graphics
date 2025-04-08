#include <GL/glut.h>
#include <unistd.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Color del fondo
    glMatrixMode(GL_MODELVIEW);
    // gluLookAt(-2, 0, 5, 0, 0, 0, 0, 1, 5);

    gluLookAt(0, 0, 8, 0, 0, 0, 0, 1, 5);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 1, 15); // Perspectiva de la esfera
}

void Pinta3D(void)
{
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    // Dibujar una esfera
    glTranslated(-3, -3, 0);
    for (int i = 1; i <= 360; i++)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glRotated(i, 0, 0, 1);
        glRotated(i, 1, 0, 0);
        glScaled(1, 1, 1);
        glColor3f(1, 0, 0);
        glutSolidSphere(1.0, 30, 60);
        glScaled(.5, 1, .5);
        glColor3f(0, 1, 0);
        glutSolidSphere(1.0, 30, 60);
        glPopMatrix();
        glTranslated(.1, .1, 0);
        usleep(50000);
        glFlush();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Programa Básico en 3D");
    init();
    glutDisplayFunc(Pinta3D);
    glutMainLoop();
    return 0;
}
