#include <stdio.h>

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
  printf("%d‰ñ–Ú‚Å3‰ñ˜A‘±6‚ªo‚Ü‚µ‚½\n",b);
  return 0;
}
