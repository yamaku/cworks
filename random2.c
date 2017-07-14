#include <stdio.h>
#include <math.h>
double GaussLegendre(int n) {
    int i;
    double a = 1.0, b = 1.0 / sqrt(2.0), t = 1.0 / 4, p = 1.0, tmp = 0;
    double ret;
    for (i = 0; i < n; i++) {
      tmp = a;
      a = (tmp + b) / 2;
      b = sqrt(tmp * b);
      t = t - (p * (a - tmp) * (a - tmp));
      p = 2 * p;  }
      return (a + b) * (a + b) / (4 * t);}
int main(void){
  printf("%1.20f\n", GaussLegendre(1));
  printf("%1.20f\n", GaussLegendre(2));
  printf("%1.20f\n", GaussLegendre(3));
  printf("%1.20f\n", GaussLegendre(4));
  printf("%1.20f\n", GaussLegendre(5));
  return 0;}
