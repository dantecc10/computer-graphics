#include <GL/glut.h>

void init(void)
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1000, 0, 800);
}

// Dibuja una curva de Bézier a partir de 4 puntos de control
void drawCurve(float p0[3], float p1[3], float p2[3], float p3[3])
{
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &p0[0]);
    glEnable(GL_MAP1_VERTEX_3);
    glColor3f(0, 0, 0); // Experimental
    glLineWidth(3);     // Experimental
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 100; i++)
    {
        glEvalCoord1f((GLfloat)i / 100.0);
    }
    glEnd();
}

void iDrawCurve(float p0[3], float p1[3], float p2[3], float p3[3], int fill, GLfloat fillColor[3])
{
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &p0[0]);
    glEnable(GL_MAP1_VERTEX_3);
    glLineWidth(5);

    if (fill) // Check if fill is enabled
    {
        glColor3f(fillColor[0], fillColor[1], fillColor[2]); // Set custom fill color
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 100; i++)
        {
            glEvalCoord1f((GLfloat)i / 100.0);
        }
        glEnd();
    }

    glColor3f(0, 0, 0); // Default line color
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 100; i++)
    {
        glEvalCoord1f((GLfloat)i / 100.0);
    }
    glEnd();
}

void polygon4Filler(float points[4][3], GLfloat fillColor[3])
{
    glColor3f(fillColor[0], fillColor[1], fillColor[2]); // Set custom fill color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; i++)
    {
        glVertex3f(points[i][0], points[i][1], points[i][2]);
    }
    glEnd();
}

void polygon3Filler(float points[3][3], GLfloat fillColor[3])
{
    glColor3f(fillColor[0], fillColor[1], fillColor[2]); // Set custom fill color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 3; i++)
    {
        glVertex3f(points[i][0], points[i][1], points[i][2]);
    }
    glEnd();
}

void Snoopy(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Reference: Mandíbula del conejo (pinta nariz)
    //polygon4Filler((float[4][3]){{90.0, 480.0, 0.0}, {75.0, 450.0, 0.0}, {150.0, 390.0, 0.0}, {350.0, 440.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Sonrisa
    float c1[4][3] = {
        {278.78, 485.0, 0.0},
        {344.0, 440.0, 0.0},
        {408.0, 435.0, 0.0},
        {501.0, 485.0, 0.0}};
    iDrawCurve(c1[0], c1[1], c1[2], c1[3], 0, (GLfloat[]){.3921, .2823, .1607});

    float c2[4][3] = {
        {501.0, 485.0, 0.0},
        {525.0, 492.0, 0.0},
        {522.0, 550.0, 0.0},
        {485.0, 580.0, 0.0}};
    iDrawCurve(c2[0], c2[1], c2[2], c2[3], 0, (GLfloat[]){.3921, .2823, .1607});

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(1600, 0);
    glutCreateWindow("Curva de Bezier");
    init();
    glutDisplayFunc(Snoopy);
    glutMainLoop();
    return 0;
}