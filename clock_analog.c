#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h> // Mac : <GLUT/glut.h>

void Display(void);
void Reshape(int, int);
void Timer(int);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(500,500);
  glutCreateWindow("clock");
  glClearColor(1.0, 1.0, 1.0, 0.0);

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutInitDisplayMode(GLUT_RGBA);

  glutTimerFunc(500,Timer,0);

  glutMainLoop();

  return 0;
}
void Display(void)
{
  int h,m,s;
  time_t tt;
  struct tm *ts;
  double rad_h,rad_m,rad_s,x=250,y=250;
  glClear(GL_COLOR_BUFFER_BIT);

  time(&tt);
  ts = localtime(&tt);
  h = ts->tm_hour;
  m = ts->tm_min;
  s = ts->tm_sec;

  rad_s = 2 *M_PI * s / 60;
  rad_m = 2 * M_PI * (60 * m + s) / 3600;
  rad_h = 2 * M_PI * (3600 * h + 60 * m + s) / 43200;

  glColor3d(0.0, 0.0, 0.0);
  glPointSize(5.0);

  glBegin(GL_LINES);
  glVertex2d(x,y);
  glVertex2d(x + 200 * sin(rad_s),y - 200 * cos(rad_s));
  glEnd();

  glBegin(GL_LINES);
  glVertex2d(x,y);
  glVertex2d(x + 180 * sin(rad_m),y - 180 * cos(rad_m));
  glEnd();

  glBegin(GL_LINES);
  glVertex2d(x,y);
  glVertex2d(x + 150 * sin(rad_h),y - 150 * cos(rad_h));
  glEnd();

  glFlush();
}

void Reshape(int w, int h)
{
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glScaled(1,-1,1);
  glTranslated(0,-h,0);
}

void Timer(int value)
{
  glutPostRedisplay();
  glutTimerFunc(500,Timer,0);
}
