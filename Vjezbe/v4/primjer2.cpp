#include <GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

  glColor3f(0.5, 0.8, 1.0);
  glutSolidTeapot(1.0);

  glPushMatrix();
  glTranslatef(0.0, 0.0, -4.0);
  glColor3f(1.0, 0.5, 0.5);
  glutSolidCube(2.0);
  glPopMatrix();

  glPopMatrix();
  glFlush();
}

const int width = 700;
const int height = 700;

void init() {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-2, 2, -2, 2, 5, 15);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(700, 700);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("Depth");
  glEnable(GL_DEPTH_TEST);
  init();

  glutDisplayFunc(display);

  glutMainLoop();
  return 0;
}
