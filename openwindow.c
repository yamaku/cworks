#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void Display(void);
void Reshape(int,int);

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize(320,240);
  glutCreateWindow("sample 1");
  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  //glutFullScreen();

  glutInitDisplayMode(GLUT_RGBA);
  glClearColor(1.0,1.0,1.0,1.0);

  glutMainLoop();

  return 0;
}

void Display(void)
{
  time_t tt;
  struct tm *ts;
  int y,mon,d,you,h,min,sec;
  char youbi[3];

  //glutFullScreen();
  //glutPositionWindow(100,100);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
  time(&tt);
  ts = localtime(&tt);

  y = ts->tm_year;
  mon = ts->tm_mon;
  d = ts->tm_mday;
  you = ts->tm_wday;
  h = ts->tm_hour;
  min = ts->tm_min;
  sec = ts->tm_sec;

  if(you == 0) strcpy(youbi,"土");
  else if(you == 1) strcpy(youbi,"日");
  else if(you == 2) strcpy(youbi,"月");
  else if(you == 3) strcpy(youbi,"火");
  else if(you == 4) strcpy(youbi,"水");
  else if(you == 5) strcpy(youbi,"木");
  else strcpy(youbi,"金");

  printf("%d年%d月%d日（%s）%d時%d分%d秒\n", y+1900, mon+1, d, youbi, h, min, sec);

  glBegin(GL_POINTS);
  glColor3ub(0,0,0);
  glVertex2i(0,0);
  glVertex2i(320,240);
  glEnd();
  glFlush();
}

void Reshape(int w, int h)
{
  printf("ウィンドウの幅と高さ=%d x %d\n", w, h);
  glViewport(0, 0, w, h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0, h, 0, w);
  glScaled(1, -1, 1);
  glTranslated(0, -h, 0);
}
