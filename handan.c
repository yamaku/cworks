#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char a[10],b[10],c[10],d[10];
  int e,f,g,h;
  double i,j;
  printf("4月生まれである(はい＝9 いいえ=3)\n");
  fgets(a,15,stdin);
  printf("血液型はAB型である(はい＝9 いいえ=3)\n");
  fgets(b,15,stdin);
  printf("部屋を片付けてもすぐに散らかってしまう(はい＝9 いいえ=3)\n");
  fgets(c,15,stdin);
  printf("小テストは授業前の休み時間だけ勉強する(はい＝9 いいえ=3)\n");
  fgets(d,15,stdin);
  e = atoi(a);
  f = atoi(b);
  g = atoi(c);
  h = atoi(d);
  i = (double)(e + f + g + h - 12) / 24.0 * 100.0;
  printf("あなたの山田度は%f%%です\n",i );

  j = (e + f + g + h - 12) / 24 * 100;
  printf("%f\n",j); //キャストをしない場合


  return 0;
}
