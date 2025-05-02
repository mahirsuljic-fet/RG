#include <GL/glut.h>

void drawTriangle() {
  glBegin(GL_TRIANGLES);
  glVertex2f(-50.0, 25.0);
  glVertex2f(50.0, -25.0);
  glVertex2f(-50.0, -75.0);
  glEnd();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 1.0);

  /* left viewport */
  glViewport(0, 0, 300, 300);
  drawTriangle();

  glColor3f(1.0, 0.0, 0.0);

  /* right viewport */
  glViewport(300, 0, 300, 300);
  drawTriangle();

  glFlush();
}

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-100.0, 100.0, -100.0, 100.0);

  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(600, 300);
  glutCreateWindow("Split-screen primjer");

  init();

  glutDisplayFunc(display);

  glutMainLoop();
  return 0;
}
