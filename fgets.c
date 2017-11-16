#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char s[15];
  printf("�������͂��Ă�������\n");
  fgets(s,sizeof(s),stdin);
  printf("���͂��ꂽ����%d�ł�\n",atoi(s));
  return 0;
}
