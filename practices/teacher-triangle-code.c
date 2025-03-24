#include <GL/glut.h>
void inicializa(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(-600.0, 600.0, -600.0, 600.0);
    gluOrtho2D(-750.0, 750.0, -750.0, 750.0);
}
void pintatriangulo(void)
{
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 100);
    glVertex2i(400, 100);
    glVertex2i(250, 500);
    glEnd();
    glFlush();
}

void Transformaciones(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    pintatriangulo();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(100.0, 10.0, 0.0);
    pintatriangulo();
    glPopMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(50.0, 5.0, 0.0);
    pintatriangulo();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Transformaciones geométricas en OpenGL");
    inicializa();
    glutDisplayFunc(Transformaciones);
    glutMainLoop();
}