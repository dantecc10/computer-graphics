#include <GL/glut.h>
#include <math.h>

void initialize(void)
{
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1000, 0, 1000);
}

void circle(float posx, float posy, float radius)
{
    int steps = 500;
    double step = 2 * M_PI / steps;
    double theta, x, y;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= steps; i++)
    {
        theta = i * step;
        x = posx + radius * cos(theta);
        y = posy + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void head()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    circle(347, 281, 22);
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

void window()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(382, 350);
    glVertex2i(396, 264);
    glVertex2i(238, 223);
    glVertex2i(210, 265);
    glEnd();
}

void vehicle()
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

void wheels()
{
    glColor3f(1.0, 1.0, 1.0);
    circle(175, 171, 25);
    circle(349, 171, 25);
}

void paint(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    head();
    window();
    vehicle();
    wheels();
    glFlush();
}
void show(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslated(255, -70, 0);
    paint();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInitWindowSize(1000, 1000);
    glutInit(&argc, argv);
    glutCreateWindow("Castelán Carpinteyro Dante - Carro");
    glutInitWindowPosition(400, 100);
    initialize();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
