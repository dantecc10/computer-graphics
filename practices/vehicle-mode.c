#include <GL/glut.h>
#include <math.h>

void inicializa(void)
{
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 800);
}

void circulo(float posx, float posy, float radio)
{
    int steps = 500;
    double step = 2 * M_PI / steps;
    double theta, x, y;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= steps; i++)
    {
        theta = i * step;
        x = posx + radio * cos(theta);
        y = posy + radio * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void cabeza()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    circulo(347, 281, 22);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(328, 272);
    glVertex2i(352, 272);
    glVertex2i(370, 273);
    glVertex2i(383, 278);
    glVertex2i(367, 293);
    glVertex2i(380, 296);
    glVertex2i(359, 301);
    glVertex2i(372, 314);
    glEnd();

    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2i(340, 285);
    glEnd();
}

void ventana()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(382, 350);
    glVertex2i(396, 264);
    glVertex2i(238, 223);
    glVertex2i(210, 265);
    glEnd();
}

void chasis()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(385, 169);
    glVertex2i(470, 196);
    glVertex2i(410, 365);
    glVertex2i(181, 252);
    glVertex2i(123, 195);
    glVertex2i(150, 171);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(210, 169);
    glVertex2i(324, 169);
    glVertex2i(332, 240);
    glVertex2i(342, 240);
    glEnd();
}

void llantas()
{
    glColor3f(1.0, 1.0, 1.0);
    circulo(175, 171, 25);
    circulo(349, 171, 25);
}

void pinta(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    cabeza();
    ventana();
    chasis();
    llantas();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInitWindowSize(800, 800);
    glutInit(&argc, argv);
    glutCreateWindow("Carro OpenGL");
    glutInitWindowPosition(400, 100);
    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();
    return 0;
}
