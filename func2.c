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
  printf("‚Æ‚à‚â‚ñ‚Ì‹­‚³\n");
  printf("UŒ‚—Í:");
  graph(15);

  printf("–hŒä—Í:");
  graph(12);

  printf("‘f‘‚³:");
  graph(19);

  return 0;
}
