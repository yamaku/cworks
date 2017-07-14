#include <stdio.h>
#include <stdlib.h>
#include <string.h> //ƒwƒbƒ_‚Ìæ‚è‚İ
int main(int argc, char *argv[]) {
  char a[10];
  char b[10];
  int c,d;
  char e[] = "quit";

  while(1){ //0‚ğ1
    gets(a); //scanf‚ª‚æ‚­‚í‚©‚ç‚È‚¢‚Ì‚Ågets‚É‚µ‚Ü‚µ‚½
    gets(b);

    if(strcmp(a,e)==0||strcmp(b,e)==0){
      break;
    }
    if (strlen(a)>5||strlen(b)>5) {
      printf("Œ…”‚ª‘å‚«‚·‚¬‚Ü‚·\n");
      continue;
    }
    if(d == 0){
      printf("0‚Å‚ÍŠ„‚ê‚Ü‚¹‚ñ\n");
      continue;
    }
    c = atoi(a);
    d = atoi(b);
    printf("¤=%d,—]‚è=%d\n",c/d,c%d);
    printf("%d€%d=%.2f\n",c,d,(float)c/d); //\n‚ğ’Ç‰Á
  }
  return 0;
}
