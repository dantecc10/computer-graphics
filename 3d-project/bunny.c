#include <GL/glut.h>

void inicializa(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0); // Color de fondo RGBA (A no interesa por ahora)
	glMatrixMode(GL_MODELVIEW);
	//gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0); // Cámara
	gluLookAt(4, 4, 9, 0, 0, 0, 0, 1, 0); // Cámara
	glMatrixMode(GL_PROJECTION);		  // Para el tipo de matriz a usar: Proyección
	gluPerspective(35, 1, 1, 20);
}

void middle_sphere(void)
{
	glColor3f(255 / 255.0, 0.0 / 255.0, 0.0 / 255.0);
	glPushMatrix();
	glScalef(1, 1, 1);
	glutSolidSphere(.2, 40, 30);
	glPopMatrix();
}

void bottom_sphere(void)
{
	glColor3f(77.0 / 255.0, 131.0 / 255.0, 22.0 / 255.0);
	glPushMatrix();
	glScalef(1, 1, 1);
	glTranslatef(0, -.5, 0);
	glutSolidSphere(.4, 40, 30);
	glPopMatrix();
}

void bottom_foot(int side)
{
	glColor3f(0 / 255.0, 255 / 255.0, 0.0 / 255.0);
	glPushMatrix();
	if (side == 0)
	{
		// Rotar 45 grados
		glRotatef(45, 0, 0, 1);
		glScalef(.4, .6, 1);
		glTranslatef(-1.7, -.4, 0);
		glutSolidSphere(.4, 40, 30);
	}
	else
	{
		glRotatef(-45, 0, 0, 1);
		glScalef(.4, .6, 1);
		glTranslatef(1.7, -.4, 0);
		glutSolidSphere(.4, 40, 30);
	}

	glPopMatrix();
}

void pera(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	bottom_sphere();
	middle_sphere();
	bottom_foot(0);
	bottom_foot(1);
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
