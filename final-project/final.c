#include <GL/glut.h>
#include <math.h>
void inicializa(void)
{
    glClearColor(1, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 800);
}

void rabbit()
{
    // Cuello
    glColor3f(.6745, .6392, .5215);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(230, 155);
    glVertex2i(240, 190);
    glVertex2i(260, 200);
    glVertex2i(275, 205);

    glVertex2i(325, 205);
    glVertex2i(340, 200);
    glVertex2i(360, 190);
    glVertex2i(370, 155);

    glEnd();

    glColor3f(.7529, .7529, .7529);
    // Pata izquierda
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(200, 50);
    glVertex2i(180, 60);
    glVertex2i(185, 70);
    glVertex2i(205, 80);
    glVertex2i(230, 80);
    glVertex2i(250, 75);
    glVertex2i(270, 60);
    glVertex2i(265, 55);
    glVertex2i(260, 50);
    glEnd();

    // Pierna izquierda
    glColor3f(.5019, .4509, .3882);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(270, 60);
    glVertex2i(250, 75);
    glVertex2i(230, 80);
    glVertex2i(225, 90);
    glVertex2i(200, 100);
    glVertex2i(190, 105);
    glVertex2i(185, 125);
    glVertex2i(185, 140);
    glVertex2i(190, 145);
    glVertex2i(200, 150);
    glVertex2i(220, 155);
    glVertex2i(250, 155);
    glVertex2i(260, 140);
    glEnd();

    // Brazo izquierdo
    glColor3f(.3882, .4039, .3333);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(250, 155);
    glVertex2i(260, 140);
    glVertex2i(270, 60);
    glVertex2i(280, 65);
    glVertex2i(290, 60);
    glVertex2i(290, 160);
    glVertex2i(285, 175);
    glVertex2i(275, 180);
    glVertex2i(260, 180);
    glVertex2i(250, 175);
    glVertex2i(245, 170);
    glEnd();

    // Mano izquierda
    glColor3f(.7333, .74509, .8941);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(260, 50);
    glVertex2i(265, 55);
    glVertex2i(270, 60);
    glVertex2i(280, 65);
    glVertex2i(290, 60);
    glVertex2i(295, 55);
    glVertex2i(298, 50);
    glEnd();

    glColor3f(.7529, .7529, .7529);
    // Pata derecha
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(400, 50);
    glVertex2i(420, 60);
    glVertex2i(415, 70);
    glVertex2i(395, 80);
    glVertex2i(370, 80);
    glVertex2i(350, 75);
    glVertex2i(330, 60);
    glVertex2i(335, 55);
    glVertex2i(340, 50);
    glEnd();

    // Pierna derecha
    glColor3f(.5019, .4509, .3882);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(330, 60);
    glVertex2i(350, 75);
    glVertex2i(370, 80);
    glVertex2i(375, 90);
    glVertex2i(400, 100);
    glVertex2i(410, 105);
    glVertex2i(415, 125);
    glVertex2i(415, 140);
    glVertex2i(410, 145);
    glVertex2i(400, 150);
    glVertex2i(380, 155);
    glVertex2i(350, 155);
    glVertex2i(340, 140);
    glEnd();

    // Brazo derecho
    glColor3f(.3882, .4039, .3333);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(350, 155);
    glVertex2i(340, 140);
    glVertex2i(330, 60);
    glVertex2i(320, 65);
    glVertex2i(310, 60);
    glVertex2i(310, 160);
    glVertex2i(315, 175);
    glVertex2i(325, 180);
    glVertex2i(340, 180);
    glVertex2i(350, 175);
    glVertex2i(355, 170);
    glEnd();

    // Mano izquierda
    glColor3f(.7333, .74509, .8941);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(340, 50);
    glVertex2i(335, 55);
    glVertex2i(330, 60);
    glVertex2i(320, 65);
    glVertex2i(310, 60);
    glVertex2i(305, 55);
    glVertex2i(302, 50);
    glEnd();

    // Vientre
    glColor3f(.7529, .7529, .7529);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);

    // glVertex2i(325, 180);

    glVertex2i(310, 180);
    glVertex2i(315, 175);
    glVertex2i(310, 160);
    glVertex2i(310, 60);
    glVertex2i(305, 55);
    glVertex2i(302, 50);

    glVertex2i(298, 50);
    glVertex2i(295, 55);
    glVertex2i(290, 60);
    glVertex2i(290, 160);
    glVertex2i(285, 175);
    glVertex2i(290, 180);
    glEnd();

    // Cabeza
    glColor3f(.5019, .4509, .3882);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    // glVertex2i(275, 205);
    // glVertex2i(325, 205);
    glVertex2i(260, 205);
    glVertex2i(240, 245);
    glVertex2i(240, 275);
    glVertex2i(255, 290);
    glVertex2i(270, 320);

    glVertex2i(280, 325); // Oreja
    glVertex2i(300, 330);
    glVertex2i(320, 325); // Oreja

    glVertex2i(330, 320);
    glVertex2i(345, 290);
    glVertex2i(360, 275);
    glVertex2i(360, 245);
    glVertex2i(340, 205);
    glEnd();

    // Cubrebocas
    glColor3f(1, 1, 1);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);

    glVertex2i(300, 215);
    glVertex2i(270, 215);
    glVertex2i(255, 245);
    glVertex2i(265, 275);
    glVertex2i(280, 285);
    glVertex2i(300, 290);

    // glVertex2i(320, 285);
    // glVertex2i(335, 275);
    // glVertex2i(345, 245);
    // glVertex2i(330, 215);
    glEnd();

    // Tirantes
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(265, 275);
    glVertex2i(262, 270);
    glVertex2i(240, 270);
    glVertex2i(240, 275);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(265, 225);
    glVertex2i(267, 220);
    glVertex2i(253, 220);
    glVertex2i(249, 225);
    glEnd();
    
    // Ojos
    glColor3f(1, 1, 1);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(267, 293);
    glVertex2i(270, 290);
    glVertex2i(275, 290);
    glVertex2i(290, 310);
    glVertex2i(287, 313);
    glVertex2i(282, 313);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(281, 298);
    glVertex2i(274, 298);
    glVertex2i(274, 305);
    glVertex2i(281, 305);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(333, 293);
    glVertex2i(330, 290);
    glVertex2i(325, 290);
    glVertex2i(310, 310);
    glVertex2i(313, 313);
    glVertex2i(318, 313);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(319, 298);
    glVertex2i(326, 298);
    glVertex2i(326, 305);
    glVertex2i(319, 305);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(300, 275);
    glVertex2i(310, 269);
    glVertex2i(330, 269);
    
    glVertex2i(330, 230);
    glVertex2i(300, 230);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2i(300, 230);
    glVertex2i(320, 230);
    glVertex2i(320, 215);
    glVertex2i(300, 215);
    glEnd();
    
    glColor3f(.6745, .4078, .5215);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 275);
    glVertex2i(315, 270);
    glVertex2i(300, 255);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 245);
    glVertex2i(320, 245);
    glVertex2i(300, 220);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(300, 247);
    glVertex2i(300, 230);
    glVertex2i(310, 230);
    glVertex2i(310, 247);
    glEnd();
    
    // Orejas
    glColor3f(0.3882, 0.4039, 0.3333);
    glBegin(GL_POLYGON);
    glVertex2i(280, 325);
    glVertex2i(270, 320);
    glVertex2i(220, 345);
    glVertex2i(205, 360);
    glVertex2i(205, 375);
    glVertex2i(220, 390);
    glVertex2i(240, 390);
    glVertex2i(250, 380);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2i(320, 325);
    glVertex2i(330, 320);
    glVertex2i(380, 345);
    glVertex2i(395, 360);
    glVertex2i(395, 375);
    glVertex2i(380, 390);
    glVertex2i(360, 390);
    glVertex2i(350, 380);
    glEnd();
}

void pinta(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // drawCircle(350, 400, 100, 100, 180, 360);

    // Césped
    glColor3f(.0627, .4862, .2549);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(300, 0);
    glVertex2i(600, 0);
    glVertex2i(600, 400);
    glVertex2i(300, 400);
    glEnd();
    
    // Tierra
    glColor3f(.8156, .6, .3490);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(300, 0);
    glVertex2i(300, 400);
    glVertex2i(0, 400);
    glEnd();

    rabbit();
    // Raya
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(302, 0);
    glVertex2i(302, 800);
    glVertex2i(298, 800);
    glVertex2i(298, 0);
    glEnd();

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInitWindowSize(600, 800);
    glutInit(&argc, argv);
    glutCreateWindow("Castelán Carpinteyro Dante - ProyectoFinal.c");
    glutInitWindowPosition(500, 500);

    inicializa();
    glutDisplayFunc(pinta);
    glutMainLoop();
    return 0;
}
