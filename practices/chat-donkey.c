#include <GL/glut.h>

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

// Dibuja el burro usando varias curvas
void dibujarBurro(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glLineWidth(3);

    // **Cabeza**
    float cabeza1[4][3] = {
        {150.0, 300.0, 0.0},
        {130.0, 340.0, 0.0},
        {100.0, 330.0, 0.0},
        {80.0, 300.0, 0.0}
    };
    dibujarCurva(cabeza1[0], cabeza1[1], cabeza1[2], cabeza1[3]);

    // **Oreja izquierda**
    float orejaIzq[4][3] = {
        {80.0, 300.0, 0.0},
        {60.0, 350.0, 0.0},
        {70.0, 400.0, 0.0},
        {90.0, 320.0, 0.0}
    };
    dibujarCurva(orejaIzq[0], orejaIzq[1], orejaIzq[2], orejaIzq[3]);

    // **Oreja derecha**
    float orejaDer[4][3] = {
        {150.0, 300.0, 0.0},
        {170.0, 350.0, 0.0},
        {160.0, 400.0, 0.0},
        {140.0, 320.0, 0.0}
    };
    dibujarCurva(orejaDer[0], orejaDer[1], orejaDer[2], orejaDer[3]);

    // **Cuerpo**
    float cuerpo1[4][3] = {
        {80.0, 300.0, 0.0},
        {50.0, 200.0, 0.0},
        {200.0, 150.0, 0.0},
        {300.0, 200.0, 0.0}
    };
    dibujarCurva(cuerpo1[0], cuerpo1[1], cuerpo1[2], cuerpo1[3]);

    float cuerpo2[4][3] = {
        {300.0, 200.0, 0.0},
        {350.0, 250.0, 0.0},
        {320.0, 300.0, 0.0},
        {250.0, 300.0, 0.0}
    };
    dibujarCurva(cuerpo2[0], cuerpo2[1], cuerpo2[2], cuerpo2[3]);

    // **Patas (simplificadas)**
    float pata1[4][3] = {
        {100.0, 200.0, 0.0},
        {90.0, 100.0, 0.0},
        {110.0, 50.0, 0.0},
        {100.0, 0.0, 0.0}
    };
    dibujarCurva(pata1[0], pata1[1], pata1[2], pata1[3]);

    float pata2[4][3] = {
        {250.0, 200.0, 0.0},
        {240.0, 100.0, 0.0},
        {260.0, 50.0, 0.0},
        {250.0, 0.0, 0.0}
    };
    dibujarCurva(pata2[0], pata2[1], pata2[2], pata2[3]);

    // **Cola**
    float cola[4][3] = {
        {300.0, 200.0, 0.0},
        {350.0, 220.0, 0.0},
        {370.0, 180.0, 0.0},
        {340.0, 150.0, 0.0}
    };
    dibujarCurva(cola[0], cola[1], cola[2], cola[3]);

    glFlush();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Burro con curvas de Bezier");
    init();
    glutDisplayFunc(dibujarBurro);
    glutMainLoop();
    return 0;
}
