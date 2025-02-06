// DAnte Castelán Carpinteyro

#include <GL/glut.h>
#include <math.h>
void inicializa(void)
{
    glClearColor(.5490, .8, .9372, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 800);
}

void drawCircle(float cx, float cy, float radius, float color1, float color2, float color3)
{
    // glClear(GL_COLOR_BUFFER_BIT);

    // Establecer el color de relleno
    glColor3f(color1, color2, color3);

    // Definir el número de pasos para dibujar el círculo
    int steps = 500;
    double step = 2 * M_PI / steps; // Incremento angular
    double theta, x, y;

    glPointSize(4);

    // Dibujar el círculo como un polígono
    glBegin(GL_POLYGON);
    for (int i = 0; i <= steps; i++)
    {
        theta = i * step;             // Ángulo actual
        x = cx + radius * cos(theta); // Coordenada x del punto
        y = cy + radius * sin(theta); // Coordenada y del punto

        glVertex2f(x, y); // Añadir el punto al polígono
    }
    glEnd();

    glFlush();
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

void skull()
{
    // Cráneo (muerte)
    // glColor3f(.6745, .6392, .5215);
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(190, 600);
    glVertex2i(175, 570);
    glVertex2i(175, 540);
    glVertex2i(190, 510);

    glVertex2i(255, 510);
    glVertex2i(270, 540);

    glVertex2i(270, 570);
    glVertex2i(255, 600);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(190, 510);
    glVertex2i(190, 485);
    glVertex2i(198, 485);
    glVertex2i(198, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(209, 510);
    glVertex2i(209, 485);
    glVertex2i(217, 485);
    glVertex2i(217, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(228, 510);
    glVertex2i(228, 485);
    glVertex2i(236, 485);
    glVertex2i(236, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(247, 510);
    glVertex2i(247, 485);
    glVertex2i(255, 485);
    glVertex2i(255, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(255, 480);
    glVertex2i(250, 465);
    glVertex2i(195, 465);
    glVertex2i(190, 480);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(217, 545);
    glVertex2i(223, 525);
    glVertex2i(229, 545);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(190, 575);
    glVertex2i(190, 545);
    glVertex2i(210, 545);
    glVertex2i(210, 575);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(235, 575);
    glVertex2i(235, 545);
    glVertex2i(255, 545);
    glVertex2i(255, 575);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(265, 565);
    glVertex2i(265, 545);
    glVertex2i(300, 575);
    glVertex2i(300, 595);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(300, 625);
    glVertex2i(300, 575);
    glVertex2i(290, 575);
    glVertex2i(290, 625);
    glEnd();
}

void tree()
{
    // Cráneo (muerte)

    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2i(190, 600);
    glVertex2i(175, 570);
    glVertex2i(175, 540);
    glVertex2i(190, 510);

    glVertex2i(255, 510);
    glVertex2i(270, 540);

    glVertex2i(270, 570);
    glVertex2i(255, 600);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(190, 510);
    glVertex2i(190, 485);
    glVertex2i(198, 485);
    glVertex2i(198, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(209, 510);
    glVertex2i(209, 485);
    glVertex2i(217, 485);
    glVertex2i(217, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(228, 510);
    glVertex2i(228, 485);
    glVertex2i(236, 485);
    glVertex2i(236, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(247, 510);
    glVertex2i(247, 485);
    glVertex2i(255, 485);
    glVertex2i(255, 510);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(255, 480);
    glVertex2i(250, 465);
    glVertex2i(195, 465);
    glVertex2i(190, 480);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(217, 545);
    glVertex2i(223, 525);
    glVertex2i(229, 545);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(190, 575);
    glVertex2i(190, 545);
    glVertex2i(210, 545);
    glVertex2i(210, 575);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(235, 575);
    glVertex2i(235, 545);
    glVertex2i(255, 545);
    glVertex2i(255, 575);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(265, 565);
    glVertex2i(265, 545);
    glVertex2i(300, 575);
    glVertex2i(300, 595);
    glEnd();

    glColor3f(.4039, .2196, .0980);
    glBegin(GL_POLYGON);
    glVertex2i(300, 625);
    glVertex2i(300, 575);
    glVertex2i(310, 575);
    glVertex2i(310, 625);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(335, 565);
    glVertex2i(335, 545);
    glVertex2i(300, 575);
    glVertex2i(300, 595);
    glEnd();

    drawCircle(380, 535, 40, 0, .1647, .0352);
    drawCircle(380, 565, 40, 0, .1647, .0352);

    drawCircle(335, 555, 20, 0, .1647, .0352);
    drawCircle(345, 525, 20, 0, .1647, .0352);
    drawCircle(375, 495, 20, 0, .1647, .0352);
    drawCircle(400, 485, 20, 0, .1647, .0352);
    drawCircle(410, 540, 20, 0, .1647, .0352);
    drawCircle(410, 510, 20, 0, .1647, .0352);
}

void mount()
{
    glColor3f(.8196, .5098, .9960);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 400);
    glVertex2i(300, 600);
    glVertex2i(450, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(450, 400);
    glVertex2i(600, 600);
    glVertex2i(600, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(300, 400);
    glVertex2i(450, 600);
    glVertex2i(600, 400);
    glEnd();

    glColor3f(.2666, .2746, .3019);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 400);
    glVertex2i(0, 600);
    glVertex2i(150, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(150, 400);
    glVertex2i(300, 600);
    glVertex2i(300, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(0, 400);
    glVertex2i(150, 600);
    glVertex2i(300, 400);
    glEnd();
}

void bote()
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex2i(350, 450);
    glVertex2i(550, 450);
    glVertex2i(525, 330);
    glVertex2i(375, 330);
    glEnd();

    // Bambú (recipiente reciclado de bambú)
    glColor3f(.6509, .8901, .1294);
    glBegin(GL_POLYGON);
    glVertex2i(440, 430);
    glVertex2i(460, 430);
    glVertex2i(460, 350);
    glVertex2i(440, 350);
    glEnd();

    glColor3f(0, .5176, .0627);
    glBegin(GL_POLYGON);
    glVertex2i(430, 430);
    glVertex2i(470, 430);
    glVertex2i(470, 420);
    glVertex2i(430, 420);
    glEnd();

    glColor3f(0, .5176, .0627);
    glBegin(GL_POLYGON);
    glVertex2i(435, 390);
    glVertex2i(465, 390);
    glVertex2i(465, 380);
    glVertex2i(435, 380);
    glEnd();

    glColor3f(0, .5176, .0627);
    glBegin(GL_POLYGON);
    glVertex2i(435, 350);
    glVertex2i(465, 350);
    glVertex2i(465, 340);
    glVertex2i(435, 340);
    glEnd();
}

void bottle()
{
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 270);
    glVertex2i(160, 270);
    glVertex2i(160, 260);
    glVertex2i(140, 260);
    glEnd();
    
    glColor3f(.4, .7568, .7764);
    glBegin(GL_POLYGON);
    glVertex2i(140, 260);
    glVertex2i(130, 240);
    glVertex2i(130, 190);
    glVertex2i(135, 180);

    glVertex2i(165, 180);
    glVertex2i(170, 190);
    glVertex2i(170, 240);
    glVertex2i(160, 260);
    

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

    mount();

    bote();

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

    skull();

    tree();

    bottle();

    drawCircle(600, 800, 100, 1, .6588, .0313);
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
