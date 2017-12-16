#include <stdio.h>
#include <GL/glut.h>

void Display(void);
void Reshape(int,int);
void Mouse(int,int,int,int);
void PassiveMotion(int,int);
void Motion(int,int);
void Entry(int);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(500,500);
  glutCreateWindow("clock");
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutInitDisplayMode(GLUT_RGBA);

  glutMouseFunc(Mouse);
  glutPassiveMotionFunc(PassiveMotion);
  glutMotionFunc(Motion);
  glutEntryFunc(Entry);

  //glutSetCursor(GLUT_CURSOR_INFO);

  glutMainLoop();

  return 0;
}

void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void Reshape(int w,int h)
{
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glScaled(1,-1,1);
  glTranslated(0,-h,0);
}

void Mouse(int b,int s,int x,int y)
{
  if(b == GLUT_LEFT_BUTTON)
  {
    if(s == GLUT_UP) printf("LEFT BUTTON UP\n");
    if(s == GLUT_DOWN) printf("LEFT BUTTON DOWN\n");
  }
  if(b == GLUT_MIDDLE_BUTTON)
  {
    if(s == GLUT_UP) printf("MIDDLE BUTTON UP\n");
    if(s == GLUT_DOWN) printf("MIDDLE BUTTON DOWN\n");
  }
  if(b == GLUT_RIGHT_BUTTON)
  {
    if(s == GLUT_UP) printf("RIGHT BUTTON UP\n");
    if(s == GLUT_DOWN) printf("RIGHT BUTTON DOWN\n");
  }

  printf(" at (%d,%d)\n",x,y);
}

void PassiveMotion(int x,int y)
{
  printf("PassiveMotion : (x,y)=(%d,%d)\n",x,y);
}

void Motion(int x,int y)
{
  printf("Motion : (x,y)=(%d,%d)\n",x,y);
}

void Entry(int s)
{
  if(s == GLUT_ENTERED) printf("Entered\n");
  if(s == GLUT_LEFT) printf("Left\n");
}
