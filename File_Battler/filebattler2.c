#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int use_kougeki(int a,int b)
{
  int c;
  c = (a-b)/2;
  if(c <= 0)
  {
    c = 1;
  }
  return c;
}

int main(int argc, char const *argv[]) {
  int hhp[2],ehp[2],hatk[2],eatk[2],hdef[2],edef[2],b[3],i,j,hdeath = 0,edeath = 0,csum;
  char hname[2][20],ename[2][20],fname[20],c;
  FILE *fp;

  fgets(fname,20,stdin);
  for(i = 0;;i ++)
  {
    if(fname[i] == '\n')
    {
      fname[i] = '\0';
      break;
    }
  }
  fp = fopen(fname,"r");
  if(fp == NULL)
  {
    printf("ファイルを開けませんでした\n");
    exit(-1);
  }
  for(j = 0;j < 3;j++)
  {
    csum = 0;
    for(i = 0;i < 10;i++)
    {
      c = fgetc(fp);
      csum += c;
      if(c == EOF)
        break;
    }
    b[j] = csum / 10;
  }
  fclose(fp);
  hhp[0] = b[0] + 20;
  hatk[0] = b[1] + 20;
  hdef[0] = (b[2] + 20) / 10;
  strcpy(hname[0],fname);

  hhp[1] = (rand()%300) + 100;
  hatk[1] = (rand()%40) + 10;
  hdef[1] = (rand()%10) + 5;
  strcpy(hname[1],"hero2");

  ehp[0] = (rand()%300) + 100;
  eatk[0] = (rand()%40) + 10;
  edef[0] = (rand()%10) + 5;
  strcpy(ename[0],"enemy1");

  ehp[1] = (rand()%300) + 100;
  eatk[1] = (rand()%40) + 10;
  edef[1] = (rand()%10) + 5;
  strcpy(ename[1],"enemy2");

  while(1)
  {
    if(hdeath >= 2)
    {
      printf("負けてしまった\n");
      break;
    }

    if(edeath >= 2)
    {
      printf("負けてしまった\n");
    }

    for(i = 0;i < 2;i++)
    {
      if(hhp[i] <= 0)
        continue;
      if(ehp[0] > 0)
      {
        ehp[0] -= use_kougeki(hatk[i],edef[0]);
        printf("hero%dの攻撃：%sに%dのダメージ！\n",i+1,ename[0],use_kougeki(hatk[i],edef[0]));
        if(ehp[0] <= 0)
        {
          printf("%sは倒れた\n", ename[0]);
          edeath++;
        }
      }
      else if(ehp[1] > 0)
      {
        ehp[1] -= use_kougeki(hatk[i],edef[1]);
        printf("hero%dの攻撃：%sに%dのダメージ！\n",i+1,ename[1],use_kougeki(hatk[i],edef[1]));
        if(ehp[1] <= 0)
        {
          printf("%sは倒れた\n", ename[1]);
          edeath++;
        }
      }
      else  continue;
      usleep(1000000);
    }

    for(i = 0;i < 2;i++)
    {
      if(ehp[i] <= 0)
        continue;
      if(hhp[0] > 0)
      {
        hhp[0] -= use_kougeki(eatk[i],hdef[0]);
        printf("enemy%dの攻撃：%sに%dのダメージ！\n",i+1,hname[0],use_kougeki(eatk[i],hdef[0]));
        if(hhp[0] <= 0)
        {
          printf("%sは倒れた\n", hname[0]);
          hdeath++;
        }
      }
      else if(hhp[1] > 0)
      {
        hhp[1] -= use_kougeki(eatk[i],hdef[1]);
        printf("enemy%dの攻撃：%sに%dのダメージ！\n",i+1,hname[1],use_kougeki(eatk[i],hdef[1]));
        if(hhp[1] <= 0)
        {
          printf("%sは倒れた\n", hname[1]);
          hdeath++;
        }
      }
      else
        continue;
      usleep(1000000);
    }
  }

  return 0;
}
