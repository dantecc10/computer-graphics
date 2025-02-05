#include <GL/glut.h>
void inicializa(void)
{
    glClearColor(0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 800);
}

void pinta(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Top
    glBegin(GL_TRIANGLES); // Genera triángulos
    glColor3f(1, 0, 0);
    glVertex2i(400, 750);
    glVertex2i(200, 550);
    glVertex2i(600, 550);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); // Square
    glColor3f(1, 1, 1);
    glVertex2i(215, 135);
    glVertex2i(585, 135);
    glVertex2i(585, 550);
    glVertex2i(215, 550);
    glEnd();

    glBegin(GL_LINE_LOOP); // Big door
    glColor3f(0, 0, 0);
    glVertex2i(338, 260);
    glVertex2i(462, 260);
    glVertex2i(462, 135);
    glVertex2i(338, 135);
    glEnd();

    glBegin(GL_LINE_LOOP); // Small door
    glColor3f(0, 0, 0);
    glVertex2i(375, 195);
    glVertex2i(425, 195);
    glVertex2i(425, 135);
    glVertex2i(375, 135);
    glEnd();

    glBegin(GL_POINTS); // Picaporte
    glColor3f(0, 0, 0);

    glVertex2i(400, 165);
    glEnd();

    glBegin(GL_LINE_LOOP); // Window 1
    glColor3f(0, 0, 0);
    glVertex2i(255, 510);
    glVertex2i(380, 510);
    glVertex2i(380, 385);
    glVertex2i(255, 385);
    glEnd();

    glBegin(GL_LINE_LOOP); // Window 2
    glColor3f(0, 0, 0);
    glVertex2i(420, 510);
    glVertex2i(545, 510);
    glVertex2i(545, 385);
    glVertex2i(420, 385);
    glEnd();

    glBegin(GL_TRIANGLES); // Genera triángulos
    // Tree top 1
    glColor3f(0, 1, 0);
    glVertex2i(670, 415);
    glVertex2i(600, 195);
    glVertex2i(740, 195);

    // Tree top 2
    glVertex2i(130, 415);
    glVertex2i(200, 195);
    glVertex2i(60, 195);

    // Tree base 1
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(.46, .35, .2);
    glVertex2i(110, 195);
    glVertex2i(150, 195);
    glVertex2i(150, 135);
    glVertex2i(110, 135);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2i(110, 195);
    glVertex2i(150, 135);
    glVertex2i(110, 135);
    glEnd();

    // Tree base 2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(650, 195);
    glVertex2i(690, 195);
    glVertex2i(690, 135);
    glVertex2i(650, 135);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glLineWidth(10);
    glVertex2i(300, 490);
    glVertex2i(370, 415);
    
    glVertex2i(270, 470);
    glVertex2i(320, 415);

    glVertex2i(520, 470);
    glVertex2i(470, 415);
    
    glVertex2i(500, 470);
    glVertex2i(450, 415);
    glLineWidth(1);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInitWindowSize(800, 800);
    glutInit(&argc, argv);
    glutCreateWindow("Mi primer programa");

    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();
    return 0;
}
