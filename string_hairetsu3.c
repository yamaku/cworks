#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char s[10][11],tmp[11];
  int i;

  for(i = 0;i < 10;i++){
    sprintf(tmp,"No.%2d\n", i);
    strcpy(s[i],tmp);
  }
  for(i = 0;i < 10;i++){
    printf("%s", s[i]);
  }
  return 0;
}
