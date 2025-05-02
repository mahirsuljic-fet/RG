#include <GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_LINE_LOOP);
  glVertex2f(0.75, 0.75);
  glVertex2f(0.75, -0.75);
  glVertex2f(-0.75, -0.75);
  glVertex2f(-0.75, 0.75);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 1.0);
  glVertex2f(0.5, 0.5);
  glVertex2f(0.5, -0.5);
  glColor3f(0.0, 0.5, 0.5);
  glVertex2f(-0.5, -0.5);
  glVertex2f(-0.5, 0.5);
  glEnd();

  glFlush();
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glLineWidth(2.0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 200);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Primjer 1");
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  init();

  glutDisplayFunc(display);

  glutMainLoop();
  return 0;
}
