#include <GL/glut.h>

void init(void)
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

// Dibuja una curva de Bézier a partir de 4 puntos de control
void dibujarCurva(float p0[3], float p1[3], float p2[3], float p3[3])
{
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &p0[0]);
    glEnable(GL_MAP1_VERTEX_3);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 100; i++)
    {
        glEvalCoord1f((GLfloat)i / 100.0);
    }
    glEnd();
}

void CurvaBezier(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glLineWidth(3);

    // Define los puntos de control (sólo se toca el primero y el último)
    float d1[4][3] = {
        {290.0, 190.0, 0.0},
        {290.0, 150.0, 0.0},
        {310.0, 140.0, 0.0},
        {310.0, 110.0, 0.0}};
    dibujarCurva(d1[0], d1[1], d1[2], d1[3]);

    float da[4][3] = {
        {310.0, 110.0, 0.0},
        {300.0, 90.0, 0.0},
        {335.0, 90.0, 0.0},
        {325.0, 110.0, 0.0}};
    dibujarCurva(da[0], da[1], da[2], da[3]);

    float d2[4][3] = {
        {350.0, 200.0, 0.0},
        {360.0, 160.0, 0.0},
        {325.0, 150.0, 0.0},
        {325.0, 110.0, 0.0}};
    dibujarCurva(d2[0], d2[1], d2[2], d2[3]);

    float d3[4][3] = {
        {290.0, 260.0, 0.0},
        {340.0, 260.0, 0.0},
        {350.0, 200.0, 0.0},
        {350.0, 200.0, 0.0},
    };
    dibujarCurva(d3[0], d3[1], d3[2], d3[3]);

    float d4[4][3] = {
        {290.0, 260.0, 0.0},
        {260.0, 265.0, 0.0},
        {230.0, 255.0, 0.0},
        {200.0, 260.0, 0.0},
    };
    dibujarCurva(d4[0], d4[1], d4[2], d4[3]);

    float d5[4][3] = {
        {200.0, 260.0, 0.0},
        {180.0, 270.0, 0.0},
        {170.0, 280.0, 0.0},
        {170.0, 300.0, 0.0},
    };
    dibujarCurva(d5[0], d5[1], d5[2], d5[3]);

    float d6[4][3] = {
        {170.0, 300.0, 0.0},
        {195.0, 315.0, 0.0},
        {195.0, 330.0, 0.0},
        {175.0, 370.0, 0.0},
    };
    dibujarCurva(d6[0], d6[1], d6[2], d6[3]);

    float d7[4][3] = {
        {175.0, 370.0, 0.0},
        {190.0, 450.0, 0.0},
        {150.0, 450.0, 0.0},
        {160.0, 375.0, 0.0},
    };
    dibujarCurva(d7[0], d7[1], d7[2], d7[3]); // Oreja

    float d8[4][3] = {
        {300.0, 145.0, 0.0},
        {270.0, 140.0, 0.0},
        {235.0, 140.0, 0.0},
        {205.0, 140.0, 0.0},
    };
    dibujarCurva(d8[0], d8[1], d8[2], d8[3]);

    float d9[4][3] = {
        {170.0, 190.0, 0.0},
        {170.0, 160.0, 0.0},
        {180.0, 140.0, 0.0},
        {180.0, 110.0, 0.0}
    };
    dibujarCurva(d9[0], d9[1], d9[2], d9[3]);

    float d10[4][3] = {
        {210.0, 190.0, 0.0},
        {198.0, 150.0, 0.0},
        {205.0, 140.0, 0.0},
        {195.0, 110.0, 0.0}
    };
    dibujarCurva(d10[0], d10[1], d10[2], d10[3]);

    float d11[4][3] = {
        {173.0, 145.0, 0.0},
        {135.0, 170.0, 0.0},
        {125.0, 190.0, 0.0},
        {125.0, 270.0, 0.0}
    };
    dibujarCurva(d11[0], d11[1], d11[2], d11[3]);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1600, 0);
    glutCreateWindow("Curva de Bezier");
    init();
    glutDisplayFunc(CurvaBezier);
    glutMainLoop();
    return 0;
}