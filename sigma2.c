#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n,i;
  n = 1;
  for(i=0;i<10;i++){
    printf("%d,",n);
    n += 3;  
  }
  printf("%d\n",n);
  return 0;
}
