#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp = NULL;
  double value, sum = 0;

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "failed to open %s\n", argv[1]);
    return 1;
  }

  while (fscanf(fp, "%lf", &value) == 1) {
    sum += value;
  }

  printf("%f\n", sum);
  return 0;
}
