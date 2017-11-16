#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int i,j;
  char s[10][100],tmp[100];

  strcpy(s[0],"�킽�Ȃ�");
  strcpy(s[1],"���Ƃ�");
  strcpy(s[2],"���܂���");
  strcpy(s[3],"���Ƃ�");
  strcpy(s[4], "������");
  strcpy(s[5],"���܂�");
  strcpy(s[6],"���΂₵");
  strcpy(s[7],"�ɂ���");
  strcpy(s[8],"���Ȃ�");
  strcpy(s[9],"�Ȃ�����");

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
