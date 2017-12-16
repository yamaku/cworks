#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/glpng.h>

void Display(void);
void Reshape(int,int);
void Timer(int);
void PutSprite(int,int,int,pngInfo *);

GLuint img[5];
pngInfo info[5];
char map[10][18] = //マップデータ
{
	"EEEEEEEEEEEEEEEEEE",
	"EAAAACAAAAAAADAAAE",
	"EAABAACAAACAAAAAAE",
	"EAAACAAABACAAABAAE",
	"EAABAACAAAAABAABAE",
	"EAACAABAAABACAACAE",
	"EAAAAACAAABAAABAAE",
	"EAAAABAAAACABAAAAE",
	"EAAAACADAABAAACAAE",
	"EEEEEEEEEEEEEEEEEE"
};
int k=0;

int main(int argc,char **argv)
{
	char fname[20];
	int i;

	srandom(12345);
	glutInit(&argc,argv);
	glutInitWindowSize(352,320);
	glutCreateWindow("PNGfile");
	glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA);
	glClearColor(0.0,0.0,1.0,1.0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

	for(i=1;i<6;i++) //画像の取り込み
	{
		sprintf(fname,"part%d.png",i);
		img[i] = pngBind(fname,PNG_NOMIPMAP,PNG_ALPHA,&info[i],GL_CLAMP,GL_NEAREST,GL_NEAREST);
	}

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutTimerFunc(1000,Timer,0);

	glutMainLoop();

	return 0;
}

void Timer(int value)
{
  glutPostRedisplay();
  glutTimerFunc(50,Timer,0);
	k--;
	if(k<=-800) k=-224;
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

void Display(void)
{
	int x=0,y=0,i,j;

	glClear(GL_COLOR_BUFFER_BIT);

	for(j=0;j<10;j++)
	{
		x=k;
		for(i=0;i<36;i++) //画像の描画（2回）
		{
			if(map[j][i%18]=='A') PutSprite(img[1],x,y,&info[1]);
			else if(map[j][i%18]=='B') PutSprite(img[2],x,y,&info[2]);
			else if(map[j][i%18]=='C') PutSprite(img[3],x,y,&info[3]);
			else if(map[j][i%18]=='D') PutSprite(img[4],x,y,&info[4]);
			else PutSprite(img[5],x,y,&info[5]);
			x+=32;
		}
		y+=32;
	}

	glFlush();
}

void PutSprite(int num,int x,int y,pngInfo *info)
{
	int w,h;

	w = info->Width;
	h = info->Height;

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,num);
	glColor4ub(255,255,255,255);

	glBegin(GL_QUADS);

	glTexCoord2i(0,0);
	glVertex2i(x,y);

	glTexCoord2i(0,1);
	glVertex2i(x,y+h);

	glTexCoord2i(1,1);
	glVertex2i(x+w,y+h);

	glTexCoord2i(1,0);
	glVertex2i(x+w,y);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
