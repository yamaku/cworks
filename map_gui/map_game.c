#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/glpng.h>

void Display(void);
void Reshape(int,int);
void Timer(int);
void PutSprite(int,int,int,pngInfo *);
void Mouse(int,int,int,int);
void Keyboard(unsigned char,int,int);
void MakeMap();

GLuint img[12],button[4],ex;
pngInfo info[12],binfo[4],einfo;
char map[100][100];
int size=10,px=0,py=32;
int count=0,p=0;


#define KABE 'E'
#define START 'J'
#define GOAL 'K'
#define TREASURE 'B'
#define BOMB 'C'
#define GRASS 'A'
#define WARP 'D'
#define HIGASHI 'F'
#define MINAMI 'G'
#define NISHI 'H'
#define KITA 'I'

int main(int argc,char **argv)
{
	char fname[20];
	int i;

	srandom(12345);
	glutInit(&argc,argv);
	glutInitWindowSize(320,360);
	glutCreateWindow("PNGfile");
	glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA);
	glClearColor(0.0,0.0,0.0,0.0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

	for(i=1;i<13;i++) //画像の取り込み
	{
		sprintf(fname,"part%1d.png",i);
		img[i] = pngBind(fname,PNG_NOMIPMAP,PNG_ALPHA,&info[i],GL_CLAMP,GL_NEAREST,GL_NEAREST);
	}

	for(i=1;i<4;i++)
	{
		sprintf(fname,"button%d.png",i);
		button[i] = pngBind(fname,PNG_NOMIPMAP,PNG_ALPHA,&binfo[i],GL_CLAMP,GL_NEAREST,GL_NEAREST);
	}

	ex = pngBind("exit.png",PNG_NOMIPMAP,PNG_ALPHA,&einfo,GL_CLAMP,GL_NEAREST,GL_NEAREST);

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutTimerFunc(500,Timer,0);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Keyboard);
	MakeMap();

	glutMainLoop();

	return 0;
}

void Timer(int value)
{
	count++;
  glutPostRedisplay();
  glutTimerFunc(500,Timer,0);
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
	int x=0,y=0,i,j,a;

	glClear(GL_COLOR_BUFFER_BIT);

	for(j=0;j<10;j++)
	{
		x=0;
		for(i=0;i<10;i++) //画像の描画（2回）
		{
			a=map[j][i];
			PutSprite(img[a-'A'+1],x,y,&info[a-'A'+1]);
			x+=32;
		}
		y+=32;
	}


	PutSprite(img[p%4+6],px,py,&info[p%4+6]);

	for(i=0;i<3;i++)
	{
		PutSprite(button[i+1],i*32+96+i*2,323,&binfo[i+1]);
	}

	PutSprite(ex,200,323,&einfo);

	glFlush();
}

void Mouse(int s,int b,int x,int y)
{
	if(s==GLUT_LEFT_BUTTON)
	{
		if(b==GLUT_UP)
		{
			if(y>323&&y<357)
			{
				if(x>96&&x<128) p++;
				else if(x>130&&x<162) p+=3;
				else if(x>164&&x<196)
				{
					switch (p%4)
					{
						case 0:
							if(px!=256&&map[py/32][(px+32)/32]!=KABE)px+=32;
							break;
						case 1:
							if(py!=256&&px!=0&&map[(py+32)/32][(px)/32]!=KABE)py+=32;
							break;
						case 2:
							if(px>32&&map[py/32][(px-32)/32]!=KABE)px-=32;
							break;
						case 3:
							if(py!=32&&map[(py-32)/32][(px)/32]!=KABE)py-=32;
							break;
					}
				}
			}
		}
	}
	glutPostRedisplay();
}

void Keyboard(unsigned char key,int x,int y)
{
	if(key=='q') exit(0);
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

void MakeMap()
{
	int a, b, c, d, e, f, g, h, i, j, k, l, m;

	srand((unsigned)time(NULL));

	for(i = 0; i < size; i++)
	{
			for(j = 0; j < size; j++)
			{
					if((i == 1) && (j == 0) )
					{
							map[i][j] = START;
					}
					else if((i == size - 2) && (j == size - 1) )
					{
							map[i][j] = GOAL;
					}
					else if((i == 0) || (i == size - 1) )
					{
							map[i][j] = KABE;
					}
					else if((j == 0) || (j == size - 1) )
					{
							map[i][j] = KABE;
					}
					else
					{
							map[i][j] = GRASS;
					}
			}
	}

	for(k = 0; k < 3; k++)
	{
			a = (rand() / (double)RAND_MAX * (size - 3) + 1);
			b = (rand() / (double)RAND_MAX * (size - 3) + 1);

			while((a == 1 && b == 1) || (map[a][b] == TREASURE))
			{
					a = (rand() / (double)RAND_MAX * (size - 3) + 1);
					b = (rand() / (double)RAND_MAX * (size - 3) + 1);
			}

			map[a][b] = TREASURE;
	}

	for(l = 0; l < size - 5; l++)
	{
			c = (rand() / (double)RAND_MAX * (size - 3) + 1);
			d = (rand() / (double)RAND_MAX * (size - 3) + 1);
			e = (rand() / (double)RAND_MAX * (size - 3) + 1);
			f = (rand() / (double)RAND_MAX * (size - 3) + 1);

			while((c == 1 && d == 1) || (c == size - 2 && d == size - 1) || (map[c][d] == TREASURE) || (map[c][d] == BOMB) || (map[c][d] == KABE))
			{
					c = (rand() / (double)RAND_MAX * (size - 3) + 1);
					d = (rand() / (double)RAND_MAX * (size - 3) + 1);
			}

			map[c][d] = BOMB;

			while((e == 1 && f == 1) || (e == size - 2 && f == size - 1) || (map[e][f] == TREASURE) || (map[e][f] == BOMB) || (map[e][f] == KABE))
			{
					e = (rand() / (double)RAND_MAX * (size - 3) + 1);
					f = (rand() / (double)RAND_MAX * (size - 3) + 1);
			}

			map[e][f] = KABE;
	}

	for(m = 0; m < 2; m++)
	{
			g = (rand() / (double)RAND_MAX * (size - 3) + 1);
			h = (rand() / (double)RAND_MAX * (size - 3) + 1);

			while((g == 1 && h == 1) || (e == size - 2 && f == size - 2) || (map[g][h] == TREASURE) || (map[g][h] == BOMB) || (map[g][h] == KABE) || (map[g][h] == WARP))
			{
					g = (rand() / (double)RAND_MAX * (size - 3) + 1);
					h = (rand() / (double)RAND_MAX * (size - 3) + 1);
			}

			map[g][h] = WARP;
	}
}
