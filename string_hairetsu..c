#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int i;
  char s[] = "Hello!";

  printf("%s\n", s);

  for(i = 0;i < strlen(s);i++){
    printf("%c", s[i]);
  }
  printf("\n");

  return 0;
}
