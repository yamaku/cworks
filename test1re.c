#include <stdio.h>
#include <stdlib.h>
#include <string.h> //�w�b�_�̎��荞��
int main(int argc, char *argv[]) {
  char a[10];
  char b[10];
  int c,d;
  char e[] = "quit";

  while(1){ //0��1
    gets(a); //scanf���悭�킩���Ȃ��̂�gets�ɂ��܂���
    gets(b);

    if(strcmp(a,e)==0||strcmp(b,e)==0){
      break;
    }
    if (strlen(a)>5||strlen(b)>5) {
      printf("�������傫�����܂�\n");
      continue;
    }
    if(d == 0){
      printf("0�ł͊����܂���\n");
      continue;
    }
    c = atoi(a);
    d = atoi(b);
    printf("��=%d,�]��=%d\n",c/d,c%d);
    printf("%d��%d=%.2f\n",c,d,(float)c/d); //\n���ǉ�
  }
  return 0;
}
