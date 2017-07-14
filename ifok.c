#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,c;
  a = 1;
  b = 0;
  c = 0;
  if(a == 0 && (b == 0 || c == 0)) printf("True\n");
  else printf("False\n");
  return 0;
}
