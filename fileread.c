#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *fp;
  int a,b;

  a = 0;
  b = 0;

  fp = fopen("test.txt","r");

  if(fp == NULL)
  {
    printf("ファイルを開けませんでした\n");
    exit(-1);
  }

  fscanf(fp, "a = %d\n", &a);
  fscanf(fp, "b = %d\n", &b);

  fclose(fp);

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("a / b = %lf\n", (double)a/(double)b);

  return 0;
}
