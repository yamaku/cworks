#include <stdio.h>

long func(long);

int main(int argc, char const *argv[]) {
  printf("%ld\n",func(100000));
  return 0;
}

long func(long a){
  if(a == 1){
    return 1;
  }
  else{
    return func(a - 1) + 3;
  }
}
