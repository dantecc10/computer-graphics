// DAnte Castelán Carpinteyro

#include <GL/glut.h>
#include <math.h>
#include <unistd.h>

void inicializa(void)
{
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);
}

void drawCircle(float cx, float cy, float radius, float color1, float color2, float color3)
{
    // glClear(GL_COLOR_BUFFER_BIT);

    // Establecer el color de relleno
    glColor3f(color1, color2, color3);

    // Definir el número de pasos para dibujar el círculo
    int steps = 500;
    double step = 2 * M_PI / steps; // Incremento angular
    double theta, x, y;

    glPointSize(1);
    glLineWidth(1);

    // Dibujar el círculo como un polígono
    // glBegin(GL_POLYGON); // Sólo contorno
    glBegin(GL_LINE_LOOP);
    // No rellenar
    for (int i = 0; i <= steps; i++)
    {
        theta = i * step;             // Ángulo actual
        x = cx + radius * cos(theta); // Coordenada x del punto
        y = cy + radius * sin(theta); // Coordenada y del punto

        glVertex2f(x, y); // Añadir el punto al polígono
    }
    glEnd();

    glFlush();
}

void head()
{
    // Cuello
    glColor3f(1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT, GL_LINE);
    glBegin(GL_POLYGON);
    drawCircle(347, 281, 22, 1, 1, 1);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(210, 169);
    glVertex2i(324, 169);

    // glVertex2i(370, 273);
    // glVertex2i(383, 278);
    // glVertex2i(367, 293);
    // glVertex2i(380, 296);
    // glVertex2i(359, 301);
    // glVertex2i(372, 314);

    glVertex2i(332, 240);
    glVertex2i(342, 240);
    glEnd();

    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(340, 285);
    glEnd();
}

void hair(int enabled)
{
    if (!enabled) // if (enabled == 0)
    {
        return;
    }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(370, 273);
    glVertex2i(383, 278);
    glVertex2i(367, 293);
    glVertex2i(380, 296);
    glVertex2i(359, 301);
    glVertex2i(372, 314);
    glEnd();
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
    // Cuello
    glColor3f(1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT, GL_LINE);
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
    glPolygonMode(GL_FRONT, GL_LINE); // Aquí se asegura el modo contorno antes de comenzar
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
    glPolygonMode(GL_FRONT, GL_LINE);
    glBegin(GL_POLYGON);
    drawCircle(175, 171, 25, 1, 1, 1);
    glEnd();

    glBegin(GL_POLYGON);
    drawCircle(349, 171, 25, 1, 1, 1);
    glEnd();
}

void pinta(void)
{ 
    glClear(GL_COLOR_BUFFER_BIT);
    // Llamar funciones
    for (int i = 0; i < 100; i++)
    {
        usleep(500000);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        hair(i % 2 == 0);
        (i % 2 == 0) ? mouth(338, 272, 350, 275, 1.0, 1.0, 1.0) : mouth(325, 270, 345, 270, 1.0, 1.0, 1.0);
        head();
        window();
        vehicle();
        wheels();
    }
    // glFlush(); // La maestra dijo que le ponga un sólo flush
}

int main(int argc, char **argv)
{
    glutInitWindowSize(400, 400);
    glutInit(&argc, argv);
    glutCreateWindow("Castelán Carpinteyro Dante - CarroPlantilla.c");
    glutInitWindowPosition(1200, 400);
    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();
    return 0;
}
