#include <GL/glut.h>
#include <unistd.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Color del fondo
	glMatrixMode(GL_MODELVIEW);
	// gluLookAt(-2, 0, 5, 0, 0, 0, 0, 1, 5);

	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 5);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(60, 1, 1, 12); // Perspectiva de la esfera
}

void Pinta3D(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	for (int i = 1; i <= 360; i++)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		glRotated(i, 1, 0, 0);
		glTranslated(2, 0, 0);
		glutWireCube(1.0);
		usleep(5000);
		glPopMatrix();
		glFlush();
	}
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