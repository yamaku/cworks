#include <stdio.h>

float getMax(float a, float b) {
/*  if(a >= b) {
    return a;
  } else {
    return b;
  } */
  retrun (a >= b) ? a : b;
}

void sayHi(void) {
  printf("Hi!\n");
}

int main(void) {
  float result;
  result = getMax(2.3, 5.2);
  printf("%f\n", result);
  sayHi();
  return 0;
}
