#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

void Display(void);
void Reshape(int,int);

int main(int argc, char **argv) {

  glutInit(&argc,argv);
  glutInitWindowSize(320,240);
  glutCreateWindow("BitMap");
  glutInitDisplayMode(GLUT_RGBA);
  glClearColor(0.0,1.0,1.0,0.0);
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);

  glutMainLoop();

  return 0;
}

void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  char s[20];
  int i,n,x=123;

  sprintf(s,"SCORE : %05d",x);

  n = strlen(s);

  glColor3ub(0,0,0);
  glRasterPos2i(10,10);

  for(i = 0;i<n;i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
  }

  glColor3ub(255,100,100);
  glRasterPos2i(9,9);

  for(i = 0;i<n;i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
  }

  //glColor3ub(1,0,0);
  //glRasterPos2i(100,100);
  //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'A');
  //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'B');
  //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'C');

  glFlush();
}

void Reshape(int w,int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0, h, 0, w);
  glScaled(1, -1, 1);
  glTranslated(0, -h, 0);
}
