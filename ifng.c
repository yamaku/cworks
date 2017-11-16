#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,c;
  a = 1;
  b = 0;
  c = 0;
  if(a == 0 && b == 0 || c == 0) printf("True\n");//a=0���Ab=0�܂���c=0�̂Ƃ�True
  else printf("False\n");                         //�ƕ\��������(a�͕K��0)
  return 0;
}
