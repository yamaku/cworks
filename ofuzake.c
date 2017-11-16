#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,c;
  double d;
  printf("�������܂��ł����H\n");
  scanf("%d",&a);
  printf("�������܂��ł����H\n");
  scanf("%d",&b);
  printf("1�N���������̏��ʂ́H\n");
  scanf("%d",&c );
  d = (double)(c - 1)/40.0*100.0;
  printf("���Ȃ��̍����̍K���x��%3.0f%%�ł��B\n",d);

  return 0;
}
