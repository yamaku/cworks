#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char a[] = "90";
  char b[] = "10.0";
  char c[] = "abc";
  int d,f;
  double e;
  d = atoi(a);
  e = atof(b);
  f = atoi(c);
  printf("%s,%s,%s\n",a,b,c);
  printf("%d,%lf,%d\n",d,e,f);
  return 0;
}
