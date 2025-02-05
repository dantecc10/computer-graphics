#include <GL/glut.h>
#include <math.h>
void inicializa(void)
{
    glClearColor(1, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1600, 0, 1000);
}

void drawTriangle(int vertices[3][2], float color[3]){
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(color[0], color[1], color[2]);
    glVertex2i(vertices[0][0], vertices[0][1]);
    glVertex2i(vertices[1][0], vertices[1][1]);
    glVertex2i(vertices[2][0], vertices[2][1]);
    glEnd();
}

void drawPine(int a, int b, int x)
{
    glEnd();
    glBegin(GL_TRIANGLES); // Simple, filled triangles
    glColor3f(.06, .8, .5);
    glVertex2i(a, b);
    glVertex2i(a + x, b - 2 * x);
    glVertex2i(a - x, b - 2 * x);

    glVertex2i(a, b - x);
    glVertex2i(a - 1.5 * x, b - 4 * x);
    glVertex2i(a + 1.5 * x, b - 4 * x);

    glVertex2i(a, b - 2.5 * x);
    glVertex2i(a - 2 * x, b - 6 * x);
    glVertex2i(a + 2 * x, b - 6 * x);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); // Every point
    glColor3f(.34, .13, .05);

    glVertex2i(a - .5 * x, b - 6 * x);
    glVertex2i(a + .5 * x, b - 6 * x);
    glVertex2i(a + .5 * x, b - 8 * x);
    glVertex2i(a - .5 * x, b - 8 * x);
    glEnd();
}

void drawCloud(int a, int b, int x)
{
    glEnd();
    glBegin(GL_TRIANGLES); // Simple, filled triangles
    glColor3f(1, 1, 1); // White
    glVertex2i(a, b);
    glVertex2i(a + 2 * x, b + 2 * x);
    glVertex2i(a + 4 * x, b);

    glColor3f(.74, .88, .96); // First cloud gray
    glVertex2i(a + 2 * x, b + 2 * x);
    glVertex2i(a + 4 * x, b);
    glVertex2i(a + 6 * x, b + 2 * x);

    glColor3f(.6, .87, .92); // Second cloud gray
    glVertex2i(a + 4 * x, b);
    glVertex2i(a + 6 * x, b + 2 * x);
    glVertex2i(a + 8 * x, b);

    glColor3f(.15, .16, .2); // Third cloud gray
    glVertex2i(a + 8 * x, b);
    glVertex2i(a + 6 * x, b + 2 * x);
    glVertex2i(a + 8.5 * x, b + 3 * x);

    glColor3f(.58, .73, .81); // Fourth cloud gray
    glVertex2i(a + 7 * x, b + 4.5 * x);
    glVertex2i(a + 6 * x, b + 2 * x);
    glVertex2i(a + 8.5 * x, b + 3 * x);

    glColor3f(.6, .87, .92); // Second cloud gray
    glVertex2i(a + 7 * x, b + 4.5 * x);
    glVertex2i(a + 6 * x, b + 2 * x);
    glVertex2i(a + 4 * x, b + 4 * x);

    glColor3f(1, 1, 1); // White
    glVertex2i(a + 2 * x, b + 2 * x);
    glVertex2i(a + 6 * x, b + 2 * x);
    glVertex2i(a + 4 * x, b + 4 * x);

    glVertex2i(a + 8.5 * x, b + 3 * x);
    glVertex2i(a + 8 * x, b);
    glVertex2i(a + 12 * x, b);

    glColor3f(.6, .87, .92); // Second cloud gray
    glVertex2i(a + 14 * x, b + 3 * x);
    glVertex2i(a + 12 * x, b);
    glVertex2i(a + 16 * x, b);

    glColor3f(.58, .73, .81); // Fourth cloud gray
    glVertex2i(a + 14 * x, b + 3 * x);
    glVertex2i(a + 12 * x, b);
    glVertex2i(a + 8.5 * x, b + 3 * x);

    glColor3f(.15, .16, .2); // Third cloud gray
    glVertex2i(a + 8.5 * x, b + 3 * x);
    glVertex2i(a + 14 * x, b + 3 * x);
    glVertex2i(a + 7 * x, b + 4.5 * x);

    glColor3f(1, 1, 1); // White
    glVertex2i(a + 11.5 * x, b + 4.5 * x);
    glVertex2i(a + 14 * x, b + 3 * x);
    glVertex2i(a + 7 * x, b + 4.5 * x);

    glEnd();
}

void drawMountain(int a, int b, int x)
{
    glEnd();
    glBegin(GL_TRIANGLES); // Simple, filled triangles
    glColor3f(.72, .67, .87); // Lil' gray
    glVertex2i(a, b);
    glVertex2i(a + 4 * x, b);
    glVertex2i(a + 2 * x, b + sqrt(pow(4 * x, 2) - pow(2, 2)));
    
    glEnd();
    glBegin(GL_TRIANGLE_STRIP); // Every point
    glColor3f(1, 1, 1); // Lil' gray
    glVertex2i(a + 2 * x, b + sqrt(pow(4 * x, 2) - pow(2, 2)));
    glVertex2i(a + 1.25 * x, b + sqrt(pow(2.5 * x, 2) - pow(1.5, 2)));
    glVertex2i(a + 2.75 * x, b + sqrt(pow(2.5 * x, 2) - pow(1.5, 2)));

    glVertex2i(a + 1.5 * x, b + sqrt(pow(4 * x, 2) - pow(2, 2)) - 1.75 * x);
    glVertex2i(a + 1.67 * x, b + sqrt(pow(4 * x, 2) - pow(2, 2)) - 1.67 * x);
    glVertex2i(a + 2 * x, b + sqrt(pow(4 * x, 2) - pow(2, 2)) - 1.67 * x);

    glVertex2i(a + 2.37 * x, b + sqrt(pow(4 * x, 2) - pow(2, 2)) - 1.75 * x);
    glVertex2i(a + 2.5 * x, b + sqrt(pow(4 * x, 2) - pow(2, 2)) - 1.67 * x);


    glEnd();
}

void drawField(int a, int b, int x){
    glEnd();
    glBegin(GL_TRIANGLES);
    int vertices[3][2] = {{0, 0}, {0, 0}, {0, 0}};
    int a_p[2] = {a, b},
    b_p[2] = {a + x, b},
    c_p[2] = {a + 2 * x, b},
    d_p[2] = {a + 3 * x, b},
    e_p[2] = {a + 4 * x, b},
    f_p[2] = {a + 5 * x, b},
    g_p[2] = {a + 6 * x, b},
    h_p[2] = {a + 7 * x, b},
    i_p[2] = {a + .5 * x, b + x},
    j_p[2] = {a + 1.5 * x, b + x},
    k_p[2] = {a + 2.5 * x, b + x},
    l_p[2] = {a + 3.5 * x, b + x},
    m_p[2] = {a + 4.5 * x, b + .5 * x},
    n_p[2] = {a + 5.5 * x, b + .75 * x},
    o_p[2] = {a + 6.5 * x, b + x},
    p_p[2] = {a + x, b + 2 * x},
    q_p[2] = {a + 2.5 * x, b + 2.2 * x},
    r_p[2] = {a + 3.5 * x, b + 2 * x},
    s_p[2] = {a + 5 * x, b + 1.75 * x},
    t_p[2] = {a + 6.5 * x, b + 2 * x};

    float color[3] = {0, 0, 0};
    // Triangle A, B, I
    color = {0.035, 0.474, 0.0039};
    vertices = {{a_p[0], a_p[1]}, {b_p[0], b_p[1]}, {i_p[0], i_p[1]}};
    drawTriangle(vertices, color);
    glEnd();
}

void pinta(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawPine(500, 500, 40);
    drawCloud(800, 700, 30);
    drawMountain(1000, 200, 60);
    drawField(0, 0, 100);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInitWindowSize(660, 400);
    glutInitWindowPosition(1280, 10);
    glutInit(&argc, argv);
    glutCreateWindow("Mi primer programa");

    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();
    return 0;
}