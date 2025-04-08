#include <GL/glut.h> //archivo cabecera opengl, glu, glut
#include <unistd.h>
// rutina de inicializacion
void inicializa(void)
{
    glClearColor(1.0, 1.0, 1.0, 1); // Color de fondo RGBA(A no interesa por ahora)
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 15, 0, 0, 0, 0, 1, 5);
    glMatrixMode(GL_PROJECTION); // Para el tipo de matriz a usar: Proyeccion
    gluPerspective(20, 1, 1, 20);
}
void Cubos(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glutInitDisplayMode(GL_DEPTH);
    glScalef(.4, .5, 1);
    glutSolidSphere(.4, 30, 30);
    glColor3f(0, 1, 0);
    glFlush();

    for (int i = 0; i < 30; i++)
    {
        glEnable(GL_DEPTH_TEST);
        glClear(GL_DEPTH_BUFFER_BIT);
        glTranslated(0, -.1, 0);
        glutSolidSphere(.4, 30, 30);
        glFlush();
        glClear(GL_DEPTH_BUFFER_BIT);
        usleep(50000);
    }
    glDisable(GL_DEPTH_TEST);
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