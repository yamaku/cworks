#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a, b;

  printf("数をいれてください\n");

  scanf("%d %d", &a, &b);

  printf("入力された数は%d,%dです\n", a, b);


  return 0;
}
