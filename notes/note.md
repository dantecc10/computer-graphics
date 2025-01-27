Se pueden pintar líneas con glBegin(GL_LINES);

glVertex2i(10, 10);

glVectorx2i/100, 100;

Triángulos

glBegin(GL_TRIANGLES);

glShadeMode(GL_FLAT);

glLineWidth(4);

glBegin(GL_LINES);

glColor3f(1, 0, 0);

glVertex2i(100, 100);

glColor3f(0, 0, 1);

glVertex2i(200, 200);

glEnd();

glShadeMode(GL_SMOOTH);

glLineWidth(4);

glBegin(GL_LINES);

glColor3f(1, 0, 0);

glVertex2i(100, 100);

glColor3f(0, 0, 1);

glVertex2i(200, 200);

glEnd();

glBegin();

 p1:

p2:

p3:

p4;

glEnd();

glPolygonMode(GL_FRONT, GL_LINE);
