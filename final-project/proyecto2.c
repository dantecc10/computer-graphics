// DAnte Castelán Carpinteyro

#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
void inicializa(void)
{
    glClearColor(.5490, .8, .9372, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 800);
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

    glPointSize(4);

    // Dibujar el círculo como un polígono
    glBegin(GL_POLYGON);
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

void sitting_rabbit(void)
{
    // glClear(GL_COLOR_BUFFER_BIT);
    //  Polígonos complementarios de relleno

    // Reference: Mitad trasera del conejo
    polygon4Filler((float[4][3]){{400, 600, 0}, {745.0, 420.0, 0.0}, {670.0, 145.0, 0.0}, {480.0, 125.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Pecho del conejo bajo cabeza
    polygon4Filler((float[4][3]){{468.0, 170.0, 0.0}, {310.0, 155.0, 0.0}, {155.0, 390.0, 0.0}, {350.0, 440.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Pecho a pata delantera principal
    polygon4Filler((float[4][3]){{155.0, 390.0, 0.0}, {245.0, 198.0, 0.0}, {308.0, 140.0, 0.0}, {310.0, 155.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Lomo-oreja a mandíbula a pata trasera a cola
    polygon4Filler((float[4][3]){{400.0, 600.0, 0.0}, {350.0, 440.0, 0.0}, {468.0, 170.0, 0.0}, {745.0, 420.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Pata delantera secundaria baja
    polygon4Filler((float[4][3]){{205.0, 130.0, 0.0}, {160.0, 119.0, 0.0}, {162.0, 130.0, 0.0}, {175.0, 150.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Pata delantera secundaria alta
    polygon4Filler((float[4][3]){{175.0, 150.0, 0.0}, {185.0, 233.0, 0.0}, {245.0, 198.0, 0.0}, {205.0, 130.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Pata delantera secundaria
    polygon4Filler((float[4][3]){{255.0, 198.0, 0.0}, {250.0, 180.0, 0.0}, {215.0, 125.0, 0.0}, {308.0, 140.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Cabeza del conejo

    // Reference: Mandíbula del conejo (pinta nariz)
    polygon4Filler((float[4][3]){{90.0, 480.0, 0.0}, {75.0, 450.0, 0.0}, {150.0, 390.0, 0.0}, {350.0, 440.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Cabeza central
    polygon4Filler((float[4][3]){{90.0, 480.0, 0.0}, {150.0, 570.0, 0.0}, {300.0, 610.0, 0.0}, {350.0, 440.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Cabeza (bajo orejas)
    polygon3Filler((float[3][3]){{400.0, 600.0, 0.0}, {300.0, 610.0, 0.0}, {350.0, 440.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Orejas del conejo
    polygon3Filler((float[3][3]){{400.0, 600.0, 0.0}, {430.0, 750.0, 0.0}, {288.0, 610.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Oreja secundaria del conejo
    polygon4Filler((float[4][3]){{370.0, 735.0, 0.0}, {340.0, 780.0, 0.0}, {295.0, 705.0, 0.0}, {288.0, 610.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});
    polygon3Filler((float[3][3]){{370.0, 735.0, 0.0}, {288.0, 610.0, 0.0}, {300.0, 610.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    polygon3Filler((float[3][3]){{422.0, 730.0, 0.0}, {341.0, 555.0, 0.0}, {315.0, 575.0, 0.0}}, (GLfloat[]){.5568, .5843, .7294});

    // Reference: Ojo complemento a parte blanca
    polygon4Filler((float[4][3]){{200.0, 530.0, 0.0}, {170.0, 510.0, 0.0}, {200.0, 490.0, 0.0}, {230.0, 510.0, 0.0}}, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Ojo complemento a retina
    polygon4Filler((float[4][3]){{200.0, 530.0, 0.0}, {180.0, 510.0, 0.0}, {200.0, 490.0, 0.0}, {220.0, 510.0, 0.0}}, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Lomo del conejo
    float c1[4][3] = {
        {400.0, 600.0, 0.0},
        {600.0, 615.0, 0.0},
        {715.0, 500.0, 0.0},
        {745.0, 420.0, 0.0}};
    // drawCurve(c1[0], c1[1], c1[2], c1[3]); // Display curve
    iDrawCurve(c1[0], c1[1], c1[2], c1[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve and optionally fill with custom color

    // Reference: Cola del conejo
    float c2[4][3] = {
        {745.0, 420.0, 0.0},
        {770.0, 350.0, 0.0},
        {750.0, 200.0, 0.0},
        {670.0, 145.0, 0.0}};
    // drawCurve(c2[0], c2[1], c2[2], c2[3]);
    iDrawCurve(c2[0], c2[1], c2[2], c2[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Planta de la pata trasera del conejo
    float c3[4][3] = {
        {670.0, 145.0, 0.0},
        {607.0, 125.0, 0.0},
        {533.0, 120.0, 0.0},
        {480.0, 125.0, 0.0}};
    // drawCurve(c3[0], c3[1], c3[2], c3[3]);
    iDrawCurve(c3[0], c3[1], c3[2], c3[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: [Área de garras] Punta de la pata trasera del conejo
    float c4[4][3] = {
        {480.0, 125.0, 0.0},
        {458.0, 160.0, 0.0},
        {465.0, 198.0, 0.0},
        {507.0, 205.0, 0.0}};
    // drawCurve(c4[0], c4[1], c4[2], c4[3]);
    iDrawCurve(c4[0], c4[1], c4[2], c4[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: [Curva] Parte superior de la pata trasera del conejo
    float c5[4][3] = {
        {507.0, 205.0, 0.0},
        {538.0, 210.0, 0.0},
        {561.0, 208.0, 0.0},
        {600.0, 180.0, 0.0}};
    drawCurve(c5[0], c5[1], c5[2], c5[3]);

    // Reference: Pierna del conejo
    float c6[4][3] = {
        {600.0, 180.0, 0.0},
        {530.0, 260.0, 0.0},
        {530.0, 325.0, 0.0},
        {585.0, 390.0, 0.0}};
    drawCurve(c6[0], c6[1], c6[2], c6[3]);

    // Reference_ Vientre del conejo
    float c7[4][3] = {
        {468.0, 170.0, 0.0},
        {430.0, 170.0, 0.0},
        {350.0, 140.0, 0.0},
        {310.0, 155.0, 0.0}};
    iDrawCurve(c7[0], c7[1], c7[2], c7[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Músculo de la pata delantera principal
    float c8[4][3] = {
        {385.0, 300.0, 0.0},
        {362.0, 265.0, 0.0},
        {340.0, 243.0, 0.0},
        {320.0, 220.0, 0.0}};
    drawCurve(c8[0], c8[1], c8[2], c8[3]);

    // Reference: Músculo-pata delantera principal
    float c9[4][3] = {
        {320.0, 220.0, 0.0},
        {317.0, 186.0, 0.0},
        {314.0, 164.0, 0.0},
        {308.0, 140.0, 0.0}};
    drawCurve(c9[0], c9[1], c9[2], c9[3]);

    // Reference: Planta de la pata delantera principal
    float c10[4][3] = {
        {308.0, 140.0, 0.0},
        {225.0, 90.0, 0.0},
        {205.0, 105.0, 0.0},
        {215.0, 125.0, 0.0}};
    // drawCurve(c10[0], c10[1], c10[2], c10[3]);
    iDrawCurve(c10[0], c10[1], c10[2], c10[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Punta de la pata delantera principal
    float c11[4][3] = {
        {215.0, 125.0, 0.0},
        {229.0, 148.0, 0.0},
        {237.0, 160.0, 0.0},
        {245.0, 180.0, 0.0}};
    iDrawCurve(c11[0], c11[1], c11[2], c11[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva unión de la pata del. prin. con pecho
    float c12[4][3] = {
        {245.0, 180.0, 0.0},
        {247.0, 186.0, 0.0},
        {247.0, 192.0, 0.0},
        {245.0, 198.0, 0.0}};
    drawCurve(c12[0], c12[1], c12[2], c12[3]);

    // Reference: Pecho del conejo
    float c13[4][3] = {
        {245.0, 198.0, 0.0},
        {150.0, 230.0, 0.0},
        {120.0, 330.0, 0.0},
        {155.0, 390.0, 0.0}};
    // drawCurve(c13[0], c13[1], c13[2], c13[3]);
    iDrawCurve(c13[0], c13[1], c13[2], c13[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Pata delantera secundaria
    float c14[4][3] = {
        {245.0, 198.0, 0.0},
        {235.0, 178.0, 0.0},
        {215.0, 130.0, 0.0},
        {205.0, 130.0, 0.0}};
    // drawCurve(c14[0], c14[1], c14[2], c14[3]);
    iDrawCurve(c14[0], c14[1], c14[2], c14[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Planta de la pata delantera secundaria
    float c15[4][3] = {
        {205.0, 130.0, 0.0},
        {190.0, 119.0, 0.0},
        {185.0, 116.0, 0.0},
        {160.0, 119.0, 0.0}};
    // drawCurve(c15[0], c15[1], c15[2], c15[3]);
    iDrawCurve(c15[0], c15[1], c15[2], c15[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Punta de la pata delantera secundaria
    float c16[4][3] = {
        {160.0, 119.0, 0.0},
        {158.0, 123.0, 0.0},
        {159.0, 127.0, 0.0},
        {162.0, 130.0, 0.0}};
    // drawCurve(c16[0], c16[1], c16[2], c16[3]);
    iDrawCurve(c16[0], c16[1], c16[2], c16[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva de la pata delantera secundaria
    float c17[4][3] = {
        {162.0, 130.0, 0.0},
        {168.0, 140.0, 0.0},
        {176.0, 146.0, 0.0},
        {175.0, 150.0, 0.0}};
    // drawCurve(c17[0], c17[1], c17[2], c17[3]);
    iDrawCurve(c17[0], c17[1], c17[2], c17[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Pata delantera secundaria
    float c18[4][3] = {
        {175.0, 150.0, 0.0},
        {178.0, 178.0, 0.0},
        {181.0, 206.0, 0.0},
        {185.0, 233.0, 0.0}};
    // drawCurve(c18[0], c18[1], c18[2], c18[3]);
    iDrawCurve(c18[0], c18[1], c18[2], c18[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Mandíbula del conejo 1
    float c19[4][3] = {
        {350.0, 440.0, 0.0},
        {320.0, 400.0, 0.0},
        {220.0, 375.0, 0.0},
        {150.0, 390.0, 0.0}};
    // drawCurve(c19[0], c19[1], c19[2], c19[3]);
    iDrawCurve(c19[0], c19[1], c19[2], c19[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Mandíbula del conejo 2
    float c20[4][3] = {
        {150.0, 390.0, 0.0},
        {110.0, 400.0, 0.0},
        {95.0, 400.0, 0.0},
        {75.0, 450.0, 0.0}};
    // drawCurve(c20[0], c20[1], c20[2], c20[3]);
    iDrawCurve(c20[0], c20[1], c20[2], c20[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Nariz (externo)
    float c21[4][3] = {
        {75.0, 450.0, 0.0},
        {70.0, 460.0, 0.0},
        {80.0, 472.0, 0.0},
        {90.0, 480.0, 0.0}};
    // drawCurve(c21[0], c21[1], c21[2], c21[3]);
    iDrawCurve(c21[0], c21[1], c21[2], c21[3], 1, (GLfloat[]){0.9058, 0.7215, 0.6862});

    // Reference: Nariz (interno)
    float c22[4][3] = {
        {75.0, 450.0, 0.0},
        {85.0, 460.0, 0.0},
        {105.0, 470.0, 0.0},
        {90.0, 480.0, 0.0}};
    iDrawCurve(c22[0], c22[1], c22[2], c22[3], 1, (GLfloat[]){0.9058, 0.7215, 0.6862});

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
    // drawCurve(c24[0], c24[1], c24[2], c24[3]);
    iDrawCurve(c24[0], c24[1], c24[2], c24[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva 1 de la oreja principal
    float c25[4][3] = {
        {300.0, 590.0, 0.0},
        {280.0, 670.0, 0.0},
        {345.0, 740.0, 0.0},
        {430.0, 750.0, 0.0}};
    // drawCurve(c25[0], c25[1], c25[2], c25[3]);
    iDrawCurve(c25[0], c25[1], c25[2], c25[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva 2 de la oreja principal
    float c26[4][3] = {
        {355.0, 550.0, 0.0},
        {460.0, 640.0, 0.0},
        {435.0, 735.0, 0.0},
        {430.0, 750.0, 0.0}};
    // drawCurve(c26[0], c26[1], c26[2], c26[3]);
    iDrawCurve(c26[0], c26[1], c26[2], c26[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva 1 interna de la oreja principal
    float c27[4][3] = {
        {341.0, 555.0, 0.0},
        {443.0, 640.0, 0.0},
        {425.0, 735.0, 0.0},
        {422.0, 730.0, 0.0}};
    // drawCurve(c27[0], c27[1], c27[2], c27[3]);
    iDrawCurve(c27[0], c27[1], c27[2], c27[3], 1, (GLfloat[]){.5568, .5843, .7294});

    // Reference: Curva 2 interna de la oreja principal
    float c28[4][3] = {
        {315.0, 575.0, 0.0},
        {293.0, 640.0, 0.0},
        {335.0, 735.0, 0.0},
        {422.0, 730.0, 0.0}};
    // drawCurve(c28[0], c28[1], c28[2], c28[3]);
    iDrawCurve(c28[0], c28[1], c28[2], c28[3], 1, (GLfloat[]){.5568, .5843, .7294});

    // Reference: Curva 1 de la oreja secundaria
    float c29[4][3] = {
        {370.0, 735.0, 0.0},
        {355.0, 770.0, 0.0},
        {350.0, 770.0, 0.0},
        {340.0, 780.0, 0.0}};
    // drawCurve(c29[0], c29[1], c29[2], c29[3]);
    iDrawCurve(c29[0], c29[1], c29[2], c29[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva 2 de la oreja secundaria
    float c30[4][3] = {
        {295.0, 705.0, 0.0},
        {315.0, 770.0, 0.0},
        {324.0, 770.0, 0.0},
        {340.0, 780.0, 0.0}};
    // drawCurve(c30[0], c30[1], c30[2], c30[3]);
    iDrawCurve(c30[0], c30[1], c30[2], c30[3], 1, (GLfloat[]){.3921, .2823, .1607});

    float c31[4][3] = {
        {295.0, 705.0, 0.0},
        {285.0, 680.0, 0.0},
        {288.0, 630.0, 0.0},
        {288.0, 610.0, 0.0}};
    // drawCurve(c31[0], c31[1], c31[2], c31[3]);
    iDrawCurve(c31[0], c31[1], c31[2], c31[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Ojo (dividido entre 4 sectores curvos)

    // Reference: Ojo (parte blanca)
    float c36[4][3] = {
        {200.0, 530.0, 0.0},
        {210.0, 530.32, 0.0},
        {217.32, 525.0, 0.0},
        {230.0, 510.0, 0.0}};
    // drawCurve(c36[0], c36[1], c36[2], c36[3]);
    iDrawCurve(c36[0], c36[1], c36[2], c36[3], 1, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Ojo (parte blanca)
    float c37[4][3] = {
        {200.0, 530.0, 0.0},
        {190.0, 530.32, 0.0},
        {182.67, 525.0, 0.0},
        {170.0, 510.0, 0.0}};
    // drawCurve(c37[0], c37[1], c37[2], c37[3]);
    iDrawCurve(c37[0], c37[1], c37[2], c37[3], 1, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Ojo (parte blanca)
    float c38[4][3] = {
        {200.0, 490.0, 0.0},
        {210.0, 489.32, 0.0},
        {217.32, 495.0, 0.0},
        {230.0, 510.0, 0.0}};
    // drawCurve(c38[0], c38[1], c38[2], c38[3]);
    iDrawCurve(c38[0], c38[1], c38[2], c38[3], 1, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Ojo (parte blanca)
    float c39[4][3] = {
        {170.0, 510.0, 0.0},
        {182.67, 495.0, 0.0},
        {190.0, 489.32, 0.0},
        {200.0, 490.0, 0.0}};
    // drawCurve(c39[0], c39[1], c39[2], c39[3]);
    iDrawCurve(c39[0], c39[1], c39[2], c39[3], 1, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Curva 1 de la pupila
    float c32[4][3] = {
        {200.0, 530.0, 0.0},
        {210.0, 527.32, 0.0},
        {217.32, 520.0, 0.0},
        {220.0, 510.0, 0.0}};
    // drawCurve(c32[0], c32[1], c32[2], c32[3]);
    iDrawCurve(c32[0], c32[1], c32[2], c32[3], 1, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Curva 2 de la pupila
    float c33[4][3] = {
        {200.0, 530.0, 0.0},
        {190.0, 527.32, 0.0},
        {182.67, 520.0, 0.0},
        {180.0, 510.0, 0.0}};
    // drawCurve(c33[0], c33[1], c33[2], c33[3]);
    iDrawCurve(c33[0], c33[1], c33[2], c33[3], 1, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Curva 3 de la pupila
    float c34[4][3] = {
        {180.0, 510.0, 0.0},
        {182.67, 500.0, 0.0},
        {190.0, 492.67, 0.0},
        {200.0, 490.0, 0.0}};
    // drawCurve(c34[0], c34[1], c34[2], c34[3]);
    iDrawCurve(c34[0], c34[1], c34[2], c34[3], 1, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Curva 4 de la pupila
    float c35[4][3] = {
        {200.0, 490.0, 0.0},
        {210.0, 492.67, 0.0},
        {217.32, 500.0, 0.0},
        {220.0, 510.0, 0.0}};
    // drawCurve(c35[0], c35[1], c35[2], c35[3]);
    iDrawCurve(c35[0], c35[1], c35[2], c35[3], 1, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Ojo pupila
    polygon4Filler((float[4][3]){{195.0, 528.0, 0}, {199.0, 528.0, 0.0}, {199.0, 524.0, 0.0}, {195.0, 524.0, 0.0}}, (GLfloat[]){1.0, 1.0, 1.0});

    glFlush();
}

void jumping_rabbit(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Reference: Polígonos complementarios de relleno

    // Pata delantera secundaria del conejo
    polygon3Filler((float[3][3]){{200.0, 300.0, 0.0}, {345.0, 310.0, 0.0}, {310.0, 365.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno final de la pata delantera principal
    polygon4Filler((float[4][3]){{150.0, 230.0, 0.0}, {250.0, 210.0, 0.0}, {380.0, 230.0, 0.0}, {270.0, 270.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno central de la pata delantera principal
    polygon4Filler((float[4][3]){{270.0, 270.0, 0.0}, {380.0, 230.0, 0.0}, {530.0, 400.0, 0.0}, {360.0, 310.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno lomo1-vientre-vientre-cuello
    polygon4Filler((float[4][3]){{600.0, 575.0, 0.0}, {662.0, 300.0, 0.0}, {455.0, 280.0, 0.0}, {360.0, 310.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno lomo1-vientre-vientre-cuello
    polygon4Filler((float[4][3]){{600.0, 575.0, 0.0}, {360.0, 310.0, 0.0}, {290.0, 400.0, 0.0}, {400.0, 600.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno general de la parte trasera
    polygon4Filler((float[4][3]){{600.0, 575.0, 0.0}, {840.0, 520.0, 0.0}, {840.0, 520.0, 0.0}, {600.0, 288.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno de la parte trasera
    polygon4Filler((float[4][3]){{600.0, 288.0, 0.0}, {620.0, 360.0, 0.0}, {840.0, 520.0, 0.0}, {790.0, 250.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno de la parte trasera (sobre patas)
    polygon4Filler((float[4][3]){{840.0, 520.0, 0.0}, {790.0, 250.0, 0.0}, {880.0, 375.0, 0.0}, {885.0, 335.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno de la parte trasera (sobre patas)
    polygon4Filler((float[4][3]){{790.0, 250.0, 0.0}, {880.0, 375.0, 0.0}, {905.0, 230.0, 0.0}, {820.0, 205.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Relleno de la parte trasera
    polygon3Filler((float[3][3]){{810.0, 200.0, 0.0}, {905.0, 230.0, 0.0}, {845.0, 115.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    /*
    {880.0, 375.0, 0.0},


    {905.0, 230.0, 0.0}};
    -
    -

    */

    // Reference: Cabeza del conejo
    // Reference: Mandíbula del conejo (pinta nariz)
    polygon4Filler((float[4][3]){{90.0, 480.0, 0.0}, {75.0, 450.0, 0.0}, {150.0, 390.0, 0.0}, {350.0, 440.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Cabeza central
    polygon4Filler((float[4][3]){{90.0, 480.0, 0.0}, {150.0, 570.0, 0.0}, {300.0, 610.0, 0.0}, {350.0, 440.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Cabeza (bajo orejas)
    polygon3Filler((float[3][3]){{400.0, 600.0, 0.0}, {300.0, 610.0, 0.0}, {350.0, 440.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Orejas del conejo
    polygon3Filler((float[3][3]){{400.0, 600.0, 0.0}, {430.0, 750.0, 0.0}, {288.0, 610.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Oreja secundaria del conejo
    polygon4Filler((float[4][3]){{370.0, 735.0, 0.0}, {340.0, 780.0, 0.0}, {295.0, 705.0, 0.0}, {288.0, 610.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});
    polygon3Filler((float[3][3]){{370.0, 735.0, 0.0}, {288.0, 610.0, 0.0}, {300.0, 610.0, 0.0}}, (GLfloat[]){.3921, .2823, .1607});

    polygon3Filler((float[3][3]){{422.0, 730.0, 0.0}, {341.0, 555.0, 0.0}, {315.0, 575.0, 0.0}}, (GLfloat[]){.5568, .5843, .7294});

    // Reference: Ojo complemento a parte blanca
    polygon4Filler((float[4][3]){{200.0, 530.0, 0.0}, {170.0, 510.0, 0.0}, {200.0, 490.0, 0.0}, {230.0, 510.0, 0.0}}, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Ojo complemento a retina
    polygon4Filler((float[4][3]){{200.0, 530.0, 0.0}, {180.0, 510.0, 0.0}, {200.0, 490.0, 0.0}, {220.0, 510.0, 0.0}}, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Mandíbula del conejo 1
    float c19[4][3] = {
        {350.0, 440.0, 0.0},
        {320.0, 400.0, 0.0},
        {220.0, 375.0, 0.0},
        {150.0, 390.0, 0.0}};
    // drawCurve(c19[0], c19[1], c19[2], c19[3]);
    iDrawCurve(c19[0], c19[1], c19[2], c19[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Mandíbula del conejo 2
    float c20[4][3] = {
        {150.0, 390.0, 0.0},
        {110.0, 400.0, 0.0},
        {95.0, 400.0, 0.0},
        {75.0, 450.0, 0.0}};
    // drawCurve(c20[0], c20[1], c20[2], c20[3]);
    iDrawCurve(c20[0], c20[1], c20[2], c20[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Nariz (externo)
    float c21[4][3] = {
        {75.0, 450.0, 0.0},
        {70.0, 460.0, 0.0},
        {80.0, 472.0, 0.0},
        {90.0, 480.0, 0.0}};
    // drawCurve(c21[0], c21[1], c21[2], c21[3]);
    iDrawCurve(c21[0], c21[1], c21[2], c21[3], 1, (GLfloat[]){0.9058, 0.7215, 0.6862});

    // Reference: Nariz (interno)
    float c22[4][3] = {
        {75.0, 450.0, 0.0},
        {85.0, 460.0, 0.0},
        {105.0, 470.0, 0.0},
        {90.0, 480.0, 0.0}};
    iDrawCurve(c22[0], c22[1], c22[2], c22[3], 1, (GLfloat[]){0.9058, 0.7215, 0.6862});

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
    // drawCurve(c24[0], c24[1], c24[2], c24[3]);
    iDrawCurve(c24[0], c24[1], c24[2], c24[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva 1 de la oreja principal
    float c25[4][3] = {
        {300.0, 590.0, 0.0},
        {280.0, 670.0, 0.0},
        {345.0, 740.0, 0.0},
        {430.0, 750.0, 0.0}};
    // drawCurve(c25[0], c25[1], c25[2], c25[3]);
    iDrawCurve(c25[0], c25[1], c25[2], c25[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva 2 de la oreja principal
    float c26[4][3] = {
        {355.0, 550.0, 0.0},
        {460.0, 640.0, 0.0},
        {435.0, 735.0, 0.0},
        {430.0, 750.0, 0.0}};
    // drawCurve(c26[0], c26[1], c26[2], c26[3]);
    iDrawCurve(c26[0], c26[1], c26[2], c26[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva 1 interna de la oreja principal
    float c27[4][3] = {
        {341.0, 555.0, 0.0},
        {443.0, 640.0, 0.0},
        {425.0, 735.0, 0.0},
        {422.0, 730.0, 0.0}};
    // drawCurve(c27[0], c27[1], c27[2], c27[3]);
    iDrawCurve(c27[0], c27[1], c27[2], c27[3], 1, (GLfloat[]){.5568, .5843, .7294});

    // Reference: Curva 2 interna de la oreja principal
    float c28[4][3] = {
        {315.0, 575.0, 0.0},
        {293.0, 640.0, 0.0},
        {335.0, 735.0, 0.0},
        {422.0, 730.0, 0.0}};
    // drawCurve(c28[0], c28[1], c28[2], c28[3]);
    iDrawCurve(c28[0], c28[1], c28[2], c28[3], 1, (GLfloat[]){.5568, .5843, .7294});

    // Reference: Curva 1 de la oreja secundaria
    float c29[4][3] = {
        {370.0, 735.0, 0.0},
        {355.0, 770.0, 0.0},
        {350.0, 770.0, 0.0},
        {340.0, 780.0, 0.0}};
    // drawCurve(c29[0], c29[1], c29[2], c29[3]);
    iDrawCurve(c29[0], c29[1], c29[2], c29[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva 2 de la oreja secundaria
    float c30[4][3] = {
        {295.0, 705.0, 0.0},
        {315.0, 770.0, 0.0},
        {324.0, 770.0, 0.0},
        {340.0, 780.0, 0.0}};
    // drawCurve(c30[0], c30[1], c30[2], c30[3]);
    iDrawCurve(c30[0], c30[1], c30[2], c30[3], 1, (GLfloat[]){.3921, .2823, .1607});

    float c31[4][3] = {
        {295.0, 705.0, 0.0},
        {285.0, 680.0, 0.0},
        {288.0, 630.0, 0.0},
        {288.0, 610.0, 0.0}};
    // drawCurve(c31[0], c31[1], c31[2], c31[3]);
    iDrawCurve(c31[0], c31[1], c31[2], c31[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Ojo (dividido entre 4 sectores curvos)

    // Reference: Ojo (parte blanca)
    float c36[4][3] = {
        {200.0, 530.0, 0.0},
        {210.0, 530.32, 0.0},
        {217.32, 525.0, 0.0},
        {230.0, 510.0, 0.0}};
    // drawCurve(c36[0], c36[1], c36[2], c36[3]);
    iDrawCurve(c36[0], c36[1], c36[2], c36[3], 1, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Ojo (parte blanca)
    float c37[4][3] = {
        {200.0, 530.0, 0.0},
        {190.0, 530.32, 0.0},
        {182.67, 525.0, 0.0},
        {170.0, 510.0, 0.0}};
    // drawCurve(c37[0], c37[1], c37[2], c37[3]);
    iDrawCurve(c37[0], c37[1], c37[2], c37[3], 1, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Ojo (parte blanca)
    float c38[4][3] = {
        {200.0, 490.0, 0.0},
        {210.0, 489.32, 0.0},
        {217.32, 495.0, 0.0},
        {230.0, 510.0, 0.0}};
    // drawCurve(c38[0], c38[1], c38[2], c38[3]);
    iDrawCurve(c38[0], c38[1], c38[2], c38[3], 1, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Ojo (parte blanca)
    float c39[4][3] = {
        {170.0, 510.0, 0.0},
        {182.67, 495.0, 0.0},
        {190.0, 489.32, 0.0},
        {200.0, 490.0, 0.0}};
    // drawCurve(c39[0], c39[1], c39[2], c39[3]);
    iDrawCurve(c39[0], c39[1], c39[2], c39[3], 1, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Curva 1 de la pupila
    float c32[4][3] = {
        {200.0, 530.0, 0.0},
        {210.0, 527.32, 0.0},
        {217.32, 520.0, 0.0},
        {220.0, 510.0, 0.0}};
    // drawCurve(c32[0], c32[1], c32[2], c32[3]);
    iDrawCurve(c32[0], c32[1], c32[2], c32[3], 1, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Curva 2 de la pupila
    float c33[4][3] = {
        {200.0, 530.0, 0.0},
        {190.0, 527.32, 0.0},
        {182.67, 520.0, 0.0},
        {180.0, 510.0, 0.0}};
    // drawCurve(c33[0], c33[1], c33[2], c33[3]);
    iDrawCurve(c33[0], c33[1], c33[2], c33[3], 1, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Curva 3 de la pupila
    float c34[4][3] = {
        {180.0, 510.0, 0.0},
        {182.67, 500.0, 0.0},
        {190.0, 492.67, 0.0},
        {200.0, 490.0, 0.0}};
    // drawCurve(c34[0], c34[1], c34[2], c34[3]);
    iDrawCurve(c34[0], c34[1], c34[2], c34[3], 1, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Curva 4 de la pupila
    float c35[4][3] = {
        {200.0, 490.0, 0.0},
        {210.0, 492.67, 0.0},
        {217.32, 500.0, 0.0},
        {220.0, 510.0, 0.0}};
    // drawCurve(c35[0], c35[1], c35[2], c35[3]);
    iDrawCurve(c35[0], c35[1], c35[2], c35[3], 1, (GLfloat[]){0.0, 0.0, 0.0});

    // Reference: Ojo pupila
    polygon4Filler((float[4][3]){{195.0, 528.0, 0}, {199.0, 528.0, 0.0}, {199.0, 524.0, 0.0}, {195.0, 524.0, 0.0}}, (GLfloat[]){1.0, 1.0, 1.0});

    // Reference: Lomo del conejo
    float c1[4][3] = {
        {400.0, 600.0, 0.0},
        {480.0, 635.0, 0.0},
        {560.0, 600.0, 0.0},
        {600.0, 575.0, 0.0}};
    // drawCurve(c1[0], c1[1], c1[2], c1[3]); // Display curve
    iDrawCurve(c1[0], c1[1], c1[2], c1[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Curva del lomo del conejo
    float c2[4][3] = {
        {600.0, 575.0, 0.0},
        {630.0, 553.0, 0.0},
        {670.0, 552.0, 0.0},
        {700.0, 548.0, 0.0}};
    drawCurve(c2[0], c2[1], c2[2], c2[3]); // Display curve

    // Reference: Lomo trasero del conejo
    float c3[4][3] = {
        {700.0, 548.0, 0.0},
        {740.0, 560.0, 0.0},
        {800.0, 545.0, 0.0},
        {840.0, 520.0, 0.0}};
    iDrawCurve(c3[0], c3[1], c3[2], c3[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Cola del conejo
    float c4[4][3] = {
        {840.0, 520.0, 0.0},
        {883.62, 494.99, 0.0},
        {918.93, 447.84, 0.0},
        {885.0, 335.0, 0.0}};
    iDrawCurve(c4[0], c4[1], c4[2], c4[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Pata trasera del conejo
    float c5[4][3] = {
        {880.0, 375.0, 0.0},
        {885.0, 330.0, 0.0},
        {910.0, 325.0, 0.0},
        {905.0, 230.0, 0.0}};
    iDrawCurve(c5[0], c5[1], c5[2], c5[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Planta de la pata trasera del conejo
    float c6[4][3] = {
        {905.0, 230.0, 0.0},
        {902.0, 202.0, 0.0},
        {895.0, 150.0, 0.0},
        {845.0, 115.0, 0.0}};
    iDrawCurve(c6[0], c6[1], c6[2], c6[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: [Área de garras] Punta de la pata trasera del conejo
    float c7[4][3] = {
        {845.0, 225.0, 0.0},
        {820.0, 198.0, 0.0},
        {810.0, 165.0, 0.0},
        {845.0, 115.0, 0.0}};
    iDrawCurve(c7[0], c7[1], c7[2], c7[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: [Curva] Parte superior de la pata trasera del conejo
    float c8[4][3] = {
        {845.0, 225.0, 0.0},
        {850.0, 278.0, 0.0},
        {845.0, 292.0, 0.0},
        {820.0, 310.0, 0.0}};
    iDrawCurve(c8[0], c8[1], c8[2], c8[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

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
    iDrawCurve(c10[0], c10[1], c10[2], c10[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Parte de la pata delantera principal
    float c11[4][3] = {
        {380.0, 230.0, 0.0},
        {337.0, 210.0, 0.0},
        {293.0, 200.0, 0.0},
        {250.0, 210.0, 0.0}};
    iDrawCurve(c11[0], c11[1], c11[2], c11[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Previo a pata delantera principal
    float c12[4][3] = {
        {400.0, 450.0, 0.0},
        {370.0, 404.0, 0.0},
        {360.0, 346.0, 0.0},
        {360.0, 310.0, 0.0}};
    iDrawCurve(c12[0], c12[1], c12[2], c12[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    float c13[4][3] = {
        {360.0, 310.0, 0.0},
        {330.0, 300.0, 0.0},
        {300.0, 280.0, 0.0},
        {270.0, 270.0, 0.0}};
    drawCurve(c13[0], c13[1], c13[2], c13[3]);

    float c14[4][3] = {
        {270.0, 270.0, 0.0},
        {230.0, 290.0, 0.0},
        {170.0, 290.0, 0.0},
        {150.0, 230.0, 0.0}};
    iDrawCurve(c14[0], c14[1], c14[2], c14[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Parte de la pata delantera principal
    float c15[4][3] = {
        {150.0, 230.0, 0.0},
        {178.0, 210.0, 0.0},
        {217.0, 200.0, 0.0},
        {250.0, 210.0, 0.0}};
    iDrawCurve(c15[0], c15[1], c15[2], c15[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Vientre del conejo
    float c16[4][3] = {
        {662.0, 300.0, 0.0},
        {540.0, 270.0, 0.0},
        {500.0, 270.0, 0.0},
        {455.0, 280.0, 0.0}};
    iDrawCurve(c16[0], c16[1], c16[2], c16[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Cuello del conejo
    float c17[4][3] = {
        {360.0, 310.0, 0.0},
        {340.0, 290.0, 0.0},
        {310.0, 380.0, 0.0},
        {290.0, 400.0, 0.0}};
    iDrawCurve(c17[0], c17[1], c17[2], c17[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Músculo de la pata trasera secundaria del conejo
    float c18[4][3] = {
        {790.0, 250.0, 0.0},
        {750.0, 220.0, 0.0},
        {640.0, 210.0, 0.0},
        {600.0, 288.0, 0.0}};
    iDrawCurve(c18[0], c18[1], c18[2], c18[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

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
    iDrawCurve(c41[0], c41[1], c41[2], c41[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    // Reference: Pata delantera secundaria
    float c42[4][3] = {
        {310.0, 365.0, 0.0},
        {270.0, 350.0, 0.0},
        {215.0, 370.0, 0.0},
        {200.0, 300.0, 0.0}};
    iDrawCurve(c42[0], c42[1], c42[2], c42[3], 1, (GLfloat[]){.3921, .2823, .1607});

    // Reference: Planta de la pata delantera secundaria
    float c43[4][3] = {
        {200.0, 300.0, 0.0},
        {255.0, 280.0, 0.0},
        {300.0, 318.0, 0.0},
        {345.0, 310.0, 0.0}};
    iDrawCurve(c43[0], c43[1], c43[2], c43[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve

    glFlush();
}

void old_rabbit()
{
    // Cuello
    glColor3f(.6745, .6392, .5215);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(230, 155);
    glVertex2i(240, 190);
    glVertex2i(260, 200);
    glVertex2i(275, 205);

    glVertex2i(325, 205);
    glVertex2i(340, 200);
    glVertex2i(360, 190);
    glVertex2i(370, 155);

    glEnd();

    glColor3f(.7529, .7529, .7529);
    // Pata izquierda
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(200, 50);
    glVertex2i(180, 60);
    glVertex2i(185, 70);
    glVertex2i(205, 80);
    glVertex2i(230, 80);
    glVertex2i(250, 75);
    glVertex2i(270, 60);
    glVertex2i(265, 55);
    glVertex2i(260, 50);
    glEnd();

    // Pierna izquierda
    glColor3f(.5019, .4509, .3882);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(270, 60);
    glVertex2i(250, 75);
    glVertex2i(230, 80);
    glVertex2i(225, 90);
    glVertex2i(200, 100);
    glVertex2i(190, 105);
    glVertex2i(185, 125);
    glVertex2i(185, 140);
    glVertex2i(190, 145);
    glVertex2i(200, 150);
    glVertex2i(220, 155);
    glVertex2i(250, 155);
    glVertex2i(260, 140);
    glEnd();

    // Brazo izquierdo
    glColor3f(.3882, .4039, .3333);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(250, 155);
    glVertex2i(260, 140);
    glVertex2i(270, 60);
    glVertex2i(280, 65);
    glVertex2i(290, 60);
    glVertex2i(290, 160);
    glVertex2i(285, 175);
    glVertex2i(275, 180);
    glVertex2i(260, 180);
    glVertex2i(250, 175);
    glVertex2i(245, 170);
    glEnd();

    // Mano izquierda
    glColor3f(.7333, .74509, .8941);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(260, 50);
    glVertex2i(265, 55);
    glVertex2i(270, 60);
    glVertex2i(280, 65);
    glVertex2i(290, 60);
    glVertex2i(295, 55);
    glVertex2i(298, 50);
    glEnd();

    glColor3f(.7529, .7529, .7529);
    // Pata derecha
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(400, 50);
    glVertex2i(420, 60);
    glVertex2i(415, 70);
    glVertex2i(395, 80);
    glVertex2i(370, 80);
    glVertex2i(350, 75);
    glVertex2i(330, 60);
    glVertex2i(335, 55);
    glVertex2i(340, 50);
    glEnd();

    // Pierna derecha
    glColor3f(.5019, .4509, .3882);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(330, 60);
    glVertex2i(350, 75);
    glVertex2i(370, 80);
    glVertex2i(375, 90);
    glVertex2i(400, 100);
    glVertex2i(410, 105);
    glVertex2i(415, 125);
    glVertex2i(415, 140);
    glVertex2i(410, 145);
    glVertex2i(400, 150);
    glVertex2i(380, 155);
    glVertex2i(350, 155);
    glVertex2i(340, 140);
    glEnd();

    // Brazo derecho
    glColor3f(.3882, .4039, .3333);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(350, 155);
    glVertex2i(340, 140);
    glVertex2i(330, 60);
    glVertex2i(320, 65);
    glVertex2i(310, 60);
    glVertex2i(310, 160);
    glVertex2i(315, 175);
    glVertex2i(325, 180);
    glVertex2i(340, 180);
    glVertex2i(350, 175);
    glVertex2i(355, 170);
    glEnd();

    // Mano izquierda
    glColor3f(.7333, .74509, .8941);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(340, 50);
    glVertex2i(335, 55);
    glVertex2i(330, 60);
    glVertex2i(320, 65);
    glVertex2i(310, 60);
    glVertex2i(305, 55);
    glVertex2i(302, 50);
    glEnd();

    // Vientre
    glColor3f(.7529, .7529, .7529);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);

    // glVertex2i(325, 180);

    glVertex2i(310, 180);
    glVertex2i(315, 175);
    glVertex2i(310, 160);
    glVertex2i(310, 60);
    glVertex2i(305, 55);
    glVertex2i(302, 50);

    glVertex2i(298, 50);
    glVertex2i(295, 55);
    glVertex2i(290, 60);
    glVertex2i(290, 160);
    glVertex2i(285, 175);
    glVertex2i(290, 180);
    glEnd();

    // Cabeza
    glColor3f(.5019, .4509, .3882);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    // glVertex2i(275, 205);
    // glVertex2i(325, 205);
    glVertex2i(260, 205);
    glVertex2i(240, 245);
    glVertex2i(240, 275);
    glVertex2i(255, 290);
    glVertex2i(270, 320);

    glVertex2i(280, 325); // Oreja
    glVertex2i(300, 330);
    glVertex2i(320, 325); // Oreja

    glVertex2i(330, 320);
    glVertex2i(345, 290);
    glVertex2i(360, 275);
    glVertex2i(360, 245);
    glVertex2i(340, 205);
    glEnd();

    // Cubrebocas
    glColor3f(1, 1, 1);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);

    glVertex2i(300, 215);
    glVertex2i(270, 215);
    glVertex2i(255, 245);
    glVertex2i(265, 275);
    glVertex2i(280, 285);
    glVertex2i(300, 290);

    // glVertex2i(320, 285);
    // glVertex2i(335, 275);
    // glVertex2i(345, 245);
    // glVertex2i(330, 215);
    glEnd();

    // Tirantes
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(265, 275);
    glVertex2i(262, 270);
    glVertex2i(240, 270);
    glVertex2i(240, 275);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(265, 225);
    glVertex2i(267, 220);
    glVertex2i(253, 220);
    glVertex2i(249, 225);
    glEnd();

    // Ojos
    glColor3f(1, 1, 1);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(267, 293);
    glVertex2i(270, 290);
    glVertex2i(275, 290);
    glVertex2i(290, 310);
    glVertex2i(287, 313);
    glVertex2i(282, 313);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(281, 298);
    glVertex2i(274, 298);
    glVertex2i(274, 305);
    glVertex2i(281, 305);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(333, 293);
    glVertex2i(330, 290);
    glVertex2i(325, 290);
    glVertex2i(310, 310);
    glVertex2i(313, 313);
    glVertex2i(318, 313);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(319, 298);
    glVertex2i(326, 298);
    glVertex2i(326, 305);
    glVertex2i(319, 305);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(300, 275);
    glVertex2i(310, 269);
    glVertex2i(330, 269);

    glVertex2i(330, 230);
    glVertex2i(300, 230);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(300, 230);
    glVertex2i(320, 230);
    glVertex2i(320, 215);
    glVertex2i(300, 215);
    glEnd();

    glColor3f(.6745, .4078, .5215);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 275);
    glVertex2i(315, 270);
    glVertex2i(300, 255);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 245);
    glVertex2i(320, 245);
    glVertex2i(300, 220);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(300, 247);
    glVertex2i(300, 230);
    glVertex2i(310, 230);
    glVertex2i(310, 247);
    glEnd();

    // Orejas
    glColor3f(0.3882, 0.4039, 0.3333);
    glBegin(GL_POLYGON);
    glVertex2i(280, 325);
    glVertex2i(270, 320);
    glVertex2i(220, 345);
    glVertex2i(205, 360);
    glVertex2i(205, 375);
    glVertex2i(220, 390);
    glVertex2i(240, 390);
    glVertex2i(250, 380);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(320, 325);
    glVertex2i(330, 320);
    glVertex2i(380, 345);
    glVertex2i(395, 360);
    glVertex2i(395, 375);
    glVertex2i(380, 390);
    glVertex2i(360, 390);
    glVertex2i(350, 380);
    glEnd();
}

void skull()
{
    // Cráneo (muerte)
    // glColor3f(.6745, .6392, .5215);
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(190, 600);
    glVertex2i(175, 570);
    glVertex2i(175, 540);
    glVertex2i(190, 510);

    glVertex2i(255, 510);
    glVertex2i(270, 540);

    glVertex2i(270, 570);
    glVertex2i(255, 600);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(190, 510);
    glVertex2i(190, 485);
    glVertex2i(198, 485);
    glVertex2i(198, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(209, 510);
    glVertex2i(209, 485);
    glVertex2i(217, 485);
    glVertex2i(217, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(228, 510);
    glVertex2i(228, 485);
    glVertex2i(236, 485);
    glVertex2i(236, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(247, 510);
    glVertex2i(247, 485);
    glVertex2i(255, 485);
    glVertex2i(255, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(255, 480);
    glVertex2i(250, 465);
    glVertex2i(195, 465);
    glVertex2i(190, 480);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(217, 545);
    glVertex2i(223, 525);
    glVertex2i(229, 545);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(190, 575);
    glVertex2i(190, 545);
    glVertex2i(210, 545);
    glVertex2i(210, 575);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(235, 575);
    glVertex2i(235, 545);
    glVertex2i(255, 545);
    glVertex2i(255, 575);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(265, 565);
    glVertex2i(265, 545);
    glVertex2i(300, 575);
    glVertex2i(300, 595);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(300, 625);
    glVertex2i(300, 575);
    glVertex2i(290, 575);
    glVertex2i(290, 625);
    glEnd();
}

void tree()
{
    // Cráneo (muerte)

    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(190, 600);
    glVertex2i(175, 570);
    glVertex2i(175, 540);
    glVertex2i(190, 510);

    glVertex2i(255, 510);
    glVertex2i(270, 540);

    glVertex2i(270, 570);
    glVertex2i(255, 600);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(190, 510);
    glVertex2i(190, 485);
    glVertex2i(198, 485);
    glVertex2i(198, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(209, 510);
    glVertex2i(209, 485);
    glVertex2i(217, 485);
    glVertex2i(217, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(228, 510);
    glVertex2i(228, 485);
    glVertex2i(236, 485);
    glVertex2i(236, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(247, 510);
    glVertex2i(247, 485);
    glVertex2i(255, 485);
    glVertex2i(255, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(255, 480);
    glVertex2i(250, 465);
    glVertex2i(195, 465);
    glVertex2i(190, 480);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(217, 545);
    glVertex2i(223, 525);
    glVertex2i(229, 545);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(190, 575);
    glVertex2i(190, 545);
    glVertex2i(210, 545);
    glVertex2i(210, 575);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(235, 575);
    glVertex2i(235, 545);
    glVertex2i(255, 545);
    glVertex2i(255, 575);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(265, 565);
    glVertex2i(265, 545);
    glVertex2i(300, 575);
    glVertex2i(300, 595);
    glEnd();

    glColor3f(.4039, .2196, .0980);
    glBegin(GL_POLYGON);
    glVertex2i(300, 625);
    glVertex2i(300, 575);
    glVertex2i(310, 575);
    glVertex2i(310, 625);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(335, 565);
    glVertex2i(335, 545);
    glVertex2i(300, 575);
    glVertex2i(300, 595);
    glEnd();

    drawCircle(380, 535, 40, 0, .1647, .0352);
    drawCircle(380, 565, 40, 0, .1647, .0352);

    drawCircle(335, 555, 20, 0, .1647, .0352);
    drawCircle(345, 525, 20, 0, .1647, .0352);
    drawCircle(375, 495, 20, 0, .1647, .0352);
    drawCircle(400, 485, 20, 0, .1647, .0352);
    drawCircle(410, 540, 20, 0, .1647, .0352);
    drawCircle(410, 510, 20, 0, .1647, .0352);
}

void mount()
{
    glColor3f(.8196, .5098, .9960);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 400);
    glVertex2i(300, 600);
    glVertex2i(450, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(450, 400);
    glVertex2i(600, 600);
    glVertex2i(600, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(300, 400);
    glVertex2i(450, 600);
    glVertex2i(600, 400);
    glEnd();

    glColor3f(.2666, .2746, .3019);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 400);
    glVertex2i(0, 600);
    glVertex2i(150, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(150, 400);
    glVertex2i(300, 600);
    glVertex2i(300, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 400);
    glVertex2i(150, 600);
    glVertex2i(300, 400);
    glEnd();
}

void bote()
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2i(350, 450);
    glVertex2i(550, 450);
    glVertex2i(525, 330);
    glVertex2i(375, 330);
    glEnd();

    // Bambú (recipiente reciclado de bambú)
    glColor3f(.6509, .8901, .1294);
    glBegin(GL_POLYGON);
    glVertex2i(440, 430);
    glVertex2i(460, 430);
    glVertex2i(460, 350);
    glVertex2i(440, 350);
    glEnd();

    glColor3f(0, .5176, .0627);
    glBegin(GL_POLYGON);
    glVertex2i(430, 430);
    glVertex2i(470, 430);
    glVertex2i(470, 420);
    glVertex2i(430, 420);
    glEnd();

    glColor3f(0, .5176, .0627);
    glBegin(GL_POLYGON);
    glVertex2i(435, 390);
    glVertex2i(465, 390);
    glVertex2i(465, 380);
    glVertex2i(435, 380);
    glEnd();

    glColor3f(0, .5176, .0627);
    glBegin(GL_POLYGON);
    glVertex2i(435, 350);
    glVertex2i(465, 350);
    glVertex2i(465, 340);
    glVertex2i(435, 340);
    glEnd();
}

void plato_bambu(void)
{
    float points[4][3] = {
        {300.0, 250.0, 0.0},
        {350.0, 140.0, 0.0},
        {430.0, 140.0, 0.0},
        {480.0, 250.0, 0.0}};
    iDrawCurve(points[0], points[1], points[2], points[3], 1, (GLfloat[]){.3921, .2823, .1607}); // Display curve
}

void bottle()
{
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 470);
    glVertex2i(160, 470);
    glVertex2i(160, 460);
    glVertex2i(140, 460);
    glEnd();

    glColor3f(.4, .7568, .7764);
    glBegin(GL_POLYGON);
    glVertex2i(140, 460);
    glVertex2i(130, 440);
    glVertex2i(130, 390);
    glVertex2i(135, 380);

    glVertex2i(165, 380);
    glVertex2i(170, 390);
    glVertex2i(170, 440);
    glVertex2i(160, 460);

    glEnd();
}

void scene()
{

    // Césped
    glColor3f(.0627, .4862, .2549);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(300, 0);
    glVertex2i(600, 0);
    glVertex2i(600, 400);
    glVertex2i(300, 400);
    glEnd();

    // Tierra
    glColor3f(.8156, .6, .3490);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(300, 0);
    glVertex2i(300, 400);
    glVertex2i(0, 400);
    glEnd();

    mount();

    // bote();

    // rabbit();
    //  Raya
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(302, 0);
    glVertex2i(302, 800);
    glVertex2i(298, 800);
    glVertex2i(298, 0);
    glEnd();

    skull();

    tree();

    bottle();

    drawCircle(600, 800, 100, 1, .6588, .0313);

    // Cigarro
    glColor3f(1.0, 0.65, 0.0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(50, 400);
    glVertex2i(100, 400);
    glVertex2i(100, 410);
    glVertex2i(50, 410);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(100, 400);
    glVertex2i(110, 400);
    glVertex2i(110, 410);
    glVertex2i(100, 410);
    glEnd();
}

void smoke()
{
    float smoke_points1[4][3] = {
        {105.0, 400.0, 0.0},
        {80.0, 433.0, 0.0},
        {80.0, 460.0, 0.0},
        {105.0, 500.0, 0.0}};
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &smoke_points1[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glColor3f(0, 0, 0); // Experimental
    glLineWidth(10);    // Experimental
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 100; i++)
    {
        glEvalCoord1f((GLfloat)i / 100.0);
    }
    glEnd();

    float smoke_points2[4][3] = {
        {105.0, 500.0, 0.0},
        {120.0, 533.0, 0.0},
        {120.0, 560.0, 0.0},
        {105.0, 600.0, 0.0}};
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &smoke_points2[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glColor3f(0, 0, 0); // Experimental
    glLineWidth(10);    // Experimental
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 100; i++)
    {
        glEvalCoord1f((GLfloat)i / 100.0);
    }
    glEnd();
}
void pinta(void)
{

    int frame = 0, offset_x = 450, offset_y = 0;

    while (frame < 30)
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia la pantalla
        scene();
        if (frame < 5)
        {
            if (frame % 2)
            {
                glPushMatrix();
                glTranslated(0, 50, 0);
                smoke();
                glTranslated(500, 400, 0);
                glScaled(.5, .5, 0);
                bote();
                plato_bambu();
                glPopMatrix();
            }
            else
            {
                glPushMatrix();
                glScaled(1, 1, 0);
                bote();
                smoke();
                plato_bambu();
                glPopMatrix();
            }

            glPushMatrix();
            glScaled(.35, .35, 0);
            glTranslated(offset_x - 40, 0, 0);
            sitting_rabbit();
            glPopMatrix();

            usleep(100000);
        }
        else if (frame < 10)
        {
            bote();
            plato_bambu();

            glPushMatrix();
            glScaled(.35, .35, 0);
            glTranslated(offset_x - 40, offset_y + 50, 0);
            jumping_rabbit();
            glPopMatrix();

            usleep(100000);
        }
        else if (frame < 15)
        {
            bote();
            plato_bambu();

            glPushMatrix();
            glScaled(.35, .35, 0);
            glTranslated(offset_x - 40, offset_y - 50, 0);
            jumping_rabbit();
            glPopMatrix();

            usleep(100000);
        }
        else
        {
            bote();
            plato_bambu();

            glPushMatrix();
            glScaled(.35, .35, 0);
            glTranslated(offset_x - 40, offset_y, 0);
            sitting_rabbit();
            glPopMatrix();

            usleep(100000);
        }

        (frame == 30) ? frame = 0 : frame++;
        glFlush();
        usleep(200000);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 800);
    glutCreateWindow("Castelán Carpinteyro Dante - ProyectoFinal.c");
    glutInitWindowPosition(500, 500);
    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();
    return 0;
}
