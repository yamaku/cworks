#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[]) {
  int i,j,a,b;
  long n;
  srand((unsigned)time(NULL));
  double x,y,pi;
  printf("���������闐��������\n" );
  scanf("%ld",&n);
  for(j=0;j<20;j++){
    a=0;
    b=0;
    for(i=0;i<n;i++){
      x = rand()/(double)RAND_MAX;
      y = rand()/(double)RAND_MAX;
      b++;
      if(x*x+y*y <= 1) a++;
      pi = 4.0 * (double)a / (double)b;
    }
    printf("%f\n",pi );
  }
  return 0;
}
