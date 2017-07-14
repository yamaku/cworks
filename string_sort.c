#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int i,j;
  char s[10][100],tmp[100];

  strcpy(s[0],"‚í‚½‚È‚×");
  strcpy(s[1],"‚©‚Æ‚¤");
  strcpy(s[2],"‚â‚Ü‚à‚Æ");
  strcpy(s[3],"‚³‚Æ‚¤");
  strcpy(s[4], "‚·‚¸‚«");
  strcpy(s[5],"‚â‚Ü‚¾");
  strcpy(s[6],"‚±‚Î‚â‚µ");
  strcpy(s[7],"‚É‚µ‚¾");
  strcpy(s[8],"‚½‚È‚©");
  strcpy(s[9],"‚È‚©‚ª‚í");

  for(j=0;j<10;j++){
    for(i=0;i<9;i++){
      if(strcmp(s[i],s[i+1]) > 0){
        strcpy(tmp,s[i]);
        strcpy(s[i],s[i+1]);
        strcpy(s[i+1],tmp);
      }
    }
  }
  for(i=0;i<10;i++){
    printf("%s\n",s[i]);
  }


  return 0;
}
