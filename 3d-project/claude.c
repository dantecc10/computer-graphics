#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
static float anguloPiernaIzq = 0.0f;
static float anguloPiernaDer = 0.0f;
static float anguloBrazoIzq = 0.0f;
static float anguloBrazoDer = 0.0f;

static float posicionX = 0.0f;
static int direccionMovimiento = 1;
static int direccion = 1;

// Variables para el cigarro y la muerte
static int contadorVueltas = 0;
static int conejoMuerto = 0;
static float anguloCaida = 0.0f;
static float humo = 0.0f;

void inicializa(void)
{
    glClearColor(0.95, 0.45, 0.95, 0.0); // Fondo blanco/grisáceo claro
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // Cámara
    glMatrixMode(GL_PROJECTION);
    gluPerspective(35, 1, 1, 20);
}

// Cuerpo principal del conejo
void cuerpo(void)
{
    // Color rosa claro como en la imagen
    glColor3f(1.0, 0.75, 0.75);
    glPushMatrix();
    glScalef(0.8, 0.9, 0.7); // Cuerpo más redondo
    glutSolidSphere(0.6, 40, 30);
    glPopMatrix();
}

// Cabeza del conejo - más simple y redonda
void cabeza(void)
{
    // Mismo color rosa que el cuerpo
    glColor3f(1.0, 0.75, 0.75);
    glPushMatrix();
    glTranslatef(0, 0.7, 0);
    glScalef(0.9, 0.8, 0.75);
    glutSolidSphere(0.5, 40, 30);
    glPopMatrix();
}

// Orejas largas y rectas como en la imagen
void orejas(void)
{
    // Mismo color rosa
    glColor3f(1.0, 0.75, 0.75);

    // Oreja izquierda - más larga y recta
    glPushMatrix();
    glTranslatef(-0.2, 1.2, 0);
    glRotatef(-5, 0, 0, 1); // Ligeramente inclinada hacia afuera
    glScalef(0.15, 0.7, 0.1);
    glutSolidSphere(0.5, 30, 20);
    glPopMatrix();

    // Oreja derecha - más larga y recta
    glPushMatrix();
    glTranslatef(0.2, 1.2, 0);
    glRotatef(5, 0, 0, 1); // Ligeramente inclinada hacia afuera
    glScalef(0.15, 0.7, 0.1);
    glutSolidSphere(0.5, 30, 20);
    glPopMatrix();
}

// Función para dibujar el cigarrillo - versión mejorada
void cigarrillo(void)
{
    // Cuerpo del cigarrillo (blanco)
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glTranslatef(0.1, 0.58, 0.5); // Más cerca de la boca
    glRotatef(30, 0, 0, 1);       // Menos inclinado para que se vea mejor
    glScalef(0.08, 0.3, 0.08);    // Más grueso
    glutSolidCube(0.5);           // Usamos un cubo alargado en lugar de cilindro
    glPopMatrix();

    // Filtro del cigarrillo (naranja)
    glColor3f(0.9, 0.6, 0.3); // Color naranja
    glPushMatrix();
    glTranslatef(0.16, 0.68, 0.5); // Ajustado para la nueva posición
    glRotatef(30, 0, 0, 1);
    glScalef(0.08, 0.06, 0.08); // Más grueso
    glutSolidCube(0.5);         // Usamos un cubo pequeño
    glPopMatrix();

    // Punta encendida (rojo/naranja)
    glColor3f(1.0, 0.4, 0.0); // Naranja/rojo
    glPushMatrix();
    glTranslatef(0.04, 0.48, 0.5); // Ajustado para la nueva posición
    glRotatef(30, 0, 0, 1);
    glScalef(0.08, 0.03, 0.08); // Más grueso
    glutSolidSphere(0.6, 20, 20);
    glPopMatrix();

    // Dibujar humo animado
    if (!conejoMuerto)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        for (int i = 0; i < 3; i++)
        {
            float yOffset = i * 0.15;
            float xOffset = sin((humo + i) * 0.5) * 0.05;
            float tam = 0.03 + (i * 0.02); // Humo también más visible
            float alpha = 0.9 - (i * 0.2); // Más opaco al inicio

            glColor4f(0.8, 0.8, 0.8, alpha);
            glPushMatrix();
            glTranslatef(0.04 + xOffset, 0.48 + yOffset, 0.5);
            glScalef(tam, tam, tam);
            glutSolidSphere(1.0, 10, 10);
            glPopMatrix();
        }

        glDisable(GL_BLEND);
    }
}

// Ojos simplificados como en la imagen (puntos negros)
void ojos(void)
{
    if (!conejoMuerto)
    {
        // Ojo izquierdo
        glColor3f(0.0, 0.0, 0.0); // Negro
        glPushMatrix();
        glTranslatef(-0.15, 0.75, 0.42);
        glutSolidSphere(0.03, 20, 15);
        glPopMatrix();

        // Ojo derecho
        glPushMatrix();
        glTranslatef(0.15, 0.75, 0.42);
        glutSolidSphere(0.03, 20, 15);
        glPopMatrix();
    }
    else
    {
        // Ojos X cuando está muerto
        glColor3f(0.0, 0.0, 0.0); // Negro
        glLineWidth(3.0);

        // Ojo izquierdo en X
        glBegin(GL_LINES);
        // Primera línea diagonal
        glVertex3f(-0.2, 0.8, 0.42);
        glVertex3f(-0.1, 0.7, 0.42);
        // Segunda línea diagonal
        glVertex3f(-0.2, 0.7, 0.42);
        glVertex3f(-0.1, 0.8, 0.42);
        glEnd();

        // Ojo derecho en X
        glBegin(GL_LINES);
        // Primera línea diagonal
        glVertex3f(0.1, 0.8, 0.42);
        glVertex3f(0.2, 0.7, 0.42);
        // Segunda línea diagonal
        glVertex3f(0.1, 0.7, 0.42);
        glVertex3f(0.2, 0.8, 0.42);
        glEnd();
    }
}

// Nariz y boca minimalistas (una X pequeña)
void boca(void)
{
    // Líneas para formar una X
    glColor3f(0.0, 0.0, 0.0); // Negro
    glLineWidth(2.0);

    glBegin(GL_LINES);
    // Primera línea diagonal
    glVertex3f(-0.05, 0.6, 0.45);
    glVertex3f(0.05, 0.54, 0.45);

    // Segunda línea diagonal
    glVertex3f(-0.05, 0.54, 0.45);
    glVertex3f(0.05, 0.6, 0.45);
    glEnd();
}

// Brazos pequeños y redondos
void brazos(float anguloBrazoIzq, float anguloBrazoDer)
{
    // Mismo color rosa
    glColor3f(1.0, 0.75, 0.75);

    // Brazo izquierdo
    glPushMatrix();
    glTranslatef(-0.6, 0.0, 0);
    glRotatef(90, 0, 0, 1);
    glRotatef(anguloBrazoIzq, 1, 0, 0); // Animación
    glScalef(0.25, 0.4, 0.25);
    glutSolidSphere(0.5, 30, 20);
    glPopMatrix();

    // Brazo derecho
    glPushMatrix();
    glTranslatef(0.6, 0.0, 0);
    glRotatef(-90, 0, 0, 1);
    glRotatef(anguloBrazoDer, 1, 0, 0); // Animación
    glScalef(0.25, 0.4, 0.25);
    glutSolidSphere(0.5, 30, 20);
    glPopMatrix();
}

// Piernas cortas y redondas, con rotación animada para simular caminar
void piernas(float anguloPiernaIzq, float anguloPiernaDer)
{
    // Mismo color rosa
    glColor3f(1.0, 0.75, 0.75);

    // Pierna izquierda
    glPushMatrix();
    glTranslatef(-0.3, -0.6, 0);
    glRotatef(anguloPiernaIzq, 1, 0, 0); // Rotación sobre el eje X
    glScalef(0.25, 0.4, 0.25);
    glutSolidSphere(0.5, 30, 20);
    glPopMatrix();

    // Pierna derecha
    glPushMatrix();
    glTranslatef(0.3, -0.6, 0);
    glRotatef(anguloPiernaDer, 1, 0, 0); // Rotación sobre el eje X
    glScalef(0.25, 0.4, 0.25);
    glutSolidSphere(0.5, 30, 20);
    glPopMatrix();
}

void ilumina(void)
{
    GLfloat positionAndType[] = {6, 6, 6, 1};
    GLfloat environmentColor[] = {0.4, 0.4, 0.4, 1.0}; // Luz ambiental mejorada
    GLfloat difuseColor[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specularColor[] = {0.5, 0.5, 0.5, 1.0}; // Brillo reducido

    glLightfv(GL_LIGHT0, GL_POSITION, positionAndType);
    glLightfv(GL_LIGHT0, GL_AMBIENT, environmentColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difuseColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularColor);

    // Atenuación suave
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.01);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    // Configurar material para simular el aspecto de peluche
    GLfloat mat_ambient[] = {0.8, 0.6, 0.6, 1.0};
    GLfloat mat_diffuse[] = {1.0, 0.75, 0.75, 1.0}; // Rosa claro
    GLfloat mat_specular[] = {0.2, 0.2, 0.2, 1.0};  // Poco brillo
    GLfloat mat_shininess[] = {10.0};               // Superficie mate

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void desactiva_luz(void)
{
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
}

// Variables para la rotación
static GLfloat angulo = 0.0;

void rotar(void)
{
    angulo += 0.3; // Rotación más lenta
    if (angulo > 360.0)
        angulo -= 360.0;
    glutPostRedisplay();
}

// Función para añadir textura de líneas horizontales como en la imagen
void agregarTextura(void)
{
    // Dibujar líneas horizontales sutiles en todo el cuerpo
    glColor3f(0.95, 0.65, 0.65); // Un poco más oscuro que el color principal
    glLineWidth(1.0);

    // Líneas en el cuerpo y otras partes
    for (float y = -0.9; y <= 1.8; y += 0.08)
    {
        glBegin(GL_LINES);
        glVertex3f(-1.0, y, 0.45);
        glVertex3f(1.0, y, 0.45);
        glEnd();
    }
}

void animarPiernas(void)
{
    // Oscilar entre -30 y 30 grados para piernas y brazos
    anguloPiernaIzq += 1.5f * direccion;
    anguloPiernaDer -= 1.5f * direccion;
    anguloBrazoIzq -= 1.5f * direccion;
    anguloBrazoDer += 1.5f * direccion;

    if (anguloPiernaIzq > 30.0f || anguloPiernaIzq < -30.0f)
        direccion = -direccion;

    glutPostRedisplay();
}

void animarPiernasYMovimiento(void)
{
    // SOLUCIÓN: Detectar cambio de dirección cuando cruza los límites
    // Verificar si el conejo ha cambiado de dirección
    int hayCambioDeExtremoPosicion = 0;

    // Verificar si el conejo alcanzó un extremo y va a cambiar de dirección
    if ((posicionX >= 2.0f && direccionMovimiento > 0) ||
        (posicionX <= -2.0f && direccionMovimiento < 0))
    {
        hayCambioDeExtremoPosicion = 1;
    }

    // Actualizar la dirección después de comprobar si hubo cambio
    if (hayCambioDeExtremoPosicion)
    {
        direccionMovimiento = -direccionMovimiento;
        contadorVueltas++;
        // Imprime el valor para depuración
        printf("Cambio de dirección! Contador de vueltas: %d\n", contadorVueltas);

        // Después de 3 vueltas completas (6 cambios de dirección), el conejo muere
        if (contadorVueltas >= 2 && !conejoMuerto)
        {
            conejoMuerto = 1;
            printf("¡El conejo ha muerto después de %d vueltas!\n", contadorVueltas / 2);
        }
    }

    // Animar el humo
    humo += 0.1f;

    if (!conejoMuerto)
    {
        // Oscilar entre -30 y 30 grados para piernas y brazos
        anguloPiernaIzq += 1.5f * direccion;
        anguloPiernaDer -= 1.5f * direccion;
        anguloBrazoIzq -= 1.5f * direccion;
        anguloBrazoDer += 1.5f * direccion;

        if (anguloPiernaIzq > 30.0f || anguloPiernaIzq < -30.0f)
            direccion = -direccion;

        // Mover el conejo de izquierda a derecha y viceversa
        posicionX += 0.01f * direccionMovimiento;

        // El cambio de dirección ya se maneja arriba
    }
    else
    {
        // Animación de caída cuando está muerto
        if (anguloCaida < 90.0f)
        {
            anguloCaida += 2.0f;
        }
    }

    glutPostRedisplay();
}

// Función para dibujar un estante
void estante(void)
{
    // Color marrón para el estante
    glColor3f(0.6, 0.4, 0.2); // Marrón

    // Desactivar iluminación para dibujar el estante con color plano
    desactiva_luz();

    // Base del estante
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0); // Colocar detrás del conejo
    glScalef(3.0, 0.1, 0.6);      // Forma de tabla rectangular
    glutSolidCube(1.0);
    glPopMatrix();

    // Soporte izquierdo
    glPushMatrix();
    glTranslatef(-1.4, -0.5, -2.0);
    glScalef(0.1, 1.0, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();

    // Soporte derecho
    glPushMatrix();
    glTranslatef(1.4, -0.5, -2.0);
    glScalef(0.1, 1.0, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();

    // Reactivar iluminación
    ilumina();
}

// Función para dibujar un chocolate con envoltura
void chocolate(void)
{
    // Envoltura del chocolate (color dorado)
    glColor3f(0.8, 0.7, 0.0); // Dorado

    glPushMatrix();
    glTranslatef(-1.0, 0.2, -1.8); // Posición en el estante
    glScalef(0.4, 0.1, 0.3);       // Forma de barra rectangular
    glutSolidCube(1.0);
    glPopMatrix();

    // Parte del chocolate visible (marrón oscuro)
    glColor3f(0.3, 0.15, 0.1); // Marrón oscuro

    glPushMatrix();
    glTranslatef(-1.0, 0.26, -1.8); // Ligeramente encima de la envoltura
    glScalef(0.35, 0.05, 0.25);     // Un poco más pequeño que la envoltura
    glutSolidCube(1.0);
    glPopMatrix();

    // Detalles de la envoltura (líneas doradas más brillantes)
    desactiva_luz();
    glColor3f(1.0, 0.9, 0.2); // Dorado brillante
    glLineWidth(1.0);

    glBegin(GL_LINES);
    // Líneas horizontales en la envoltura
    glVertex3f(-1.2, 0.21, -1.65);
    glVertex3f(-0.8, 0.21, -1.65);

    glVertex3f(-1.2, 0.21, -1.95);
    glVertex3f(-0.8, 0.21, -1.95);
    glEnd();

    ilumina();
}

// Función para dibujar un dulce
void dulce(void)
{
    // Color del dulce (rojo brillante)
    glColor3f(1.0, 0.1, 0.1); // Rojo

    glPushMatrix();
    glTranslatef(0.0, 0.15, -1.8); // Posición en el estante
    glScalef(0.3, 0.3, 0.3);       // Tamaño del dulce
    glutSolidSphere(0.5, 20, 20);  // Forma esférica
    glPopMatrix();

    // Envoltura del dulce (transparente con torción)
    glColor4f(1.0, 1.0, 1.0, 0.5); // Blanco semi-transparente

    glPushMatrix();
    glTranslatef(0.0, 0.15, -1.8);

    // Extremo izquierdo de la envoltura
    glPushMatrix();
    glTranslatef(-0.2, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0); // Girar para simular torsión
    glScalef(0.1, 0.2, 0.15);
    glutSolidCube(1.0);
    glPopMatrix();

    // Extremo derecho de la envoltura
    glPushMatrix();
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef(-45.0, 0.0, 0.0, 1.0); // Girar en dirección opuesta
    glScalef(0.1, 0.2, 0.15);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

// Modificar la función conejo para incluir el estante y los objetos
void conejo(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3, 0, 9, 0, 0, 0, 0, 1, 0);

    // Configurar para permitir transparencia
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ilumina();

    // Dibujar el estante primero (estará detrás)
    estante();

    // Dibujar los objetos en el estante
    chocolate();
    dulce();

    // Trasladar el conejo
    glPushMatrix();
    glTranslatef(posicionX, 0.0f, 0.0f);

    // Si el conejo está muerto, rotarlo para caer
    if (conejoMuerto)
    {
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f); // Girar 90 grados (caer)
    }

    cuerpo();
    cabeza();
    orejas();
    brazos(anguloBrazoIzq, anguloBrazoDer);
    piernas(anguloPiernaIzq, anguloPiernaDer);

    desactiva_luz();

    ojos();
    boca();

    // Añadir el cigarrillo
    cigarrillo();

    glPopMatrix();

    glDisable(GL_BLEND); // Desactivar transparencia

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Conejo Fumador en OpenGL");
    inicializa();
    glutDisplayFunc(conejo);

    glutIdleFunc(animarPiernasYMovimiento);

    glutMainLoop();
    return 0;
}