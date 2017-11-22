#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include<GL/glpng.h>

void Display(void);
void Reshape(int, int);
void Timer(int);
void PutSprite(int,int,int,int,int,pngInfo *);

GLuint img1,eye1,eye2;
pngInfo info1,info_eye1,info_eye2;
int count=0;

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(500,500);
  glutCreateWindow("clock");
  glClearColor(1.0, 1.0, 1.0, 0.0);

  glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

  img1 = pngBind("7375.png",PNG_NOMIPMAP,PNG_ALPHA,&info1,GL_CLAMP,GL_NEAREST,GL_NEAREST);
  eye1 = pngBind("eye1.png",PNG_NOMIPMAP,PNG_ALPHA,&info_eye1,GL_CLAMP,GL_NEAREST,GL_NEAREST);
  eye2 = pngBind("eye2.png",PNG_NOMIPMAP,PNG_ALPHA,&info_eye2,GL_CLAMP,GL_NEAREST,GL_NEAREST);

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_ALPHA);

  glutTimerFunc(100,Timer,0);

  glutMainLoop();

  return 0;
}
void Display(void)
{
  int h,m,s,i,width,height;
  char str[20];
  time_t tt;
  struct tm *ts;
  double rad_h,rad_m,rad_s,x=250,y=250;

  glClear(GL_COLOR_BUFFER_BIT);

  width = glutGet(GLUT_WINDOW_WIDTH);
	height = glutGet(GLUT_WINDOW_HEIGHT);

  PutSprite(img1,0,0,width,height,&info1);

  count++;

  if(count%50!=0)
  {
    PutSprite(eye1,120,180,70,70,&info_eye1);
    PutSprite(eye1,310,180,70,70,&info_eye1);
  }
  else
  {
    PutSprite(eye2,120,180,70,70,&info_eye2);
    PutSprite(eye2,310,180,70,70,&info_eye2);
  }

  time(&tt);
  ts = localtime(&tt);
  h = ts->tm_hour;
  m = ts->tm_min;
  s = ts->tm_sec;

  rad_s = 2 *M_PI * s / 60;
  rad_m = 2 * M_PI * (60 * m + s) / 3600;
  rad_h = 2 * M_PI * (3600 * h + 60 * m + s) / 43200;

  switch (ts->tm_wday) {
    case 0:
      sprintf(str,"%d.%01d.%01d Sun",ts->tm_year+1900,ts->tm_mon,ts->tm_mday);
      break;
    case 1:
      sprintf(str,"%d.%01d.%01d Mon",ts->tm_year+1900,ts->tm_mon,ts->tm_mday);
      break;
    case 2:
      sprintf(str,"%d.%01d.%01d Tue",ts->tm_year+1900,ts->tm_mon,ts->tm_mday);
      break;
    case 3:
      sprintf(str,"%d.%01d.%01d Wed",ts->tm_year+1900,ts->tm_mon,ts->tm_mday);
      break;
    case 4:
      sprintf(str,"%d.%01d.%01d Thu",ts->tm_year+1900,ts->tm_mon,ts->tm_mday);
      break;
    case 5:
      sprintf(str,"%d.%01d.%01d Fri",ts->tm_year+1900,ts->tm_mon,ts->tm_mday);
      break;
    case 6:
      sprintf(str,"%d.%01d.%01d Sat",ts->tm_year+1900,ts->tm_mon,ts->tm_mday);
      break;
  }

  glColor3ub(0,0,0);
  glRasterPos2i(170,280);

  for(i=0;i<11;i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
  }

  if(ts->tm_wday==6)
  {
    glColor3ub(0,0,255);
    glRasterPos2i(290,280);
    for(i=11;i<14;i++)
    {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    }
  }
  else if(ts->tm_wday==0)
  {
    glColor3ub(255,0,0);
    glRasterPos2i(290,280);
    for(i=11;i<14;i++)
    {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    }
  }
  else
  {
    for(i=11;i<14;i++)
    {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    }
  }



  glColor3d(180.0, 0.0, 0.0);
  glLineWidth(3);

  glBegin(GL_LINES);
  glVertex2d(x,y);
  glVertex2d(x + 200 * sin(rad_s),y - 200 * cos(rad_s));
  glEnd();

  glColor3d(0.0, 0.0, 0.0);
  glLineWidth(7);

  glBegin(GL_LINES);
  glVertex2d(x,y);
  glVertex2d(x + 200 * sin(rad_m),y - 200 * cos(rad_m));
  glEnd();

  glLineWidth(15);

  glBegin(GL_LINES);
  glVertex2d(x,y);
  glVertex2d(x + 150 * sin(rad_h),y - 150 * cos(rad_h));
  glEnd();

  glutSwapBuffers();
}

void Reshape(int w, int h)
{
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glScaled(1,-1,1);
  glTranslated(0,-h,0);
  //glutReshapeWindow(500,500);
}

void Timer(int value)
{
  glutPostRedisplay();
  glutTimerFunc(100,Timer,0);
}

void PutSprite(int num,int x,int y,int w,int h,pngInfo *info)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,num);
	glColor4ub(255,255,255,255);

	glBegin(GL_QUADS);

	glTexCoord2i(0,0);
	glVertex2i(x,y);

	glTexCoord2i(0,1);
	glVertex2i(x,h+y);

	glTexCoord2i(1,1);
	glVertex2i(x+w,y+h);

	glTexCoord2i(1,0);
	glVertex2i(x+w,y);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
