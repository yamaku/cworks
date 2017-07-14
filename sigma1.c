#include <stdio.h>

int func(int);

int main(int argc, char const *argv[]) {
  int n,i;
  for(i=1;i<10;i++){
    n = func(i);
    printf("%d,",n );
  }
  printf("%d\n",func(i+1));
  return 0;
}

int func(int a){
  if(a == 1){
    return 1;
  }
  else{
    return func(a - 1) + 3;
  }
}
