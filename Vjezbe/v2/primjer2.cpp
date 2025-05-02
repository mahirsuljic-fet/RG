#include <GL/glut.h>

 GLenum shadingModel = GL_FLAT;
//GLenum shadingModel = GL_SMOOTH;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glShadeModel(shadingModel);

  glBegin(GL_QUADS);
  // glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(0.5, 0.5);
  glVertex2f(0.5, -0.5);
  glColor3f(0.0, 1.0, 0.0);
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
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("Shade model");

  init();

  glutDisplayFunc(display);

  glutMainLoop();
  return 0;
}
