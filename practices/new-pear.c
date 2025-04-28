#include <GL/glut.h>

void inicializa(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0); // Color de fondo RGBA (A no interesa por ahora)
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0); // Cámara
	glMatrixMode(GL_PROJECTION);		  // Para el tipo de matriz a usar: Proyección
	gluPerspective(35, 1, 1, 20);
}

void esfera1(void)
{
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

void ilumina2(void)
{
	GLfloat positionAndType[] = {6, 6, 6, 2};
	GLfloat environmentColor[] = {0, 0, 0, 0};
	GLfloat difuseColor[] = {0, .9, 0};
	GLfloat direction[] = {0, 0, 1};

	glLightfv(GL_LIGHT0, GL_POSITION, positionAndType);
	glLightfv(GL_LIGHT0, GL_AMBIENT, environmentColor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, difuseColor);

	// Atenuación
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, -.2);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);

	// Direcciones
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 20.0);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
}

void desactiva_luz(void)
{
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
}

void material(void){
	GLfloat amb1[] = {0.23125, 0.23125, 0.23125, 1.0};
	GLfloat amb2[] = {0.773911, 0.773911, 0.773911, 1.0};
	GLfloat amb3[] = {0.2775, 0.2775, 0.2775, 1.0};

	glMaterialfv(GL_FRONT, GL_AMBIENT, amb1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, amb2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, amb3);
	glMaterialf(GL_FRONT, GL_SHININESS, 89.6);

	glEnable(GL_COLOR_MATERIAL);
}

	/*
	Ilumina()
	GLfloat ColorAmbiente[] = {1.0, 0.0, 0.0, 0.0};
	*/
void pera(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	ilumina2();
	material();
	esfera1();
	esfera2();
	desactiva_luz();
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
