#include <stdio.h>

int main(void){

  printf("[�W�������t�������^]\nsigned char�^:%zu�o�C�g\nint�^:%zu�o�C�g\n"
         "short�^:%zu�o�C�g\nlong�^:%zu�o�C�g\nlong long�^:%zu�o�C�g\n\n",sizeof(signed char),sizeof(int),sizeof(short),sizeof(long),sizeof(long long));

  printf("[�W�������Ȃ������^]\nunsigned char�^:%zu�o�C�g\nunsigned int�^:%zu�o�C�g\n"
         "unsigned short�^:%zu�o�C�g\nunsigned long�^:%zu�o�C�g\nunsigned long long�^:%zu�o�C�g\n\n",sizeof(unsigned char),sizeof(unsigned int),sizeof(unsigned short),sizeof(unsigned long),sizeof(unsigned long long));

  printf("[�����������_�^]\nfloat�^:%zu�o�C�g\ndouble�^:%zu�o�C�g\nlong double�^:%zu�o�C�g\n",sizeof(float),sizeof(double),sizeof(long double));

  return 0;
}
