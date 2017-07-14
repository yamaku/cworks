#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a,b,c;
  double d;
  printf("何月生まれですか？\n");
  scanf("%d",&a);
  printf("何日生まれですか？\n");
  scanf("%d",&b);
  printf("1年後期期末の順位は？\n");
  scanf("%d",&c );
  d = (double)(c - 1)/40.0*100.0;
  printf("あなたの今日の幸せ度は%3.0f%%です。\n",d);

  return 0;
}
