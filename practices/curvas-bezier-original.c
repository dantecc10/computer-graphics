#include <GL/glut.h>

void init(void)
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 550, 0, 550);
}

void CurvaBezier(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    float PuntosDeControl[4][3] = {
        {10.0, 10.0, 0.0},
        {200.0, 200.0, 0.0},
        {200.0, 100.0, 0.0},
        {100.0, 100.0, 100.0}};

    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, *PuntosDeControl);
    glEnable(GL_MAP1_VERTEX_3);
    glMapGrid1f(100, 0.0, 1.0);
    glColor3f(1.0, 0, 0);
    glLineWidth(4);
    glEvalMesh1(GL_LINE, 0, 100);
    glDisable(GL_MAP1_VERTEX_3);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Curva de Bezier");
    init();
    glutDisplayFunc(CurvaBezier);
    glutMainLoop();
    return 0;
}