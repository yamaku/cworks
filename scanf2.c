#include <stdio.h>

int main(int argc, char const *argv[]) {
  char s[50];

  printf("名前を入れてください\n");

  scanf("%s", s);

  printf("入力された名前は%sです\n", s);
  return 0;
}
