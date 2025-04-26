#include <GL/glut.h>

void init(void)
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 800);
}

void drawFilledCurve(float p0[3], float p1[3], float p2[3], float p3[3])
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

void drawFilledRabbit(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Color del conejo (gris claro)
    glColor3f(0.8, 0.8, 0.8);

    // Dibujar el cuerpo relleno
    glBegin(GL_POLYGON);
    // Puntos del contorno del conejo (simplificado para el ejemplo)
    // Deberías incluir todos los puntos importantes de tu conejo aquí
    glVertex2f(400.0, 600.0); // Parte superior
    glVertex2f(745.0, 420.0); // Lomo
    glVertex2f(670.0, 145.0); // Cola
    glVertex2f(480.0, 125.0); // Pata trasera
    glVertex2f(310.0, 155.0); // Vientre
    glVertex2f(150.0, 390.0); // Pecho
    glVertex2f(75.0, 450.0);  // Cabeza
    glVertex2f(90.0, 480.0);  // Nariz
    glVertex2f(350.0, 440.0); // Mandíbula
    glEnd();

    // Dibujar las orejas (ejemplo)
    glColor3f(0.7, 0.7, 0.7); // Gris un poco más oscuro
    glBegin(GL_POLYGON);
    glVertex2f(350.0, 600.0);
    glVertex2f(300.0, 750.0);
    glVertex2f(250.0, 700.0);
    glVertex2f(320.0, 580.0);
    glEnd();

    // Dibujar el contorno en negro
    glColor3f(0, 0, 0);
    glLineWidth(2);

    // Aquí irían todas tus curvas de Bézier originales para el contorno
    // ... (todo el código de las curvas que ya tienes)

    // Ojos (ejemplo)
    glColor3f(0, 0, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(150.0, 500.0);
    glVertex2f(200.0, 500.0);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(1600, 0);
    glutCreateWindow("Conejo Relleno");
    init();
    glutDisplayFunc(drawFilledRabbit);
    glutMainLoop();
    return 0;
}