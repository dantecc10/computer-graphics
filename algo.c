#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

int ci, cs;
int cpuntos;
int xipv, xspv, yipv, yspv;

void inicializa(void)
{
    glClearColor(1, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void graficafuncion2dSubventana(void)
{
    double dx, xp, yp;
    double *xi = new double[cpuntos + 1];
    double *yi = new double[cpuntos + 1];
    double miny, maxy;
    dx = (cs - ci) * 1.0 / cpuntos;
    glClear(GL_COLOR_BUFFER_BIT);

    // Evalúa función
    for (int i = 0; i <= cpuntos; i++)
    {
        xi[i] = ci + i * dx;
        yi[i] = xi[i] * sin(xi[i]);
    }

    // Encuentra el valor mínimo y máximo de y
    miny = yi[0];
    maxy = yi[0];

    for (int i = 1; i <= cpuntos; i++)
    {
        if (yi[i] < miny)
            miny = yi[i];
        if (yi[i] > maxy)
            maxy = yi[i];
    }

    // Pinta los puntos aplicando la transformación
    for (int i = 0; i <= cpuntos; i++)
    {
        xp = xipv + (xspv - xipv) / (cs - ci) * (xi[i] - ci);
        yp = yipv + (yspv - yipv) / (maxy - miny) * (yi[i] - miny);
        glBegin(GL_POINTS);
        glVertex2d(xp, yp);
        glEnd();
    }
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    printf("Dame la cantidad de puntos (entero); ");
    scanf("%d", &cpuntos);
    printf("Valor inferior sobre x del punto de visión: ");
    scanf("%d", &xipv);
    printf("Valor superior sobre x del punto de visión: ");
    scanf("%d", &xspv);
    printf("Valor inferior sobre y del punto de visión: ");
    scanf("%d", &yipv);
    printf("Valor superior sobre y del punto de visión: ");
    scanf("%d", &yspv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Gráfica función en 2D");
    inicializa();
    glutDisplayFunc(graficafuncion2dSubventana);
    glutMainLoop();
    return 0;
}