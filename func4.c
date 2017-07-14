#include <stdio.h>

void test1(void);
void test2(void);

int g;

int main(int argc, char const *argv[]) {
  g = 514;

  printf("main g = %d\n", g);

  test1();
  test2();

  printf("main g = %d\n", g);

  return 0;
}

void test1(){
  printf("test1 g = %d\n", g);
  g = 611;
}

void test2(){
  printf("test2 g = %d\n", g);
  g = 1224;
}
