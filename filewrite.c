#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *fp;
  int a,b;

  a = 235;
  b = 15;

  fp = fopen("test.txt","w");

  if(fp == NULL)
  {
    printf("ファイルを開けませんでした\n");
    exit(-1);
  }

  fprintf(fp, "a = %d\n", a);
  fprintf(fp, "b = %d\n", b);

  fclose(fp);

  return 0;
}
