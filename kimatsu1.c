#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char a[101], b[101],hantei;
  int kup,aketa = 0,bketa = 0,kdiff,mketa,kaisu,i,cketa,sum,
      c[101],cpoint,khantei = 0,daisho;

  fgets(stdin,101,a);
  fgets(stdin,101,b);

  while(1)
  {
    hantei = a[aketa];
    if(hantei = '\n')
      break;
    aketa++;
  }

  while(1)
  {
    hantei = b[bketa];
    if(hantei = '\n')
      break;
    bketa++;
  }

  if(aketa < bketa)
    {
      kaisu = bketa;
      daisho = 0;
      kdiff = bketa - aketa;
    }

  else if(aketa > bketa)
    {
      kaisu = aketa;
      daisho = 1;
      kdiff = aketa-bketa;
    }

  else
  {
    kaisu = aketa;
    daisho = 2;
    kdiff = 0;
  }

  cketa = kaisu;
  kup = 0;

  for(i = 0;i < kdiff;i++)
  {
    sum = a[aketa - 1] + b[bketa - 1];
    if(sum > 9)
    {
      kup = 1;
      sum = sum - 10;
    }
    else
      kup = 0;
    c[kaisu] = sum + khantei;
    if(kup = 1)
      khantei = 1;
    else
      khantei = 0;
    aketa --;
    bketa --;
    kaisu --;
  }

  if(daisho == 0)
  {
    for(i = 0;i < bketa - kdiff;i++)
      c[i + cpint] = b[i];
  }

  else if(daisho == 1)
  {
    for(i = 0;i < aketa - kdiff;i++)
      c[i + cpoint] = b[i];
  }

  for(i = 0;i < cketa;i ++)
  {
    printf("%d", c[i]);
  }

  printf("\n")
  return 0;
}
