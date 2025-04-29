#include <GL/glut.h>

void inicializa(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0); // Color de fondo RGBA (A no interesa por ahora)
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0); // Cámara
	glMatrixMode(GL_PROJECTION);		  // Para el tipo de matriz a usar: Proyección
	gluPerspective(35, 1, 1, 20);
}

/*void esfera1(void)
{
	glColor3f(77.0 / 255.0, 131.0 / 255.0, 22.0 / 255.0);
	glPushMatrix();
	glScalef(0.9, 1, 1);
	glTranslatef(0, -0.5, 0);
	glutSolidSphere(0.4, 40, 30);
	glPopMatrix();
}*/

void esfera1(void){
	glColor3f(77.0 / 255.0, 131.0 / 255.0, 22.0 / 255.0);
	glPushMatrix();
	glScalef(.8, 1, 1);
	glutSolidSphere(.2, 40, 30);
	glPopMatrix();
}

void esfera2(void)
{
	glColor3f(77.0 / 255.0, 131.0 / 255.0, 22.0 / 255.0);
	glPushMatrix();
	glScalef(.9, 1, 1);
	glTranslatef(0, -.5, 0);
	glutSolidSphere(.4, 40, 30);
	glPopMatrix();
}

void tallo(void)
{
	glColor3f(128 / 255, 64 / 255, 0);
	glPushMatrix();
	glScalef(.2, 1, 1);
	glTranslatef(0, .3, 0);
	glutSolidSphere(.1, 40, 30);
	glPopMatrix();
}

void pera(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	esfera1();
	esfera2();
	tallo();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Iluminación");
	inicializa();
	glutDisplayFunc(pera);
	glutMainLoop();
	return 0;
}
