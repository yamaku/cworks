#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int i,j;
  char s[10][100],tmp[100];

  strcpy(s[0],"わたなべ");
  strcpy(s[1],"かとう");
  strcpy(s[2],"やまもと");
  strcpy(s[3],"さとう");
  strcpy(s[4], "すずき");
  strcpy(s[5],"やまだ");
  strcpy(s[6],"こばやし");
  strcpy(s[7],"にしだ");
  strcpy(s[8],"たなか");
  strcpy(s[9],"なかがわ");

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
