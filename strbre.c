#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  char s[100];
  strcpy(s, "¡‚Í‰J‚ª~‚è‚Ü‚·");
  printf("%s\n", s);
  printf("%c\n", s[5]);

  return 0;
}
