#include <stdio.h>

//void graph(int);

void graph(int x)
{
  int i;

  for(i = 0; i < x; i++)
  {
    printf("*");
  }
  printf("\n");

  return;
}

int main(int argc, char const *argv[])
{
  printf("�Ƃ������̋���\n");
  printf("�U����:");
  graph(15);

  printf("�h����:");
  graph(12);

  printf("�f����:");
  graph(19);

  return 0;
}
