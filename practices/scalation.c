#include <GL/glut.h>

void inicializa(void) {
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-600.0, 600.0, -600.0, 600.0);
}

void Triangulo(void) {
    glBegin(GL_TRIANGLES);
        glVertex2i(270, 270);
        glVertex2i(330, 270);
        glVertex2i(300, 330);
    glEnd();
    glFlush();
}

void Pinta(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    Triangulo();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(1, -0.5, 0);
    Triangulo();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformaciones geometricas en OpenGL");
    inicializa();
    glutDisplayFunc(Pinta);
    glutMainLoop();
    return 0;
}