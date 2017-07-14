#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,c;
  a = 1;
  b = 0;
  c = 0;
  if(a == 0 && b == 0 || c == 0) printf("True\n");//a=0‚©‚ÂAb=0‚Ü‚½‚Íc=0‚Ì‚Æ‚«True
  else printf("False\n");                         //‚Æ•\¦‚µ‚½‚¢(a‚Í•K‚¸0)
  return 0;
}
