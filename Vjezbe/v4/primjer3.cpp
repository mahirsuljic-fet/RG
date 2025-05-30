#include <GL/glut.h>

GLdouble ex, ey, ez = 5;

void placeLight() {
  GLfloat light_position[] = {0.0, 0.0, 1.0, 1.0};
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
}

void init(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
}

void display(void) {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  gluLookAt(ex, ey, ez, 0.0, 0.0, 0.0, 0, 1, 0);
  placeLight();
  glutSolidTorus(0.275, 0.85, 8, 15);
  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLint)w, (GLint)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(ex, ey, ez, 0.0, 0.0, 0.0, 0, 1, 0);
  placeLight();
}

void specialKeys(int key, int x, int y) {
  int response = 0;
  switch (key) {
    case GLUT_KEY_UP:
      ey += 0.1;
      break;
    case GLUT_KEY_DOWN:
      ey -= 0.1;
      break;
    case GLUT_KEY_RIGHT:
      ex += 0.1;
      break;
    case GLUT_KEY_LEFT:
      ex -= 0.1;
      break;
  }
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Svjetlo");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutMainLoop();
  return 0;
}
