// Automovil para practica porterior

#include <GL/glut.h>
#include <unistd.h>
// Inicializacion
void inicializa (void) {

    glClearColor(0.1, 0.1, 0.1, 0.0); // Background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, 400, -250, 250); // Los datos deben coincidir con el tamaño de la ventana

}

void circle (int x, int y, float ratio) {
	
	// Se multiplica el tirante por el factor ideal para los puntos de control
	float tirante = ratio * 0.55228;
	
	float I[4][3] = {
	{x, y + ratio, 0},
	{x + tirante, y + ratio, 0},
	{x + ratio, y + tirante, 0},
	{x + ratio, y, 0}
	};
	
	float II[4][3] = {
	{x + ratio, y, 0},
	{x + ratio, y - tirante, 0},
	{x + tirante, y - ratio, 0},
	{x, y - ratio, 0}
	};
	
	float III[4][3] = {
	{x, y - ratio, 0},
	{x - tirante, y - ratio, 0},
	{x - ratio, y - tirante, 0},
	{x - ratio, y, 0}
	};
	
	float IV[4][3] = {
	{x - ratio, y, 0},
	{x - ratio, y + tirante, 0},
	{x - tirante, y + ratio, 0},
	{x, y + ratio, 0}
	};
	
	// Habilita las curvas bezier
	glEnable(GL_MAP1_VERTEX_3);
	glMapGrid1f(20, 0, 1);
	
	// Evalua cada cuadrante del circulo
	glMap1f(GL_MAP1_VERTEX_3, 0, 1, 3, 4, *I);
	glEvalMesh1(GL_LINE, 0, 20);
	
	glMap1f(GL_MAP1_VERTEX_3, 0, 1, 3, 4, *II);
	glEvalMesh1(GL_LINE, 0, 20);
	
	glMap1f(GL_MAP1_VERTEX_3, 0, 1, 3, 4, *III);
	glEvalMesh1(GL_LINE, 0, 20);
	
	glMap1f(GL_MAP1_VERTEX_3, 0, 1, 3, 4, *IV);
	glEvalMesh1(GL_LINE, 0, 20);
	
	// Desactiva las curvas bezier
	glDisable(GL_MAP1_VERTEX_3);
	
}

void head (void) {
	
	// Cabeza
	circle(257, 25, 15);
	
	// Cuello
	glBegin(GL_LINES);
	
	glVertex2i(257, 10);
	glVertex2i(257, 3);
	
	glEnd();
	
}

void eye (void) {
	circle(254, 28, 3);
}

void hair (void) {
	
	glBegin(GL_LINES);
	
	glVertex2i(257, 40);
	glVertex2i(267, 45);
	
	glVertex2i(267, 36);
	glVertex2i(277, 41);
	
	glVertex2i(271, 30);
	glVertex2i(281, 35);
	
	glEnd();
	
}

void mouth (void) {
	
	glBegin(GL_LINES);
	
	glVertex2i(244, 17);
	glVertex2i(257, 17);
	
	glEnd();
	
}

void car (void) {
	
	// Cuerpo general
	glBegin(GL_LINE_STRIP);
	
	glVertex2i(307, -40);
	glVertex2i(345, -20);
	glVertex2i(317, 60);
	glVertex2i(157, 25);
	glVertex2i(137, -20);
	glVertex2i(157, -40);
	glVertex2i(167, -40);
	
	glEnd();
	
	// Ventana
	glBegin(GL_LINE_STRIP);
	
	glVertex2i(182, 30);
	glVertex2i(202, -10);
	glVertex2i(287, 10);
	glVertex2i(297, 55);
	
	glEnd();
	
	// Partes sueltas
	glBegin(GL_LINES);
	
	glVertex2i(197, -40);
	glVertex2i(277, -40);
	
	glEnd();
	
}

void wheels (void) {
	
	// Rueda frontal
	circle(182, -40, 15);
	circle(182, -40, 8);
	
	// Rueda trasera
	circle(292, -40, 15);
	circle(292, -40, 8);
	
}

void road (void) {

	glBegin(GL_LINES);
	
		glVertex2i(-400, 100);
		glVertex2i(400, 100);
		
		glVertex2i(-400, -100);
		glVertex2i(400, -100);
	
	glEnd();
	
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2, 0x00FF);
	
	glBegin(GL_LINES);
	
		glVertex2i(-400, 0);
		glVertex2i(400, 0);
	
	glEnd();
	
	glDisable(GL_LINE_STIPPLE);

}

// Pintado
void pintaAuto (void) {

	glScalef(0.7, 0.7, 0);
	glTranslatef(180, 68, 0);
	mouth();
	hair();
	glLineWidth(3);
	head();
	glLineWidth(2);
	eye();
	glLineWidth(3);
	wheels();
	car();

}

void animate (void) {

	int frame = 0;
	int desplazaX = 0;
	int desplazaY = 0;

	while (frame < 2000) {
	
		glClear(GL_COLOR_BUFFER_BIT);
		
		glColor3f(1, 1, 1);
		glLineWidth(4);
		road();
		
		if (frame <= 580) {
			glPushMatrix();
			glTranslatef(desplazaX--, 0, 0);
			pintaAuto();
			glPopMatrix();
		} else if (frame <= 630) {
			glPushMatrix();
			if (frame == 630) {
				glScalef(-1, 1, 0);
				glTranslatef(-desplazaX, 0, 0);
			} else {
				glTranslatef(desplazaX, 0, 0);
			}
			glTranslatef(0, desplazaY--, 0);
			pintaAuto();
			glPopMatrix();
		} else if (frame <= 680) {
			
			glPushMatrix();
			glTranslatef(0, desplazaY--, 0);
			pintaAuto();
			glPopMatrix();
		}
		
		frame++;
		usleep(2);
		glFlush();
	
	}

}

// Main
int main (int argc, char** argv) {

    glutInitWindowSize(1200, 750);
    glutInit(&argc, argv);

    glutCreateWindow("Automovil en carretera");
    inicializa();
    glutDisplayFunc(animate);
    glutMainLoop();

    return 0;

}
