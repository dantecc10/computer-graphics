#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h> // Para usleep

// Variables para la animación del conejo
static float anguloPiernaIzq = 0.0f;
static float anguloPiernaDer = 0.0f;
static float anguloBrazoIzq = 0.0f;
static float anguloBrazoDer = 0.0f;

static float posicionX = 0.0f;
static float posicionY = 0.0f;
static int direccionMovimiento = 1;
static int direccion = 1;
static int faseSalto = 0;              // 0: fase inicial, 1: subiendo, 2: bajando, 3: terminado
static float velocidadSalto = 0.03f;   // Velocidad del salto
static float alturaMaximaSalto = 1.0f; // Altura máxima deñ salto

static float alturasDulces[4] = {0.0f, 0.0f, 0.0f, 0.0f}; // Altura inicial del dulce
static int direccionDulces[4] = {1, -1, 1, -1};           // Dirección de movimiento (arriba/abajo)
static float velocidadDulces = 0.005f;                    // Velocidad de movimiento de los dulces
static float alturaMaximaDulces = 0.25f;                  // Altura máxima

// Variables para el cigarro y la muerte
static int contadorVueltas = 0;
static int conejoMuerto = 0;
static float anguloCaida = 0.0f;
static float humo = 0.0f;

// Variables para la animación del chocolate
static float escalaChocolateEco = 1.0f;
static float velocidadEscalaChocolate = 0.005f;
static int direccionEscalaChocolate = -1; // -1: encogiendo, 1: expandiendo
static float escalaMinChocolate = 0.85f;  // Tamaño mínimo (85% del original)
static float escalaMaxChocolate = 1.0f;   // Tamaño máximo (tamaño original)

// Variable para control de animación
static int animacionActiva = 1;

void inicializa(void)
{
    glClearColor(0.45, 0.95, 0.95, 0.0); // Fondo rosa claro
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // Cámara
    glMatrixMode(GL_PROJECTION);
    gluPerspective(35, 1, 1, 20);
}

void desactiva_luz(void)
{
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
}

// Aplicar material de papel ecológico
void materialPapelEcologico(void)
{
    GLfloat eco_ambient[] = {0.2, 0.25, 0.15, 1.0};
    GLfloat eco_diffuse[] = {0.3, 0.45, 0.25, 1.0};
    GLfloat eco_specular[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat eco_shininess[] = {3.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, eco_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, eco_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, eco_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, eco_shininess);
}

void Trans2D(GLubyte label[], int x, int y)
{
    GLint k;
    // glClear(GL_COLOR_BUFFER_BIT); // Desactivar para no parpadear
    glColor3d(1.0, 0.1, 0.1);

    for (k = 0; k < sizeof(label); k++)
    {
        glRasterPos2i(x, y);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, label[k]);
        x += 15;
    }

    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'O');
    // glFlush();
}

void ilumina(void)
{
    GLfloat positionAndType[] = {6, 6, 6, 1};
    GLfloat environmentColor[] = {0.4, 0.4, 0.4, 1.0};
    GLfloat difuseColor[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specularColor[] = {0.5, 0.5, 0.5, 1.0};

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
    GLfloat mat_diffuse[] = {1.0, 0.75, 0.75, 1.0};
    GLfloat mat_specular[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat mat_shininess[] = {10.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

// Función para aplicar material metálico para la lata
void materialMetal(void)
{
    GLfloat metal_ambient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat metal_diffuse[] = {0.7, 0.7, 0.8, 1.0};
    GLfloat metal_specular[] = {0.9, 0.9, 0.9, 1.0};
    GLfloat metal_shininess[] = {80.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, metal_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, metal_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, metal_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, metal_shininess);
}

void chocolateOrganico(void)
{
    desactiva_luz();

    // Envoltura de papel ecológico (verde oliva mate)
    materialPapelEcologico();
    glColor3f(0.45, 0.53, 0.34);

    glPushMatrix();
    glTranslatef(-0.4, 0.10, -1.8);
    glScalef(0.4 * escalaChocolateEco, 0.1 * escalaChocolateEco, 0.3 * escalaChocolateEco);
    glutSolidCube(1.0);
    glPopMatrix();

    // Dibujar textura de fibras en el papel ecológico
    glLineWidth(1.0);
    glColor3f(0.35, 0.32, 0.25); // Verde más oscuro para las fibras

    glPushMatrix();
    glTranslatef(-0.4, 0.06, -1.8);
    glScalef(escalaChocolateEco, escalaChocolateEco, escalaChocolateEco);

    glBegin(GL_LINES);
    // Líneas horizontales para simular fibras de papel reciclado
    for (float x = -0.2; x <= 0.2; x += 0.05)
    {
        for (float z = -0.15; z <= 0.15; z += 0.06)
        {
            glVertex3f(x - 0.02, 0.01, z);
            glVertex3f(x + 0.03, 0.01, z + 0.01);
        }
    }

    // Algunas fibras verticales dispersas
    for (float x = -0.18; x <= 0.18; x += 0.08)
    {
        for (float z = -0.12; z <= 0.12; z += 0.09)
        {
            glVertex3f(x, 0.01, z - 0.02);
            glVertex3f(x + 0.01, 0.01, z + 0.04);
        }
    }
    glEnd();
    glPopMatrix();

    // Parte visible del chocolate (marrón oscuro)
    GLfloat choc_brown_ambient[] = {0.2, 0.1, 0.05, 1.0};
    GLfloat choc_brown_diffuse[] = {0.35, 0.2, 0.1, 1.0}; // Marrón oscuro
    GLfloat choc_brown_specular[] = {0.4, 0.4, 0.4, 1.0}; // Algo de brillo para el chocolate
    GLfloat choc_brown_shininess[] = {30.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, choc_brown_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, choc_brown_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, choc_brown_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, choc_brown_shininess);

    glColor3f(0.35, 0.2, 0.1); // Marrón oscuro para chocolate

    glPushMatrix();
    glTranslatef(-0.4, 0.11, -1.8);
    glScalef(0.2 * escalaChocolateEco, 0.05 * escalaChocolateEco, 0.2 * escalaChocolateEco);
    glutSolidCube(1.0);
    glPopMatrix();

    // Detalles de la envoltura ecológica (símbolo de reciclaje)
    glColor3f(0.2, 0.3, 0.15); // Verde más oscuro para el símbolo
    glLineWidth(2.0);

    glPushMatrix();
    glTranslatef(-0.4, 0.16, -1.65);
    glScalef(0.03 * escalaChocolateEco, 0.03 * escalaChocolateEco, 0.03 * escalaChocolateEco);

    glPopMatrix();

    // Texto "ECO" en la envoltura
    glColor3f(0.2, 0.3, 0.15); // Verde oscuro para el texto
    glLineWidth(1.5);

    glPushMatrix();
    glTranslatef(-0.6, 0.10, -1.95);
    glScalef(escalaChocolateEco, escalaChocolateEco, escalaChocolateEco);

    // Letra E
    glBegin(GL_LINES);
    glVertex3f(-0.05, 0, 0);
    glVertex3f(0.05, 0, 0);

    glVertex3f(-0.05, 0, 0);
    glVertex3f(-0.05, -0.04, 0);

    glVertex3f(-0.05, -0.02, 0);
    glVertex3f(0.03, -0.02, 0);

    glVertex3f(-0.05, -0.04, 0);
    glVertex3f(0.05, -0.04, 0);

    // Letra C
    glVertex3f(0.08, 0, 0);
    glVertex3f(0.18, 0, 0);

    glVertex3f(0.08, 0, 0);
    glVertex3f(0.08, -0.04, 0);

    glVertex3f(0.08, -0.04, 0);
    glVertex3f(0.18, -0.04, 0);

    // Letra O
    glVertex3f(0.21, 0, 0);
    glVertex3f(0.31, 0, 0);

    glVertex3f(0.21, 0, 0);
    glVertex3f(0.21, -0.04, 0);

    glVertex3f(0.21, -0.04, 0);
    glVertex3f(0.31, -0.04, 0);

    glVertex3f(0.31, 0, 0);
    glVertex3f(0.31, -0.04, 0);
    glEnd();

    glPopMatrix();

    // Restaurar iluminación estándar
    ilumina();
}

// Función para dibujar una lata de dulces metálica (usando solo cubos)
void lataDulces(void)
{
    // Aplicar material metálico para la lata
    desactiva_luz();
    materialMetal();

    // Cuerpo principal de la lata (cubo escalado)
    glColor3f(0.305, 0.305, 0.305); // Color plateado/gris claro

    // Cuerpo rectangular de la lata
    glPushMatrix();
    glTranslatef(1.0, 0.3, -1.8);
    glScalef(0.5, 0.5, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    // Tapa superior de la lata (cubo aplastado)
    glPushMatrix();
    glTranslatef(1.0, 0.53, -1.8);
    glScalef(0.55, 0.05, 0.45);
    glutSolidCube(1.0);
    glPopMatrix();

    // Añadir detalles decorativos (líneas horizontales)
    glColor3f(0.3, 0.3, 0.8); // Azul oscuro para los detalles
    glLineWidth(2.0);

    // Dibujar líneas horizontales decorativas
    glBegin(GL_LINES);
    for (float y = 0.3; y <= 0.6; y += 0.1)
    {
        glVertex3f(0.76, y, -1.6);
        glVertex3f(1.24, y, -1.6);
    }
    glEnd();

    // Etiqueta de la lata "CANDY"
    glColor3f(0.9, 0.1, 0.1); // Rojo para la etiqueta
    glLineWidth(3.0);

    // Letra C
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.85, 0.45, -1.55);
    glVertex3f(0.8, 0.45, -1.55);
    glVertex3f(0.8, 0.35, -1.55);
    glVertex3f(0.85, 0.35, -1.55);
    glEnd();

    // Letra A
    glBegin(GL_LINES);
    glVertex3f(0.9, 0.35, -1.55);
    glVertex3f(0.95, 0.45, -1.55);

    glVertex3f(0.95, 0.45, -1.55);
    glVertex3f(1.0, 0.35, -1.55);

    glVertex3f(0.92, 0.4, -1.55);
    glVertex3f(0.98, 0.4, -1.55);
    glEnd();

    // Letra N
    glBegin(GL_LINES);
    glVertex3f(1.05, 0.35, -1.55);
    glVertex3f(1.05, 0.45, -1.55);

    glVertex3f(1.05, 0.45, -1.55);
    glVertex3f(1.1, 0.35, -1.55);

    glVertex3f(1.1, 0.35, -1.55);
    glVertex3f(1.1, 0.45, -1.55);
    glEnd();

    // Letra D
    glBegin(GL_LINE_STRIP);
    glVertex3f(1.15, 0.35, -1.55);
    glVertex3f(1.15, 0.45, -1.55);
    glVertex3f(1.2, 0.42, -1.55);
    glVertex3f(1.2, 0.38, -1.55);
    glVertex3f(1.15, 0.35, -1.55);
    glEnd();

    // Letra Y
    glBegin(GL_LINES);
    glVertex3f(1.25, 0.45, -1.55);
    glVertex3f(1.275, 0.4, -1.55);

    glVertex3f(1.275, 0.4, -1.55);
    glVertex3f(1.275, 0.35, -1.55);

    glVertex3f(1.275, 0.4, -1.55);
    glVertex3f(1.3, 0.45, -1.55);
    glEnd();

    // ilumina();

    // Material para dulces coloridos
    GLfloat candy_ambient[] = {0.3, 0.3, 0.4, 1.0};
    GLfloat candy_diffuse[] = {0.6, 0.7, 1.0, 1.0};
    GLfloat candy_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat candy_shininess[] = {70.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, candy_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, candy_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, candy_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, candy_shininess);

    // Dulce 1 (azul) - usando cubos pequeños y aplicando la animación
    glColor3f(0.4, 0.6, 1.0);
    glPushMatrix();
    glTranslatef(0.9, 0.58 + alturasDulces[0], -1.75); // Añadido alturasDulces[0]
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Dulce 2 (rojo) - usando cubos pequeños y aplicando la animación
    GLfloat candy2_diffuse[] = {1.0, 0.2, 0.2, 1.0}; // Rojo
    glMaterialfv(GL_FRONT, GL_DIFFUSE, candy2_diffuse);
    glColor3f(1.0, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(1.1, 0.58 + alturasDulces[1], -1.85); // Añadido alturasDulces[1]
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Dulce 3 (verde) - usando cubos pequeños y aplicando la animación
    GLfloat candy3_diffuse[] = {0.2, 0.8, 0.2, 1.0}; // Verde
    glMaterialfv(GL_FRONT, GL_DIFFUSE, candy3_diffuse);
    glColor3f(0.2, 0.8, 0.2);
    glPushMatrix();
    glTranslatef(1.0, 0.58 + alturasDulces[2], -1.9); // Añadido alturasDulces[2]
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Dulce 4 (amarillo) - usando un cubo pequeño adicional y aplicando la animación
    GLfloat candy4_diffuse[] = {1.0, 1.0, 0.0, 1.0}; // Amarillo
    glMaterialfv(GL_FRONT, GL_DIFFUSE, candy4_diffuse);
    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.85, 0.58 + alturasDulces[3], -1.85); // Añadido alturasDulces[3]
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Restaurar iluminación estándar para objetos siguientes
    ilumina();
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

// Función para dibujar el cigarrillo - improved version
void cigarrillo(void)
{
    // Cuerpo del cigarrillo (blanco)
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glTranslatef(0.1, 0.58, 0.5);
    glRotatef(30, 0, 0, 1);
    glScalef(0.08, 0.3, 0.08);
    glutSolidCube(0.5);
    glPopMatrix();

    // Filtro del cigarrillo (naranja)
    glColor3f(0.9, 0.6, 0.3); // Color naranja
    glPushMatrix();
    glTranslatef(0.16, 0.68, 0.5); // Ajustado para la nueva posición
    glRotatef(30, 0, 0, 1);
    glScalef(0.08, 0.06, 0.08); // Más grueso
    glutSolidCube(0.5);         // Pongo un cubo pequeño
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

// Función para aplicar material de conejo (peluche rosa)
void materialConejo(void)
{
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

// Función para aplicar material de madera (estante)
void materialMadera(void)
{
    GLfloat mat_ambient[] = {0.3, 0.2, 0.1, 1.0};
    GLfloat mat_diffuse[] = {0.6, 0.4, 0.2, 1.0};  // Marrón
    GLfloat mat_specular[] = {0.1, 0.1, 0.1, 1.0}; // Poco brillo
    GLfloat mat_shininess[] = {5.0};               // Muy mate

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

// Función para dibujar un estante
void estante(void)
{
    // Aplicar material de madera para el estante
    materialMadera();

    // Color marrón para el estante (se usa con iluminación)
    glColor3f(0.6, 0.4, 0.2); // Marrón

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

    // Agregar vetas de madera (líneas más oscuras)
    desactiva_luz();
    glColor3f(0.4, 0.25, 0.1); // Marrón más oscuro para las vetas
    glLineWidth(1.0);

    // Vetas horizontales en la superficie del estante
    glBegin(GL_LINES);
    for (float x = -1.4; x <= 1.4; x += 0.2)
    {
        glVertex3f(x, 0.05, -1.7);
        glVertex3f(x, 0.05, -2.3);
    }
    glEnd();

    // Restaurar iluminación y material por defecto
    ilumina();
}

// Función para dibujar un chocolate con envoltura rojo y azul
void chocolate(void)
{
    desactiva_luz();
    // Configurar material para el chocolate (rojo)
    GLfloat choc_ambient[] = {0.4, 0.0, 0.0, 1.0};
    GLfloat choc_diffuse[] = {0.9, 0.1, 0.1, 1.0};  // Rojo vivo
    GLfloat choc_specular[] = {0.4, 0.4, 0.4, 1.0}; // Brillo para envoltura
    GLfloat choc_shininess[] = {20.0};              // Más brillante para el papel

    // Aplicar material al chocolate
    glMaterialfv(GL_FRONT, GL_AMBIENT, choc_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, choc_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, choc_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, choc_shininess);

    // Envoltura del chocolate (roja)
    glColor3f(0.9, 0.1, 0.1); // Rojo intenso

    glPushMatrix();
    glTranslatef(-1.0, 0.1, -1.8); // Posición en el estante
    glScalef(0.4, 0.1, 0.3);       // Forma de barra rectangular
    glutSolidCube(1.0);
    glPopMatrix();

    // Parte del chocolate visible (azul)
    // Nuevo material para la parte azul
    GLfloat choc_blue_ambient[] = {0.0, 0.0, 0.3, 1.0};
    GLfloat choc_blue_diffuse[] = {0.0, 0.2, 0.8, 1.0}; // Azul

    glMaterialfv(GL_FRONT, GL_AMBIENT, choc_blue_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, choc_blue_diffuse);

    glColor3f(0.0, 0.2, 0.8); // Azul

    glPushMatrix();
    glTranslatef(-1.0, 0.16, -1.8); // Ligeramente encima de la envoltura
    glScalef(0.35, 0.05, 0.25);     // Un poco más pequeño que la envoltura
    glutSolidCube(1.0);
    glPopMatrix();

    // Detalles de la envoltura (líneas azules en fondo rojo)
    desactiva_luz();
    glColor3f(0.2, 0.4, 1.0); // Azul más brillante
    glLineWidth(2.0);

    glBegin(GL_LINES);
    // Líneas horizontales azules en la envoltura roja
    glVertex3f(-1.2, 0.11, -1.65);
    glVertex3f(-0.8, 0.11, -1.65);

    glVertex3f(-1.2, 0.11, -1.95);
    glVertex3f(-0.8, 0.11, -1.95);
    glEnd();

    // Restaurar iluminación
    ilumina();
}

// Función para dibujar un dulce rojo brillante
void dulce(void)
{
    desactiva_luz();
    // Configurar material para el dulce (rojo intenso con brillo)
    GLfloat candy_ambient[] = {0.4, 0.0, 0.0, 1.0};
    GLfloat candy_diffuse[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat candy_specular[] = {1.0, 0.8, 0.8, 1.0};
    GLfloat candy_shininess[] = {90.0};

    // Aplicar material al dulce
    glMaterialfv(GL_FRONT, GL_AMBIENT, candy_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, candy_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, candy_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, candy_shininess);

    // Cuerpo del dulce (rojo brillante)
    glColor3f(1.0, 0.0, 0.0); // Rojo puro

    glPushMatrix();
    glTranslatef(0.0, 0.15, -1.8); // Posición en el estante
    glScalef(0.3, 0.3, 0.3);       // Tamaño del dulce
    glutSolidSphere(0.5, 20, 20);  // Forma esférica
    glPopMatrix();

    // Material para la envoltura transparente
    GLfloat wrapper_ambient[] = {0.8, 0.8, 0.8, 0.3};
    GLfloat wrapper_diffuse[] = {1.0, 1.0, 1.0, 0.3};  // Blanco semi-transparente
    GLfloat wrapper_specular[] = {1.0, 1.0, 1.0, 0.5}; // Brillo transparente

    glMaterialfv(GL_FRONT, GL_AMBIENT, wrapper_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wrapper_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wrapper_specular);

    // Envoltura del dulce (transparente con torción)
    glColor4f(1.0, 1.0, 1.0, 0.5); // Blanco semi-transparente

    // Habilitar mezcla para transparencia
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

    // Desactivar mezcla para el resto de objetos
    glDisable(GL_BLEND);

    // Restaurar iluminación estándar para objetos siguientes
    ilumina();
}


void actualizarAnimacion(void)
{
    // Animar el humo
    humo += 0.1f;

    // Animar los dulces sobre la lata (movimiento independiente)
    for (int i = 0; i < 4; i++)
    {
        // Actualizar posición de cada dulce
        alturasDulces[i] += velocidadDulces * direccionDulces[i];

        // Verificar si alcanzó el límite superior o inferior
        if (alturasDulces[i] >= alturaMaximaDulces || alturasDulces[i] <= -0.01f)
        {
            // Cambiar dirección
            direccionDulces[i] *= -1;
        }
    }

    // Animar el chocolate ecológico (encogimiento y expansión)
    escalaChocolateEco += velocidadEscalaChocolate * direccionEscalaChocolate;

    // Verificar límites y cambiar dirección si es necesario
    if (escalaChocolateEco <= escalaMinChocolate || escalaChocolateEco >= escalaMaxChocolate)
    {
        direccionEscalaChocolate *= -1;
    }

    // Gestionar la animación de salto antes del movimiento horizontal
    if (faseSalto != 3)
    {
        switch (faseSalto)
        {
        case 0: // Fase inicial - pequeña pausa antes de saltar
            faseSalto = 1;
            break;

        case 1: // Subiendo
            posicionY += velocidadSalto;

            // Mover ligeramente piernas y brazos durante el salto
            anguloPiernaIzq -= 1.0f;
            anguloPiernaDer -= 1.0f;
            anguloBrazoIzq += 1.5f;
            anguloBrazoDer += 1.5f;

            // Verificar si alcanzó la altura máxima
            if (posicionY >= alturaMaximaSalto)
            {
                faseSalto = 2;
            }
            break;

        case 2: // Bajando
            posicionY -= velocidadSalto;

            // Ajustar piernas y brazos para preparar aterrizaje
            anguloPiernaIzq += 1.0f;
            anguloPiernaDer += 1.0f;
            anguloBrazoIzq -= 1.5f;
            anguloBrazoDer -= 1.5f;

            // Verificar si volvió a la posición inicial
            if (posicionY <= 0.0f)
            {
                posicionY = 0.0f;
                faseSalto = 3; // Salto completo

                // Reiniciar posiciones de extremidades para comenzar movimiento normal
                anguloPiernaIzq = 0.0f;
                anguloPiernaDer = 0.0f;
                anguloBrazoIzq = 0.0f;
                anguloBrazoDer = 0.0f;

                printf("¡Salto completado! Comenzando movimiento horizontal.\n");
            }
            break;
        }
    }
    else
    {
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
        }
        else
        {
            // Animación de caída cuando está muerto
            if (anguloCaida < 90.0f)
            {
                anguloCaida += 2.0f;
            }
        }
    }
}

// Modificar la función renderizarEscena() para aplicar la posición vertical
void renderizarEscena(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Configurar vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3, 0, 9, 0, 0, 0, 0, 1, 0);

    ilumina();

    // Dibujar el estante primero (estará detrás)
    estante();

    // Dibujar los objetos en el estante
    chocolate();
    dulce();
    lataDulces();
    chocolateOrganico();

    // Aplicar material del conejo para asegurarnos de que tiene las propiedades correctas
    materialConejo();

    // Trasladar el conejo - aplicando tanto la posición horizontal como la vertical
    glPushMatrix();
    glTranslatef(posicionX, posicionY, 0.0f);

    // Si el conejo está muerto, rotarlo para caer
    if (conejoMuerto)
    {
        glRotatef(anguloCaida, 0.0f, 0.0f, 1.0f); // Girar para caer
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

    glutSwapBuffers(); // Usamos doble buffer para evitar parpadeo
}

// Función principal para animar y dibujar - reemplaza a las funciones anteriores
void conejo(void)
{
    // Bucle principal: continuará mientras la animación esté activa
    while (animacionActiva)
    {
        // Actualizar estado de animación
        actualizarAnimacion();

        // Renderizar escena
        renderizarEscena();

        // Dormir un poco para controlar la velocidad de animación (16ms ≈ 60fps)
        usleep(16000); // 16000 microsegundos = 16ms
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Castelán Carpinteyro Dante");

    inicializa();

    // Registrar la función de renderizado
    glutDisplayFunc(conejo);

    glutMainLoop();
    return 0;
}