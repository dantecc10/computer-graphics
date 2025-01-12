#include <GL/glut.h>
void inicializa(void)
{
	glClearColor(1, 1, 1, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void pinta(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glPointSize(1);
	glColor3f(0, 0, 0);
	
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(4, 0xff22);
	glBegin(GL_LINES);
	
	// Líneas punteadas
	glVertex2i(300, 230);
	glVertex2i(300, 310);
	
	glVertex2i(295, 235);
	glVertex2i(295, 315);

	glVertex2i(290, 240);
	glVertex2i(290, 320);
	
	glVertex2i(200, 250);
	glVertex2i(200, 330);
	
	glVertex2i(205, 245);
	glVertex2i(205, 315);
	
	glVertex2i(210, 240);
	glVertex2i(210, 310);
	
	// Líneas punteadas inferiores
	glVertex2i(300, 220);
	glVertex2i(300, 140);
	
	glVertex2i(295, 215);
	glVertex2i(295, 135);
	
	glVertex2i(290, 210);
	glVertex2i(290, 130);
	
	glVertex2i(150, 220);
	glVertex2i(150, 140);
	
	glVertex2i(155, 215);
	glVertex2i(155, 145);
	
	glVertex2i(160, 210);
	glVertex2i(160, 150);
	
	glVertex2i(250, 200);
	glVertex2i(250, 140);
	
	glVertex2i(255, 205);
	glVertex2i(255, 145);
	
	glVertex2i(245, 205);
	glVertex2i(245, 145);
	
	//--
	glVertex2i(200, 140);
	glVertex2i(200, 210);
	
	glVertex2i(205, 125);
	glVertex2i(205, 205);
	
	glVertex2i(210, 120);
	glVertex2i(210, 190);
	
	glEnd();
	
	glDisable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_STRIP);
	
	// Respaldo	
	glVertex2i(200, 380);
	glVertex2i(300, 360);
	
	glVertex2i(300, 360);
	glVertex2i(300, 310);
	
	glVertex2i(300, 310);
	glVertex2i(200, 330);
	
	glVertex2i(200, 330);
	glVertex2i(200, 380);
		
	glEnd();
	glBegin(GL_LINE_STRIP);	
	
	// Asiento
	glVertex2i(200, 250);
	glVertex2i(300, 230);
	
	glVertex2i(300, 230);
	glVertex2i(250, 210);
	
	glVertex2i(250, 210);
	glVertex2i(150, 230);
	
	glVertex2i(150, 230);
	glVertex2i(200, 250);
		
	glEnd();
	glBegin(GL_LINES);	
	
	glVertex2i(150, 230);
	glVertex2i(150, 220);
	
	glVertex2i(150, 220);
	glVertex2i(250, 200);	
	
	glVertex2i(250, 200);
	glVertex2i(300, 220);
	
	glVertex2i(300, 220);
	glVertex2i(300, 230);
	
	glVertex2i(150, 220);
	glVertex2i(150, 230);
	
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInitWindowSize(500, 500);
	glutInit(&argc, argv);
	glutCreateWindow("Mi primer programa");
	
	inicializa();
	glutDisplayFunc(pinta);
	glutMainLoop();
	return 0;
}
