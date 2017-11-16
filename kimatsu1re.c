#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char a[101], b[101],hantei;
    int kup = 0,aketa = 0,bketa = 0,kdiff,kaisu,i,cketa,sum,
        c[101],khantei = 0,daisho;

    fgets(a,101,stdin); //引数の間違いを訂正
    fgets(b,101,stdin);

    while(1)
    {
        hantei = a[aketa];
        if(hantei == '\n') // = を ==
            break;
        aketa++;
    }

    while(1)
    {
        hantei = b[bketa];
        if(hantei == '\n') // = を ==
            break;
        bketa++;
    }

    if(aketa < bketa)
    {
        kaisu = aketa;
        daisho = 0;
        kdiff = bketa - aketa;
        cketa = bketa;
    }

    else if(aketa > bketa)
    {
        kaisu = bketa;
        daisho = 1;
        kdiff = aketa - bketa;
        cketa = aketa;
    }

    else
    {
        kaisu = aketa;
        daisho = 2;
        kdiff = 0;
        if((a[0] - '0') + (b[0] - '0') > 9)
        {
          kdiff ++;
          cketa = aketa + 1;
        }
        else
          cketa = aketa;
    }

    for(;kaisu != 0;kaisu--) // kdiff を kaisu
    {
        sum = (a[aketa - 1] - '0') + (b[bketa - 1] - '0');
        if(sum > 9)
        {
            kup = 1;
            sum = sum - 10;
        }
        else
            kup = 0;
        c[kaisu + kdiff - 1] = sum + khantei;
        if(kup == 1) // = を ==
            khantei = 1;
        else
            khantei = 0;
        aketa--;
        bketa--;
    }

    if(daisho == 0)
    {
        for(i = 0; i < kdiff; i++)
        {
            c[i] = b[i] - '0';
          }
            if(khantei == 1)
            {
              c[kdiff - 1] = (b[kdiff - 1] - '0') + 1;
            }
    }

    else if(daisho == 1)
    {
      for(i = 0; i < kdiff; i++)
      {
          c[i] = a[i] - '0';
        }
      if(khantei == 1)
      {
        c[kdiff - 1] = (a[kdiff - 1] - '0') + 1;
      }
    }

    else if(daisho == 2 && khantei == 1)
    {
      c[0] = khantei;
    }

    for(i = 0; i < cketa; i++)
    {
        printf("%d", c[i]);
    }

    printf("\n");
    return 0;
}
