#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char s[15];
  printf("数を入力してください\n");
  fgets(s,sizeof(s),stdin);
  printf("入力された数は%dです\n",atoi(s));
  return 0;
}
