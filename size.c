#include <stdio.h>

int main(void){

  printf("[標準符号付き整数型]\nsigned char型:%zuバイト\nint型:%zuバイト\n"
         "short型:%zuバイト\nlong型:%zuバイト\nlong long型:%zuバイト\n\n",sizeof(signed char),sizeof(int),sizeof(short),sizeof(long),sizeof(long long));

  printf("[標準符号なし整数型]\nunsigned char型:%zuバイト\nunsigned int型:%zuバイト\n"
         "unsigned short型:%zuバイト\nunsigned long型:%zuバイト\nunsigned long long型:%zuバイト\n\n",sizeof(unsigned char),sizeof(unsigned int),sizeof(unsigned short),sizeof(unsigned long),sizeof(unsigned long long));

  printf("[実浮動小数点型]\nfloat型:%zuバイト\ndouble型:%zuバイト\nlong double型:%zuバイト\n",sizeof(float),sizeof(double),sizeof(long double));

  return 0;
}
