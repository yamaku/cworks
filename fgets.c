#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char s[15];
  printf("”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
  fgets(s,sizeof(s),stdin);
  printf("“ü—Í‚³‚ê‚½”‚Í%d‚Å‚·\n",atoi(s));
  return 0;
}
