#include <stdio.h>
#include <math.h>
#include <GL/glut.h> // Mac : <GLUT/glut.h>

void Display(void);
void Reshape(int, int);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(500,500);
  glutCreateWindow("Sample 1");
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutInitDisplayMode(GLUT_RGBA);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glutMainLoop();
  return 0;
}
void Display(void)
{
  int i;
  double rad=4.39823,x=250.0,y=0.0;
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3d(1.0, 1.0, 0.0);
  glPointSize(10.0);
  glBegin(GL_LINE_LOOP);
  glVertex2d(x,y);
  for(i=0;i<5;i++)
  {
    glVertex2d(x+500*cos(rad),y-500*sin(rad));
    x += 500*cos(rad);
    y -= 500*sin(rad);
    rad += 2.51327;
  }
  glEnd();

  glFlush();
}

void Reshape(int w, int h)
{
  printf("Windowの幅%d, 高さ%d\n",w,h);
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glScaled(1,-1,1);
  glTranslated(0,-h,0);
}
