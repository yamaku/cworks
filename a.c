#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char a[50];
  int count = 1,vector = 1,i,j = 1,k = 0;
  fgets(a,10,stdin);
  for(i = 0;i < 10;i++)
  {
		if(a[i] == 'R')
		{
			count++;
			vector = count%4;
		}
		else if(a[i] == 'F')
		{
			switch (vector) {
				case 1:
					k++;
          break;
				case 2:
					j++;
          break;
				case 3:
					k--;
          break;
				case 0:
					j--;
          break;
			}
		}
    printf("vector = %d\n", vector);
    printf("%d,%d\n", j, k);
  }
  printf("\n");
  return 0;
}
