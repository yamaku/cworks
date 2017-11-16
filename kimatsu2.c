#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int b = 0, line = 0, c = '0';
  FILE *fp;
  fp = fopen("a.txt", "r");
  if(fp == NULL)
  {
    printf("file not found\n");
    return 0;
  }
  while(1)
  {
    c = fgetc(fp);
    if(c == EOF)
      break;
    else if(c == '\n')
      {
        line ++;
        continue;
      }
    else if(c == '\t')
      continue;
    b += sizeof(c);
  }
  fclose(fp);
  return 0;
}
