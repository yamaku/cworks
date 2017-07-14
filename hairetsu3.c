#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;
  int a[10];
  char c[10];
  double f[10];
  for(i  =0;i < 10;i++){
    printf("a[%d]=%p\n", i, &a[i]);
  }
  for(i = 0;i < 10;i++){
    printf("c[%d]=%p\n", i, &c[i]);
  }
  for(i = 0;i < 10;i++){
    printf("f[%d]=%p\n", i, &f[i]);
  }
  return 0;
}
