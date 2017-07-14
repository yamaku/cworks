#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int [], int);

int main(int argc, char const *argv[]) {

  int i,a[50];
  srand(41);

  for(i = 0;i < 50;i++){
    a[i] = rand();
    printf("%d\t", a[i]);
  }
  printf("\n\n");

  BubbleSort(a,sizeof(a)/4);

  for(i = 0;i < 50;i++){
    printf("%d\t", a[i]);
  }
  printf("\n");

  return 0;
}

void BubbleSort(int data[], int youso){

  int i,j,tmp,count = youso - 1;

  for(i = 0;i < youso;i++){
    for(j = 0;j < count;j++){
      if(data[j] > data[j + 1]){
        tmp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = tmp;
      }
    }
    count--;
  }

}
