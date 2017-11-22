
#include <GL/glut.h>

//---------- プロトタイプ宣言 ---------------------//
void display(void);
void reshape(int w, int h);
void timer(int value);
void DRAW_XYZ(void);
void DRAW_TRI(void);
//フォント
void *font = GLUT_BITMAP_HELVETICA_18;
void DrawString(const char *str,void *font,float x,float y,float z);


//------------- OpenGLの初期設定 ----------------//
void GLUT_INIT()
{
	glutInitDisplayMode(GLUT_RGBA| GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(300,300);
	glutCreateWindow("Bitmap Font");
}

void GLUT_CALL_FUNC()
{
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,17);
}

void MY_INIT()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);  //Zバッファ有効化
}


//------------ メイン関数 ---------------//
int main(int argc, char **argv)
{
	glutInit(&argc,argv);

	GLUT_INIT();
	GLUT_CALL_FUNC();
	MY_INIT();

	glutMainLoop();

	return 0;
}

//------------ ここからコールバック ---------------//
void display()
{
	static int r = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	DRAW_XYZ();  //XYZ軸の描画

	//ポリゴンの描画
	glPushMatrix();
	glRotated((double)r, 0.0, 1.0, 0.0);
	glTranslated(1,0,0);
	glColor3d(0,1,0);
	DRAW_TRI();
	glPopMatrix();


	glPushAttrib(GL_CURRENT_BIT|GL_DEPTH_BUFFER_BIT);  //色、Zバッファの退避
	glDisable(GL_DEPTH_TEST);
	glColor3d(1,0,1);
	DrawString("Hello Bitmap glut",font,0,0,0);
	glPopAttrib();//色、Zバッファを戻す


	glutSwapBuffers();

	if(++r > 360){
		r= 0;
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void timer(int t)
{
	glutPostRedisplay();
	glutTimerFunc(t,timer,17); //タイマー関数
}

//------------- ここから各種関数 ------------------//
void DRAW_XYZ()
{
	glBegin(GL_LINES);

	glColor3d(0,1,0);//x
	glVertex2d(-100,0);
	glVertex2d(100, 0);

	glColor3d(1,0,0);//y
	glVertex2d(0,0);
	glVertex2d(0,100);

	glColor3d(0,0,1);//z
	glVertex3d(0,0,-100);
	glVertex3d(0,0, 100);
	glEnd();

}

void DRAW_TRI()
{
	glBegin(GL_TRIANGLES);
	glVertex2d(0,1);
	glVertex2d(-0.5, 0);
	glVertex2d(0.5, 0);
	glEnd();
}

//---------- フォントの描画 ------------//
void DrawString(const char *str,void *font,float x,float y,float z)
{
	glRasterPos3f(x,y,z);
	while(*str){
		glutBitmapCharacter(font, *str);
		++str;
	}
}
