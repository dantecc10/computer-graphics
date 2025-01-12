#include <GL/glut.h>
void inicializa(void) {
	glClearColor(1.1, 1.1, 1.1, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1600, 0, 1000);
}

void fillRectangle(int a, int b, int c, int d, int width, double color1, double color2, double color3) {
	glEnd();
	glBegin(GL_LINES);
	(width == 0) ? glLineWidth(1) : glLineWidth(width);
	
	glColor3f(color1, color2, color3);
	
	for (int i = c; i <= d; i++) {
		
		
		glVertex2i(a, i);
		glVertex2i(b, i);
	}
	glEnd();
	glBegin(GL_LINES);
}

void drawTeacher(int x, int y, int min) {
	// Supongamos que el mínimo son 10 px
	// Color piel: rgb(221, 204, 136) / 255 = (.86, .8, .53)
	glEnd();
	glBegin(GL_LINES);
	
	glLineWidth(3);
	glColor3f(0, 0, 0);
	
	glVertex2i(x + (min * 38), y - (min * 90));
	glVertex2i(x + (min * 38), y - (min * 85));
	
	glVertex2i(x + (min * 52), y - (min * 90));
	glVertex2i(x + (min * 52), y - (min * 85));
	
	glColor3f(.86, .8, .53);
	
	// Puño
	fillRectangle(x, x + (min * 10), y - (min * 20), y - (min * 10), 0, .86, .8, .53);
	
	// Índice
	fillRectangle(x + (min * 6), x + (min * 8), y - (min * 10), y - (min * 2), 0, .86, .8, .53);
	
	// Antebrazo
	fillRectangle(x + (min * 3), x + (min * 7), y - (min * 40), y - (min * 20), 0, .86, .8, .53);
	
	// Cabello 1
	fillRectangle(x + (min * 30), x + (min * 60), y - (min * 35), y - (min * 20), 0, 0, 0, 0);
	
	// Cabello 2
	fillRectangle(x + (min * 30), x + (min * 35), y - (min * 40), y - (min * 25), 0, 0, 0, 0);
	
	// Cabello 3
	fillRectangle(x + (min * 55), x + (min * 60), y - (min * 40), y - (min * 25), 0, 0, 0, 0);
	
	// Cabello 4
	fillRectangle(x + (min * 55), x + (min * 65), y - (min * 40), y - (min * 35), 0, 0, 0, 0);
	
	// Cabello 5
	fillRectangle(x + (min * 25), x + (min * 35), y - (min * 40), y - (min * 35), 0, 0, 0, 0);
	
	// Cabeza
	fillRectangle(x + (min * 35), x + (min * 55), y - (min * 45), y - (min * 25), 0, .86, .8, .53);
	
	// Brazo 1
	fillRectangle(x + (min * 1), x + (min * 9), y - (min * 50), y - (min * 40), 0, .2, .6, 1);
	
	// Brazo 2
	fillRectangle(x + (min * 5), x + (min * 15), y - (min * 55), y - (min * 45), 0, .2, .6, 1);
	
	// Brazo 3
	fillRectangle(x + (min * 10), x + (min * 30), y - (min * 60), y - (min * 50), 0, .2, .6, 1);
	
	// Brazo 4
	fillRectangle(x + (min * 60), x + (min * 70), y - (min * 80), y - (min * 50), 0, .2, .6, 1);
	
	// Torso
	fillRectangle(x + (min * 30), x + (min * 60), y - (min * 90), y - (min * 45), 0, .2, .6, 1);
	
	// Cinturón
	fillRectangle(x + (min * 30), x + (min * 60), y - (min * 95), y - (min * 90), 0, 0, 0, 0);
	
	// Cinturón
	fillRectangle(x + (min * 42), x + (min * 48), y - (min * 95), y - (min * 90), 0, .4, .4, .4);
	
	// Debajo
	fillRectangle(x + (min * 30), x + (min * 60), y - (min * 135), y - (min * 95), 0, .4, .4, .4);
	
	glEnd();
	
	glBegin(GL_LINES);
	glLineWidth(3);
	glColor3f(1, 1, 1);
	
	glLineWidth(3);
	glColor3f(1, 1, 1);
	
	glVertex2i(x + (min * 45), y - (min * 100));
	glVertex2i(x + (min * 45), y - (min * 135));
}

void tableChair(int x, int y){
	//A = (x, y);
	//B = (x + alpha, y);
	//C = (x, y - beta);
	//D = (x + alpha, y - beta);
	//E = (x + gamma, y - delta);
	//F = (x + epsilon, y - delta);
	//G = (x + gamma, y - zeta);
	//H = (x + epsilon, y - zeta);
	int alpha = 250, beta = 120, gamma = 50, delta = 30, epsilon = 190, zeta = 140;
	int prop1 = (((x + epsilon) - (x + gamma)) / 7), prop2 = (((y - delta) - (y - zeta)) * (2 / 3));
	int extra = 15;
	glColor3f(.8, .6, 0);
	// Bordes de la mesa
	glVertex2i(x, y);
	glVertex2i(x + alpha, y);
	
	glVertex2i(x, y);
	glVertex2i(x, y - beta);
	
	glVertex2i(x + alpha, y);
	glVertex2i(x + alpha, y - beta);
	
	glVertex2i(x, y - beta);
	glVertex2i(x + gamma, y - beta);
	
	glVertex2i(x + alpha, y - beta);
	glVertex2i(x + epsilon, y - beta);
	
	fillRectangle(x + 1, x + alpha - 1, y - beta + 1, y - 1, 0, .8, .6, 0);
	
	glLineWidth(1);
	glColor3f(0, 0, 0);
	
	// Bordes de la silla
	glVertex2i(x + gamma, y - delta);
	glVertex2i(x + epsilon, y - delta);
	
	glVertex2i(x + gamma, y - delta);
	glVertex2i(x + gamma, y - zeta);
	
	glVertex2i(x + epsilon, y - delta);
	glVertex2i(x + epsilon, y - zeta);
	
	glVertex2i(x + gamma, y - zeta);
	glVertex2i(x + epsilon, y - zeta);
	
	fillRectangle(x + gamma + 1, x + epsilon - 1, y - zeta + 1, y - delta - 1, 0, 1, .8, 0);
	// Patas de la silla
	glEnd();
	glBegin(GL_LINES);
	glLineWidth(extra);
	glColor3f(0, 0, 0);
	
	glVertex2i(x + gamma, y - zeta - extra);
	glVertex2i(x + epsilon, y - zeta - extra);
	
	glVertex2i(x + gamma, y - zeta - extra);
	glVertex2i(x + gamma, y - zeta - (3 * extra));
	
	glVertex2i(x + epsilon, y - zeta - extra);
	glVertex2i(x + epsilon, y - zeta - (3 * extra));
	
	glVertex2i(x + gamma, y - zeta - (3 * extra));
	glVertex2i(x + epsilon, y - zeta - (3 * extra));
	
	fillRectangle(x + gamma + 1, x + epsilon - 1, y - zeta - (3 * extra) + 1, y - zeta - extra - 1, 1, 1, .8, 0);
	
	glEnd();
	glBegin(GL_LINES);
	glLineWidth(extra * 4);
	glColor3f(0, 0, 0);
	glVertex2i(x + gamma + (2 * extra), y - delta - extra);
	glVertex2i(x + gamma + (2 * extra), y - zeta - (6 * extra));
	
	glVertex2i(x + epsilon - (2 * extra), y - delta - extra);
	glVertex2i(x + epsilon - (2 * extra), y - zeta - (6 * extra));
	
}
	
	void pinta(void){
		int a, b, c, d;
		glClear(GL_COLOR_BUFFER_BIT);
		glLineWidth(5);
		glPointSize(5);
		//glBegin(GL_POINTS);
		//glVertex2i(175, 225);
		//glVertex2i(250, 225);
		//glVertex2i(325, 225);
		//glEnd();
		
		//glColor3f(0,1,0);
		glBegin(GL_LINES);
		glColor3f(0,0,0);
		// Salón de clases
		glVertex2i(0, 1000);
		glVertex2i(150, 900);
		
		glVertex2i(1600, 1000);
		glVertex2i(1450, 900);
		
		glVertex2i(1450, 900);
		glVertex2i(150, 900);
		
		glColor3f(.4,.2,0); // Color café
		
		fillRectangle(500, 1100, 830, 850, .4, .2, 0, 0);
		fillRectangle(500, 1100, 540, 560, .4, .2, 0, 0);
		fillRectangle(500, 520, 540, 850, .4, .2, 0, 0);
		fillRectangle(1080, 1100, 540, 850, .4, .2, 0, 0);
		
		glVertex2i(500, 850);
		glVertex2i(1100, 850);
		
		glVertex2i(520, 830);
		glVertex2i(1080, 830);
		
		glVertex2i(500, 540);
		glVertex2i(1100, 540);
		
		glVertex2i(520, 560);
		glVertex2i(1080, 560);
		
		glVertex2i(1080, 560);
		glVertex2i(1080, 830);
		
		glVertex2i(520, 560);
		glVertex2i(520, 830);
		
		glVertex2i(500, 540);
		glVertex2i(500, 850);
		
		glVertex2i(1100, 540);
		glVertex2i(1100, 850);
		
		// Rellenar pizarrón
		a = 520, b = 1080, c = 560, d = 830;	
		fillRectangle(a, b, c, d, 1, 0, .4, 0);
		
		a = 990, b = 1025, c = 560, d = 565;	
		fillRectangle(a, b, c, d, 1, 1, 1, 1);
		
		drawTeacher(1000, 850, 3);
		
		
		// Fin de relleno de pizarrón
		tableChair(100, 460);
		tableChair(400, 460);
		tableChair(700, 460);
		tableChair(1000, 460);
		tableChair(1300, 460);
		
		tableChair(100, 265);
		tableChair(400, 265);
		tableChair(700, 265);
		tableChair(1000, 265);
		tableChair(1300, 265);
		// Termina salón de clases
		glEnd();
		glFlush();
	}
		
		int main(int argc, char ** argv) {
			glutInitWindowSize(1600, 1000);
			glutInit(&argc, argv);
			glutCreateWindow("Dante Castelán Carpinteyro - Graficación");
			
			inicializa();
			glutDisplayFunc(pinta);
			glutMainLoop();
			return 0;
		}
		
		
		
