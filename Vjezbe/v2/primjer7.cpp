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
  //glLoadIdentity();
  glPushMatrix();
  drawCoordinates();
  glPopMatrix();
  glColor3f(1.0, 0.0, 0.0);
  glRotatef(2.0, 0.0, 0.0, 1.0);
  drawPolygon();

  glFlush();
}

void mouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON) glutPostRedisplay();
}

void init() {
  /* set coordinate system */
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-100.0, 100.0, -100.0, 100.0);

  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Rotacija");

  init();

  glutMouseFunc(mouse);
  glutDisplayFunc(display);

  glutMainLoop();
  return 0;
}
