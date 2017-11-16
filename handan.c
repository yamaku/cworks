#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char a[10],b[10],c[10],d[10];
  int e,f,g,h;
  double i,j;
  printf("4�����܂��ł���(�͂���9 ������=3)\n");
  fgets(a,15,stdin);
  printf("���t�^��AB�^�ł���(�͂���9 ������=3)\n");
  fgets(b,15,stdin);
  printf("�������Еt���Ă������ɎU�炩���Ă��܂�(�͂���9 ������=3)\n");
  fgets(c,15,stdin);
  printf("���e�X�g�͎��ƑO�̋x�ݎ��Ԃ����׋�����(�͂���9 ������=3)\n");
  fgets(d,15,stdin);
  e = atoi(a);
  f = atoi(b);
  g = atoi(c);
  h = atoi(d);
  i = (double)(e + f + g + h - 12) / 24.0 * 100.0;
  printf("���Ȃ��̎R�c�x��%f%%�ł�\n",i );

  j = (e + f + g + h - 12) / 24 * 100;
  printf("%f\n",j); //�L���X�g�����Ȃ��ꍇ


  return 0;
}
