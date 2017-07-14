#include <stdio.h>

int main(void){
  int i = 0;
  printf("%d\n", i);
  i++;
  main();
  return 0;
}
