#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a[10][10];
  int i,j;

  for(i = 0;i < 10;i++){
    for(j = 0;j < 10;j++){
      printf("a[%d][%d]�̃A�h���X��%p\n", j, i, &a[j][i]);
    }
  }

  return 0;
}
