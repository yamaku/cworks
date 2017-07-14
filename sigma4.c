#include <stdio.h>

int main(int argc, char const *argv[]) {
  long n,i;
  n = 1;
  for(i=0;i<99999;i++){
    n += 3;
  }
  printf("%ld\n",n);
  return 0;
}
