#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Color del fondo
	glMatrixMode(GL_MODELVIEW);
	//gluLookAt(-2, 0, 5, 0, 0, 0, 0, 1, 5);

	gluLookAt(3, 2, 5, 0, 0, 0, 0, 1, 0); // Vista de la esfera
	//gluLookAt(0, 5, 10, 0, 0, 0, 0, 5, 0); // Vista del cono
	//gluLookAt(0, -15, .5, 0, 35, 0, 0, 1, 0); // Vista del cono


	glMatrixMode(GL_PROJECTION);
	//gluPerspective(45, 1, 1, 12);
	//gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
	//gluPerspective(20, 1, 5, 15); // Perspectiva del cono
	gluPerspective(45, 1, 1, 12); // Perspectiva de la esfera
}

void Pinta3D(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glutWireSphere(1.0, 30, 60); // Primitiva de la esfera
	//glutWireCone(1.0, 2.0, 30, 80); // Primitiva del cono
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