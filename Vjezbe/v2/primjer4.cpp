#include <GL/glut.h>
#include <iostream>

GLushort patterns[3] = {
    0x0101, /* dotted */
    0x00FF, /* dashed */
    0x1C47  /* dash/dot/dash */
};

int patternIndex = 0;
GLenum polygonMode = GL_LINE;
GLenum shadingModel = GL_FLAT;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glShadeModel(shadingModel);

  glColor3f(1.0, 1.0, 1.0);

  glEnable(GL_LINE_STIPPLE);
  glLineStipple(2, patterns[patternIndex]);

  glBegin(GL_LINE_LOOP);
  glVertex2f(0.75, 0.75);
  glVertex2f(0.75, -0.75);
  glVertex2f(-0.75, -0.75);
  glVertex2f(-0.75, 0.75);
  glEnd();

  glDisable(GL_LINE_STIPPLE);

  glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

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

void keyboard(unsigned char key, int x, int y) {
  std::cout << "keyboard callback" << std::endl;
  switch (key) {
    case 27:
      exit(0);
      break;
    case 'n':
    case 'N':
      patternIndex = (patternIndex + 1) % 3;
      break;
  }
  glutPostRedisplay();
}
/* da li mozemo optimizirati keyboard callback? */

void specialKeys(int key, int x, int y) {
  std::cout << "special keyboard callback" << std::endl;
  switch (key) {
  case GLUT_KEY_UP:
    patternIndex = (patternIndex + 1) % 3;
    break;
  }
  glutPostRedisplay();
}
/* da li mozemo optimizirati special keyboard callback? */

void motion(int x, int y) {
  std::cout << "motion: " << x << " " << y << std::endl;
}

void passiveMotion(int x, int y) {
  std::cout << "passive motion: " << x << " " << y << std::endl;
  float windowWidth = glutGet(GLUT_WINDOW_WIDTH);
  float windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

  /* skaliranje na opseg [-1,1] */
  float xCoordinate = x / (windowWidth / 2.0f) - 1.0f;
  float yCoordinate = -(y / (windowHeight / 2.0f) - 1.0f);

  std::cout << xCoordinate << " " << yCoordinate << std::endl;

  bool insideRectangle = xCoordinate > -0.5f && xCoordinate < 0.5f &&
                         yCoordinate < 0.5f && yCoordinate > -0.5f;

  polygonMode = insideRectangle ? GL_FILL : GL_LINE;

  glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
  std::cout << "mouse: " << x << " " << y << std::endl;

  if (button == GLUT_LEFT_BUTTON)
    shadingModel = state == GLUT_DOWN ? GL_SMOOTH : GL_FLAT;

  glutPostRedisplay();
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glLineWidth(2.0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 200);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Mouse & Keyboard");
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  init();

  glutDisplayFunc(display);

  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutPassiveMotionFunc(passiveMotion);

  glutKeyboardFunc(keyboard);
  glutSpecialFunc(specialKeys);

  glutMainLoop();
  return 0;
}
