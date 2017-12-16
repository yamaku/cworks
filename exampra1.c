#include <stdio.h>

struct exam
{
  char name[20];
  int score;
  char rank;
}

void rank_set(struct exam* a)
{
  if(a->score >= 80)
  {
    a->rank = 'A';
  }
  else if(a->score >= 70)
  {
    a->rank = 'B';
  }
  else if(a->score >= 60)
  {
    a->rank = 'C';
  }
  else
  {
    a->rank = 'D';
  }
}

int main(int argc, char **argv) {
  struct exam no1,exam* p1;
  p1 = &no1;

  scanf("%s",&(p1->name));
  scanf("%d",&(p1->score));
  rank_set(p1)

  return 0;
}
