#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char a[10];
  char b[10];
  int c,d;
  char e[] = "quit";

  while(0){
    scanf("%s\n",&a );
    scanf("%s\n",&b );

    if(strcmp(a,e)==0||strcmp(b,e)==0){
      break;
    }
    if (strlen(a)>5||strlen(b)>5) {
      printf("桁数が大きすぎます\n");
      continue;
    }
    if(d == 0){
      printf("0では割れません\n");
      continue;
    }
    c = atoi(a);
    d = atoi(b);
    printf("商=%d,余り=%d\n",a/b,a%b);
    printf("%d÷%d=%.2f",c,d,(float)c/d);
  }
  return 0;
}
