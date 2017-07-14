#include <stdio.h>
#include <stdlib.h> //ヘッダの取り込み
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
  printf("%d回目で3回連続6が出ました\n",b);
  return 0;
}
