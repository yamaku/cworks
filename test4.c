#include <stdio.h>
#include <stdlib.h> //�w�b�_�̎��荞��
int main(int argc, char  *argv[]) {
  int i,a,b;
  i = 0;
  b = 0;
  srand(41);
  while(i<3)
  {
    a=(float)rand()/(RAND_MAX+1)*6+1;
    if(a == 6)
    {
      i++;
    }
    else
    {
      i=0;
    }
    b++;
  }
  printf("%d���ڂ�3���A��6���o�܂���\n",b);
  return 0;
}
