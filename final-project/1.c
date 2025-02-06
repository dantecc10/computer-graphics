#include <GL/glut.h>
#include <math.h>
void inicializa(void)
{
    glClearColor(0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 800);
}

void drawCircle(double x, double y, double r, int steps, double startAngle, double endAngle){
    double step;

    glColor3f(0, 1, 1); // Default white color

    glBegin(GL_POINTS);
    step = (endAngle - startAngle) / steps;
    for (double i = startAngle; i < endAngle; i += step){
        x = r * cos(i) + x;
        y = r * sin(i) + y;
        glVertex2i(x, y);
    }
}

void recycleSymbol(int x, int y, int u){

    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + 3 * u, y);
    glVertex2i(x + 3 * u, y - 2 * u);
    glVertex2i(x, y - 2 * u);
    glEnd();

}

void pinta(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //drawCircle(350, 400, 100, 100, 180, 360);

    recycleSymbol(300, 600, 10);

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInitWindowSize(800, 800);
    glutInit(&argc, argv);
    glutCreateWindow("Mi primer programa");
    glutInitWindowPosition(500, 500);

    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();
    return 0;
}
