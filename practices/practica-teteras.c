#include <GL/glut.h>

void init(void)
{
    glClearColor(1.0, .5, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);

    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 5);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 1, 20);
}

void Pinta3D(void)
{
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);

    for (int i = 1; i <= 360; i++)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();
        glColor3f(1, 0, 0);
        glTranslated(4, 0, 0);
        glRotated(i, 0, 1, 0);
        glutWireTeapot(1.0);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0, 1);
        glTranslated(0, 0, 0);
        glRotated(i, 0, 1, 0);
        glutWireTeapot(1.0);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 1, 0);
        glTranslated(4, 0, 0);
        glRotated(i, 0, 1, 0);
        glutWireTeapot(1.0);
        glPopMatrix();

        Sleep(5000);
        glFlush();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Programa en 3D Teteras");
    init();
    glutDisplayFunc(Pinta3D);
    glutMainLoop();
    return 0;
}
