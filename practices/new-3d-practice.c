#include <GL/glut.h> //archivo cabecera opengl, glu, glut
#include <unistd.h>
// rutina de inicializacion
void inicializa(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Color de fondo RGBA(A no interesa por ahora)
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 15, 0, 0, 0, 0, 1, 5);
    glMatrixMode(GL_PROJECTION); // Para el tipo de matriz a usar: Proyeccion
    gluPerspective(20, 1, 1, 20);
}
void Cubos(void)
{
    glMatrixMode(GL_MODELVIEW);
    glutInitDisplayMode(GL_DEPTH);
    for (int i = 0; i <= 360; i++)
    {
        glRotated(1, 1, 0, 0);
        glClear(GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 0, 0);
        glutSolidSphere(1.0, 20, 20);
        glColor3f(0.8, 0.8, 0);
        glutWireSphere(1.0, 20, 20);
        glColor3f(0, 0, 1);
        glutSolidTorus(1, 2, 40, 40);
        glFlush();
        glDisable(GL_DEPTH_TEST);
        usleep(29000);
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);              // Tamaño de la ventana de visualización
    glutCreateWindow("Programa basico en 3D"); // Crea la ventana de visualización
    inicializa();
    glutDisplayFunc(Cubos); // PINTA LO QUE ORDENE PINTA
    glutMainLoop();         // Espera ordenes
    return 0;
}