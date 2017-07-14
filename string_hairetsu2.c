#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int i,j=1,length;
  char s[] = "yamada",t[strlen(s)];
  length = strlen(s);

  printf("%s\n", s);

  for(i = 0;i < length;i++,j++){
    t[i] = s[length-j];
  }
  t[length] = '\0';
  printf("%s\n", t);

  return 0;
}
