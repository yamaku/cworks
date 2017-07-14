#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[]) {
  double d;
  for(d=0.0;d<360;d+=1.0){
    printf("%.0lf\t%lf\n",d,sin(d*M_PI/180));
  }
  return 0;
}
