#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  char s[] = "abc"; //変数の定義、文字列の代入
  char t[] = "abcdefg";
  char u[] = "123";
  char v[] = "1234567";
  char w[] = "あいう";
  char x[] = "あいうえお";
  char y[] = "松竹梅";
  char z[] = "風林火山";

  int a,b,c,d,e,f,g,h,i,j,k; //文字列の比較
  a = strcmp(s,t);
  b = strcmp(t,s);
  c = strcmp(u,v);
  d = strcmp(v,u);
  e = strcmp(w,x);
  f = strcmp(x,w);
  g = strcmp(y,z);
  h = strcmp(z,y);
  i = strcmp(s,u);
  j = strcmp(s,w);
  k = strcmp(w,y);

  printf("%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n%s,%s:%d\n"
  ,s,t,a,t,s,b,u,v,c,v,u,d,w,x,e,x,w,f,y,z,g,z,y,h,s,u,i,s,w,j,w,y,k);



  return 0;
}
