#include <GL/glut.h>
#include <math.h>
void inicializa(void) {
	glClearColor(0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 800, 0, 800);
}

void pinta(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Top
	glBegin(GL_POINTS);
	glVertex2i(c1, 400);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2i(400, 400);
	glVertex2i(100.cos(45), 100.sin(45));
	glVertex2i(500, 400);	
	
	for(double i=0; i<=r; i+=.1){
		for(double j=0; j<=r; j+.1){
			if(((i-c1)*(i-c1))+((j-c2)*(j-c2)) == (r*r)){
				glVertex2i(i, j);
			}
		}
	}
	
	glEnd();
	glFlush();
}
	
	int main(int argc, char ** argv) {
		glutInitWindowSize(800, 800);
		glutInit(&argc, argv);
		glutCreateWindow("Mi primer programa");
		
		inicializa();
		glutDisplayFunc(pinta);
		glutMainLoop();
		return 0;
	}
	
	
	
	
