#include <GL/glut.h>
#include <math.h>
void inicializa(void)
{
    glClearColor(0.0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1600, 0, 1600);
}

void drawCircle(){

    glColor3f(1, 1, 1); // Default white color

    glBegin(GL_POLYGON);
    glVertex2i(400, 400);
    glVertex2i(400, 600);
    glVertex2i(361, 596.2);
    glVertex2i(323.46, 584.78);
    glVertex2i(288.88, 566.3);
    glVertex2i(258.58, 541.42);
    glVertex2i(233.7, 511.12);
    glVertex2i(215.22, 476.54);
    glVertex2i(203.8, 439);
    glVertex2i(200, 400);
    glEnd();
}

void pinta(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle();
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(1280, 10);
    glutInit(&argc, argv);
    glutCreateWindow("Mi primer programa");

    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();
    return 0;
}