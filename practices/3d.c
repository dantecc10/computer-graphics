#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Color del fondo
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(-2, 0, 5, 0, 0, 0, 0, 1, 5);
	glMatrixMode(GL_PROJECTION);
	//gluPerspective(45, 1, 1, 12);
	//gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
	gluPerspective(45, 1, 1, 12);
}

void Pinta3D(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glutWireCube(1.0);
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