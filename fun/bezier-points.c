#include <GL/glut.h>
#include <math.h>

void inicializa(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

void Puntos(void)
{
    glPointSize(1);
    glBegin(GL_POINTS);

    // Inician matemáticas
    double t = 0.0;
    int order = 4;
    int control_points[5][2] = {
        {0, 0},
        {200, 550},
        {300, 10},
        {400, 350},
        {600, 0}};

    for (int j = 0; j <= 100; j++)
    {
        double t = j / 100.0;

        double ct[2] = {0.0, 0.0};

        for (int i = 0; i <= order; i++)
        {
            // Calcular el valor de Bi^n(t)
            double bi = (factorial(order) / (factorial(order - i) * factorial(i)));
            double bint = bi * pow(t, i) * pow((1 - t), order - i);

            // Multiplicar Ci por Bi^n(t)
            ct[0] += control_points[i][0] * bint;
            ct[1] += control_points[i][1] * bint;
        }
        glVertex2i((int)ct[0], (int)ct[1]);
        // t += 0.01;
    }

    glEnd();
    glFlush();
}

void Pinta(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    Puntos();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformaciones geometricas en OpenGL");
    inicializa();
    glutDisplayFunc(Pinta);
    glutMainLoop();
    return 0;
}