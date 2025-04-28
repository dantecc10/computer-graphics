#include <GL/glut.h>

GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat z = 0.0;
GLubyte label[] = {'H', 'O', 'L', 'A'};

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set background color to white
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 5);
    glMatrixMode(GL_PROJECTION);          // Set projection matrix
    gluPerspective(45.0, 1.0, 1.0, 12.0); // Set perspective projection
}

void Trans2D(void)
{
    GLint k;
    glColor3f(0.0, 0.0, 0.0);
    for (k = 0; k < 4; k++)
    {
        glRasterPos3f(x, y, z);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, label[k]);
        x += 0.1;
    }
}

void Pinta3D(void)
{
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(1.0);
}

void Todo(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Pinta3D();
    Trans2D();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Programa Básico en 3D");
    init();
    glutDisplayFunc(Todo);
    glutMainLoop();
    return 0;
}