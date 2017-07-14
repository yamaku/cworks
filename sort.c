#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i,j,t,a[50];
  srand(41);
  for(i = 0;i < 50;i++){
    a[i] = rand();
    printf("%d\t",a[i]);
  }
  printf("\n\n");
  for(j=0;j<50;j++){
    for(i=0;i<49;i++){
      if(a[i]>a[i+1]){
        t = a[i+1];
        a[i+1] = a[i];
        a[i] = t;
      }
    }
  }
  for(i=0;i<50;i++){
    printf("%d\t",a[i]);
  }
  printf("\n");

  return 0;
}
