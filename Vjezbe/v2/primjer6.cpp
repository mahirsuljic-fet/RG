#include <GL/glut.h>

void drawCoordinates() {
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_LINES);

  /* x */
  glVertex2f(-100.0, 0.0);
  glVertex2f(100.0, 0.0);

  /* y */
  glVertex2f(0.0, -100.0);
  glVertex2f(0.0, 100.0);

  glEnd();
}

void drawPolygon() {
  glBegin(GL_POLYGON);
  glVertex2f(0.0, 0.0);
  glVertex2f(25.0, 0.0);
  glVertex2f(25.0, 25.0);
  glVertex2f(0.0, 25.0);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  drawCoordinates();

  glPushMatrix();
  glTranslatef(0.0, 50.0, 0.0);  // red polygon
  glColor3f(1.0, 0.0, 0.0);
  drawPolygon();
  glPopMatrix();

  glTranslatef(50.0, 0.0, 0.0);  // green polygon
  glColor3f(0.0, 1.0, 0.0);
  drawPolygon();

  glFlush();
}

void init() {
  /* set coordinate system */
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(300, 300);
  glutCreateWindow("Translacija 2");

  init();

  glutDisplayFunc(display);

  glutMainLoop();
  return 0;
}
