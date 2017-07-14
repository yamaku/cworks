#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a[10];
  printf("a=%p\n", a);
  printf("a[-1]=%d\n", a[-1]);
  printf("&a[-1]=%p\n", &a[-1]);
  a[10] = 100;
  printf("a[10]=%d\n", a[10]);
  printf("&a[10]=%p\n", &a[10]);
  return 0;
}
