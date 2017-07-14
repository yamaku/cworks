#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 5000,e=72,f=101,g=108,h=111,i=87,j=114,l=100,m=33;
  char b,n,o,p,q,r,s,u,v;
  double c = 2.718281828459045235360287471352;
  float d;

  b = (char)a;
  n = (char)e;
  o = (char)f;
  p = (char)g;
  q = (char)h;
  r = (char)i;
  s = (char)j;
  u = (char)l;
  v = (char)m;
  d = (float)c;

  printf("%c\n", b);
  printf("%c%c%c%c%c%c%c%c%c%c%c\n",n,o,p,p,q,r,q,s,p,u,v );
  printf("%f\n", d);


  return 0;
}
