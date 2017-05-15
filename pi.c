#include <stdio.h>

int main(void){
  float pi = 3.1415; //円周率の定義
  float r = 3.0; //半径　= 3.0 とする

  printf("半径%fの円において,直径=%f,面積=%f\n",r,2.0*r*pi,r*r*pi);
  printf("半径%fの円において,直径=%f,面積=%f\n",r,2.0*r*pi,r*r*pi);
  printf("半径%fの円において,直径=%f,面積=%f\n",r,2.0*r*pi,r*r*pi);
  
  return 0;
}
