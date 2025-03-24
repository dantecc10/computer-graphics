#include <GL/glut.h>
#include <math.h>
#include <unistd.h>

void initialize(void)
{
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 700, 0, 700);
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

void head(int mode)
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    circle(347, 281, 22);
    glEnd();

    glBegin(GL_LINES);
    // glVertex2i(328, 272);
    // glVertex2i(352, 272);
    // glVertex2i(370, 273);
    // glVertex2i(383, 278);
    // glVertex2i(367, 293);
    // glVertex2i(380, 296);
    // glVertex2i(359, 301);
    // glVertex2i(372, 314);
    glEnd();

    if (mode == 1)
    {
        glPointSize(3);
        glBegin(GL_POINTS);
        glVertex2i(340, 285);
        glEnd();
    }
    else
    {
        circle(340, 285, 3);
    }
}
void hair(int display)
{
    glColor3f(1.0, 1.0, 1.0);
    if (display == 1)
    {
        glBegin(GL_LINES);
        glVertex2i(370, 273);
        glVertex2i(383, 278);

        glVertex2i(367, 293);
        glVertex2i(380, 296);

        glVertex2i(359, 301);
        glVertex2i(372, 314);
        glEnd();
    }
}

void mouth(int x1, int y1, int x2, int y2, double c1, double c2, double c3)
{
    glColor3f(c1, c2, c3);
    glPolygonMode(GL_FRONT, GL_LINE);
    glBegin(GL_LINES);
    // glVertex2i(328, 272);
    // glVertex2i(352, 272);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
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
    //head();
    window();
    vehicle();
    wheels();
}

void show(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslated(200, -135, 0);
    paint();
    int direction = 2;
    while (1)
    {
        // Recorrer 20 pixeles a la izquierda en 15 pasos cada .5 segundos
        for (int i = 0; i < 15; i++)
        {
            usleep(500000);
            glClear(GL_COLOR_BUFFER_BIT);
            //(direction == 2) ? glTranslated(-20, 0, 0) : glTranslated(20, 0, 0);
            glTranslated(-20, 0, 0);
            paint();
            (i % 2 == 0) ? mouth(328, 272, 352, 272, 1.0, 1.0, 1.0) : mouth(338, 272, 350, 275, 1.0, 1.0, 1.0);
            (i % 2 == 0) ? hair(0) : hair(1);
            (i % 2 == 0) ? head(0) : head(1);
            glFlush();
        }
        if (direction == 2)
        {
            direction = 0;
            // Reflex en x
            glTranslated(600, 0, 0);
            glScalef(-1, 1, 0);
        }
        else
        {
            direction = 2;
            // glTranslatef(-600, 0, 0);
            glTranslated(600, 0, 0);
            glScalef(-1, 1, 0);
        }
    }
}

int main(int argc, char **argv)
{
    glutInitWindowSize(700, 700);
    glutInit(&argc, argv);
    glutCreateWindow("Castelán Carpinteyro Dante - Carro");
    glutInitWindowPosition(400, 100);
    initialize();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
