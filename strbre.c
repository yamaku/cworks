#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  char s[100];
  strcpy(s, "今は雨が降ります");
  printf("%s\n", s);
  printf("%c\n", s[5]);

  return 0;
}
