#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,c;
  a = 1;
  b = 0;
  c = 0;
  if(a == 0 && b == 0 || c == 0) printf("True\n");//a=0かつ、b=0またはc=0のときTrue
  else printf("False\n");                         //と表示したい(aは必ず0)
  return 0;
}
