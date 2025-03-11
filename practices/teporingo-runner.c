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
    glLineWidth(3);

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

void Conejo(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    // Reference: Mandíbula del conejo 1
    float c19[4][3] = {
        {350.0, 440.0, 0.0},
        {320.0, 400.0, 0.0},
        {220.0, 375.0, 0.0},
        {150.0, 390.0, 0.0}};
    drawCurve(c19[0], c19[1], c19[2], c19[3]);

    // Reference: Mandíbula del conejo 2
    float c20[4][3] = {
        {150.0, 390.0, 0.0},
        {110.0, 400.0, 0.0},
        {95.0, 400.0, 0.0},
        {75.0, 450.0, 0.0}};
    drawCurve(c20[0], c20[1], c20[2], c20[3]);

    // Reference: Nariz (externo)
    float c21[4][3] = {
        {75.0, 450.0, 0.0},
        {70.0, 460.0, 0.0},
        {80.0, 472.0, 0.0},
        {90.0, 480.0, 0.0}};
    drawCurve(c21[0], c21[1], c21[2], c21[3]);

    // Reference: Nariz (interno)
    float c22[4][3] = {
        {75.0, 450.0, 0.0},
        {85.0, 460.0, 0.0},
        {105.0, 470.0, 0.0},
        {90.0, 480.0, 0.0}};
    drawCurve(c22[0], c22[1], c22[2], c22[3]);

    // Reference: Nariz a la cabeza
    float c23[4][3] = {
        {90.0, 480.0, 0.0},
        {95.0, 485.0, 0.0},
        {130.0, 545.0, 0.0},
        {150.0, 570.0, 0.0}};
    drawCurve(c23[0], c23[1], c23[2], c23[3]);

    // Reference: Curva de la cabeza
    float c24[4][3] = {
        {150.0, 570.0, 0.0},
        {170.0, 600.0, 0.0},
        {250.0, 620.0, 0.0},
        {300.0, 610.0, 0.0}};
    drawCurve(c24[0], c24[1], c24[2], c24[3]);

    // Reference: Curva 1 de la oreja principal
    float c25[4][3] = {
        {300.0, 590.0, 0.0},
        {280.0, 670.0, 0.0},
        {345.0, 740.0, 0.0},
        {430.0, 750.0, 0.0}};
    drawCurve(c25[0], c25[1], c25[2], c25[3]);

    // Reference: Curva 2 de la oreja principal
    float c26[4][3] = {
        {355.0, 550.0, 0.0},
        {460.0, 640.0, 0.0},
        {435.0, 735.0, 0.0},
        {430.0, 750.0, 0.0}};
    drawCurve(c26[0], c26[1], c26[2], c26[3]);

    // Reference: Curva 1 interna de la oreja principal
    float c27[4][3] = {
        {341.0, 555.0, 0.0},
        {443.0, 640.0, 0.0},
        {425.0, 735.0, 0.0},
        {422.0, 730.0, 0.0}};
    drawCurve(c27[0], c27[1], c27[2], c27[3]);

    // Reference: Curva 2 interna de la oreja principal
    float c28[4][3] = {
        {315.0, 575.0, 0.0},
        {293.0, 640.0, 0.0},
        {335.0, 735.0, 0.0},
        {422.0, 730.0, 0.0}};
    drawCurve(c28[0], c28[1], c28[2], c28[3]);

    // Reference: Curva 1 de la oreja secundaria
    float c29[4][3] = {
        {370.0, 735.0, 0.0},
        {355.0, 770.0, 0.0},
        {350.0, 770.0, 0.0},
        {340.0, 780.0, 0.0}};
    drawCurve(c29[0], c29[1], c29[2], c29[3]);

    // Reference: Curva 2 de la oreja secundaria
    float c30[4][3] = {
        {295.0, 705.0, 0.0},
        {315.0, 770.0, 0.0},
        {324.0, 770.0, 0.0},
        {340.0, 780.0, 0.0}};
    drawCurve(c30[0], c30[1], c30[2], c30[3]);

    float c31[4][3] = {
        {295.0, 705.0, 0.0},
        {285.0, 680.0, 0.0},
        {288.0, 630.0, 0.0},
        {288.0, 610.0, 0.0}};
    drawCurve(c31[0], c31[1], c31[2], c31[3]);

    // Ojo (dividido entre 4 sectores curvos)
    // Reference: Curva 1 de la pupila
    float c32[4][3] = {
        {200.0, 530.0, 0.0},
        {210.0, 527.32, 0.0},
        {217.32, 520.0, 0.0},
        {220.0, 510.0, 0.0}};
    drawCurve(c32[0], c32[1], c32[2], c32[3]);

    // Reference: Curva 2 de la pupila
    float c33[4][3] = {
        {200.0, 530.0, 0.0},
        {190.0, 527.32, 0.0},
        {182.67, 520.0, 0.0},
        {180.0, 510.0, 0.0}};
    drawCurve(c33[0], c33[1], c33[2], c33[3]);

    // Reference: Curva 3 de la pupila
    float c34[4][3] = {
        {180.0, 510.0, 0.0},
        {182.67, 500.0, 0.0},
        {190.0, 492.67, 0.0},
        {200.0, 490.0, 0.0}};
    drawCurve(c34[0], c34[1], c34[2], c34[3]);

    // Reference: Curva 4 de la pupila
    float c35[4][3] = {
        {200.0, 490.0, 0.0},
        {210.0, 492.67, 0.0},
        {217.32, 500.0, 0.0},
        {220.0, 510.0, 0.0}};
    drawCurve(c35[0], c35[1], c35[2], c35[3]);

    // Reference: Ojo (parte blanca)
    float c36[4][3] = {
        {200.0, 530.0, 0.0},
        {210.0, 530.32, 0.0},
        {217.32, 525.0, 0.0},
        {230.0, 510.0, 0.0}};
    drawCurve(c36[0], c36[1], c36[2], c36[3]);

    // Reference: Ojo (parte blanca)
    float c37[4][3] = {
        {200.0, 530.0, 0.0},
        {190.0, 530.32, 0.0},
        {182.67, 525.0, 0.0},
        {170.0, 510.0, 0.0}};
    drawCurve(c37[0], c37[1], c37[2], c37[3]);

    // Reference: Ojo (parte blanca)
    float c38[4][3] = {
        {200.0, 490.0, 0.0},
        {210.0, 489.32, 0.0},
        {217.32, 495.0, 0.0},
        {230.0, 510.0, 0.0}};
    drawCurve(c38[0], c38[1], c38[2], c38[3]);

    // Reference: Ojo (parte blanca)
    float c39[4][3] = {
        {170.0, 510.0, 0.0},
        {182.67, 495.0, 0.0},
        {190.0, 489.32, 0.0},
        {200.0, 490.0, 0.0}};
    drawCurve(c39[0], c39[1], c39[2], c39[3]);

    // Reference: Lomo del conejo
    float c1[4][3] = {
        {400.0, 600.0, 0.0},
        {480.0, 635.0, 0.0},
        {560.0, 600.0, 0.0},
        {600.0, 575.0, 0.0}};
    drawCurve(c1[0], c1[1], c1[2], c1[3]); // Display curve

    // Reference: Curva del lomo del conejo
    float c2[4][3] = {
        {600.0, 575.0, 0.0},
        {630.0, 545.0, 0.0},
        {670.0, 545.0, 0.0},
        {700.0, 548.0, 0.0}};
    drawCurve(c2[0], c2[1], c2[2], c2[3]); // Display curve

    // Reference: Lomo trasero del conejo
    float c3[4][3] = {
        {700.0, 548.0, 0.0},
        {740.0, 560.0, 0.0},
        {800.0, 545.0, 0.0},
        {840.0, 520.0, 0.0}};
    drawCurve(c3[0], c3[1], c3[2], c3[3]); // Display curve

    // Reference: Cola del conejo
    float c4[4][3] = {
        {840.0, 520.0, 0.0},
        {883.62, 494.99, 0.0},
        {918.93, 447.84, 0.0},
        {885.0, 335.0, 0.0}};
    drawCurve(c4[0], c4[1], c4[2], c4[3]); // Display curve

    // Reference: Pata trasera del conejo
    float c5[4][3] = {
        {880.0, 375.0, 0.0},
        {885.0, 330.0, 0.0},
        {910.0, 325.0, 0.0},
        {905.0, 230.0, 0.0}};
    drawCurve(c5[0], c5[1], c5[2], c5[3]); // Display curve

    // Reference: Planta de la pata trasera del conejo
    float c6[4][3] = {
        {905.0, 230.0, 0.0},
        {902.0, 202.0, 0.0},
        {895.0, 150.0, 0.0},
        {845.0, 115.0, 0.0}};
    drawCurve(c6[0], c6[1], c6[2], c6[3]); // Display curve

    // Reference: [Área de garras] Punta de la pata trasera del conejo
    float c7[4][3] = {
        {845.0, 225.0, 0.0},
        {820.0, 198.0, 0.0},
        {810.0, 165.0, 0.0},
        {845.0, 115.0, 0.0}};
    drawCurve(c7[0], c7[1], c7[2], c7[3]); // Display curve

    // Reference: [Curva] Parte superior de la pata trasera del conejo
    float c8[4][3] = {
        {845.0, 225.0, 0.0},
        {850.0, 278.0, 0.0},
        {845.0, 292.0, 0.0},
        {820.0, 310.0, 0.0}};
    drawCurve(c8[0], c8[1], c8[2], c8[3]);

    // Reference: Músculo de la pata trasera del conejo
    float c9[4][3] = {
        {820.0, 310.0, 0.0},
        {780.0, 260.0, 0.0},
        {670.0, 240.0, 0.0},
        {620.0, 360.0, 0.0}};
    drawCurve(c9[0], c9[1], c9[2], c9[3]);

    // Reference: Músculo de la pata delantera principal
    float c10[4][3] = {
        {530.0, 400.0, 0.0},
        {510.0, 344.0, 0.0},
        {480.0, 286.0, 0.0},
        {380.0, 230.0, 0.0}};
    drawCurve(c10[0], c10[1], c10[2], c10[3]);

    // Reference: Parte de la pata delantera principal
    float c11[4][3] = {
        {380.0, 230.0, 0.0},
        {337.0, 210.0, 0.0},
        {293.0, 200.0, 0.0},
        {250.0, 210.0, 0.0}};
    drawCurve(c11[0], c11[1], c11[2], c11[3]);

    // Reference: Previo a pata delantera principal
    float c12[4][3] = {
        {400.0, 450.0, 0.0},
        {370.0, 404.0, 0.0},
        {360.0, 346.0, 0.0},
        {360.0, 310.0, 0.0}};
    drawCurve(c12[0], c12[1], c12[2], c12[3]);

    float c13[4][3] = {
        {360.0, 310.0, 0.0},
        {330.0, 290.0, 0.0},
        {300.0, 265.0, 0.0},
        {270.0, 270.0, 0.0}};
    drawCurve(c13[0], c13[1], c13[2], c13[3]);

    float c14[4][3] = {
        {270.0, 270.0, 0.0},
        {230.0, 290.0, 0.0},
        {170.0, 290.0, 0.0},
        {150.0, 230.0, 0.0}};
    drawCurve(c14[0], c14[1], c14[2], c14[3]);

    // Reference: Parte de la pata delantera principal
    float c15[4][3] = {
        {150.0, 230.0, 0.0},
        {178.0, 210.0, 0.0},
        {217.0, 200.0, 0.0},
        {250.0, 210.0, 0.0}};
    drawCurve(c15[0], c15[1], c15[2], c15[3]);

    // Reference: Vientre del conejo
    float c16[4][3] = {
        {662.0, 300.0, 0.0},
        {540.0, 270.0, 0.0},
        {500.0, 270.0, 0.0},
        {455.0, 280.0, 0.0}};
    drawCurve(c16[0], c16[1], c16[2], c16[3]);

    // Reference: Cuello del conejo
    float c17[4][3] = {
        {360.0, 310.0, 0.0},
        {340.0, 290.0, 0.0},
        {310.0, 380.0, 0.0},
        {290.0, 400.0, 0.0}};
    drawCurve(c17[0], c17[1], c17[2], c17[3]);

    // Reference: Músculo de la pata trasera secundaria del conejo
    float c18[4][3] = {
        {790.0, 250.0, 0.0},
        {750.0, 220.0, 0.0},
        {640.0, 210.0, 0.0},
        {600.0, 288.0, 0.0}};
    drawCurve(c18[0], c18[1], c18[2], c18[3]);

    // Reference: Pata trasera secundaria
    float c40[4][3] = {
        {790.0, 250.0, 0.0},
        {810.0, 230.0, 0.0},
        {815.0, 220.0, 0.0},
        {810.0, 200.0, 0.0}};
    drawCurve(c40[0], c40[1], c40[2], c40[3]);

    // Reference: Garras de la pata trasera secundaria
    float c41[4][3] = {
        {810.0, 200.0, 0.0},
        {805.0, 180.0, 0.0},
        {800.0, 160.0, 0.0},
        {830.0, 140.0, 0.0}};
    drawCurve(c41[0], c41[1], c41[2], c41[3]);

    // Reference: Pata delantera secundaria
    float c42[4][3] = {
        {310.0, 365.0, 0.0},
        {270.0, 350.0, 0.0},
        {215.0, 370.0, 0.0},
        {200.0, 310.0, 0.0}};
    drawCurve(c42[0], c42[1], c42[2], c42[3]);

    // Reference: Planta de la pata delantera secundaria
    float c43[4][3] = {
        {200.0, 310.0, 0.0},
        {190.0, 290.0, 0.0},
        {185.0, 280.0, 0.0},
        {160.0, 290.0, 0.0}};
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
    glutDisplayFunc(Conejo);
    glutMainLoop();
    return 0;
}