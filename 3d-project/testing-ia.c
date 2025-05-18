#include <GL/glut.h>

// Parámetros generales
float cuerpoZ = -5.0;

// Inicialización
void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.95f, 0.85f, 0.7f, 1.0f); // Fondo beige
}

// Función para dibujar el teporingo
void drawTeporingo()
{
    // ----- Cuerpo (esfera grande)
    glPushMatrix();
    glTranslatef(0.0, 0.0, cuerpoZ);
    glColor3f(0.6f, 0.3f, 0.1f); // Marrón
    glutSolidSphere(0.8, 30, 30);
    glPopMatrix();

    // ----- Cabeza (esfera mediana)
    glPushMatrix();
    glTranslatef(0.0, 0.9, cuerpoZ);
    glColor3f(0.85f, 0.6f, 0.2f); // Beige marrón claro
    glutSolidSphere(0.5, 30, 30);
    glPopMatrix();

    // ----- Hocico (cubo)
    glPushMatrix();
    glTranslatef(0.0, 0.9, cuerpoZ + 0.45);
    glColor3f(0.5f, 0.2f, 0.0f);
    glutSolidCube(0.2);
    glPopMatrix();

    // ----- Ojos (esferas negras)
    glPushMatrix();
    glTranslatef(0.2, 1.0, cuerpoZ + 0.4);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2, 1.0, cuerpoZ + 0.4);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();

    // ----- Orejas (conos)
    glPushMatrix();
    glTranslatef(0.2, 1.4, cuerpoZ);
    glRotatef(-90, 1, 0, 0);
    glColor3f(0.5f, 0.25f, 0.0f);
    glutSolidCone(0.1, 0.6, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2, 1.4, cuerpoZ);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.1, 0.6, 10, 10);
    glPopMatrix();

    // ----- Patas (cubos)
    float pataX[] = {-0.3, 0.3, -0.3, 0.3};
    float pataY[] = {-0.6, -0.6, 0.1, 0.1};
    for (int i = 0; i < 4; i++)
    {
        glPushMatrix();
        glTranslatef(pataX[i], pataY[i], cuerpoZ);
        glColor3f(0.35f, 0.2f, 0.1f);
        glutSolidCube(0.2);
        glPopMatrix();
    }

    // ----- Cola (cubo pequeño)
    glPushMatrix();
    glTranslatef(0.0, -0.1, cuerpoZ - 0.7);
    glColor3f(0.25f, 0.15f, 0.1f);
    glutSolidCube(0.2);
    glPopMatrix();
}

// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    drawTeporingo();
    glutSwapBuffers();
}

// Redimensionamiento de ventana
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Main
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Teporingo con figuras geométricas");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
