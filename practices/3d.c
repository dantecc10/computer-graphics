#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Color del fondo
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(-5, 5, 10, 0, 0, 0, 0, 1, 5);
	glMatrixMode(GL_PROJECTION);
	// gluPerspective(45, 1, 1, 12);
	// gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
	gluPerspective(18, 1, 1, 25);
}

void Pinta3D(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	// glutWireCube(1); // Original teacher code

	glutWireSphere(1, 90, 90);

	double size = 1.0;
	while (size > 0.0)
	{
		glPushMatrix();
		glTranslatef(size, -size, -size);
		glColor3f(size, 1 - size, .2 + size);
		glutWireSphere(size, 30, 30);
		glPopMatrix();
		size -= .1;
	}
	while (size < 1.0)
	{
		glPushMatrix();
		glTranslatef(size, -size, -size);
		glColor3f(size, 1 - size, .2 + size);
		glutWireSphere(size, 30, 30);
		glPopMatrix();
		size += .1;
	}

	//glPushMatrix();
	//glTranslatef(.5, -.5, -.5);
	//glColor4f(1, 1, 1, 0.00001);
	//glutSolidSphere(1, 90, 90);
	//glPopMatrix();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Programa Básico en 3D");
	init();
	glutDisplayFunc(Pinta3D);
	glutMainLoop();
	return 0;
}

/*
OpenGL ofrece figuras en 3D como:
	glutWireCube
	glutWireSphere(GLdouble radio, GLint lados, GLint stacks);
	glutSolidSphere(GLdouble radio, GLint lados, GLint stacks);
	glutWireCone(GLdouble radio, GLdouble altura, GLint lados, GLint stacks);
	glutSolidCone(GLdouble radio, GLdouble altura, GLint lados, GLint stacks);
	glutWireTorus(GLdouble radioInterior, GLdouble radioExterior, GLint lados, GLint stacks);
	glutSolidTorus(GLdouble radioInterior, GLdouble radioExterior, GLint lados, GLint stacks);

	glutWireTeapot(GLdouble radioMáximo);
	glutSolidTeapot(GLdouble radioMáximo);
	glutWireDodecahedron
	glutWireIcosahedron
	glutWireOctahedron
	glutWireTetrahedron
*/