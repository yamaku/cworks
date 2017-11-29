#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct status
{
  int hp;
  int kougeki;
  int bougyo;
  int subayasa;
  char name[20];
  int seishi;
  int turn;
  int rank;
};
//struct status a[5];

void use_kougeki(struct status *a, struct status *b)
{
  int damage = 0;
  damage = (a->kougeki - b->bougyo) / 2;
  if(damage <= 0)
  {
    damage = 1;
  }
  b->hp = b->hp - damage;
  printf("%sの攻撃！%sに%dのダメージ！\n",a->name,b->name,damage);
  if(b->hp <= 0)
  {
    printf("%sは倒れた\n",b->name);
    b->hp = 0;
    b->seishi = 1;
  }
}

int main(int argc, char **argv)
{
  FILE *fp;
  int c,csum = 0,i,j,k,l,m,n = 0,o = 0,p = 0,q,r,b[3],mikata_num,enemy_num,
  tmp = 0,hatacker,eatacker,hescape = 0,eescape = 0;
  char fname[20],title[13] = "FILE BATTLER";
  srand(1);

  system("clear");

  printf("\x1b[31m");
	for(j = 0;j < 13;j++)
	{
		printf("%c", title[j]);
		fflush(stdout);
		usleep(100000);
	}
  printf("\x1b[39m");
  printf("\n");

  system("clear");
  printf("\x1b[39m");
  printf("味方の数(0~9)を入力してください:");
  fflush(stdin);
  scanf("%d",&mikata_num);

  printf("敵の数(1~9)を入力してください:");
  fflush(stdin);
  scanf("%d",&enemy_num);

  struct status hero[mikata_num + 1],enemy[enemy_num],*h = hero,*e = enemy;
  int tmp2[mikata_num + 1],tmp3[enemy_num];

  for(i = 0;i < mikata_num + 1;i++)
  {
    tmp2[i] = i;
    sprintf((h+i)->name,"hero%d",i);
  }

  for(i = 0;i < enemy_num;i++)
  {
    tmp3[i] = i;
    sprintf((e+i)->name,"enemy%d",i);
  }

  fgetc(stdin);
  printf("ファイル名を入力してください：");
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
  for(j = 0;j < 4;j++)
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
  h->hp = b[0] + 220;
  h->kougeki = b[1] + 40;
  h->bougyo = (b[2] + 20) / 5;
  h->subayasa = b[3] + 20;
  strcpy(h->name,fname);
  h->seishi = 0;
  h->turn = 0;

  for(i = 1;i <= mikata_num;i++)
  {
    (h+i)->hp = (rand()%300) + 100;
    (h+i)->kougeki = (rand()%40) + 30;
    (h+i)->bougyo = (rand()%10) + 5;
    (h+i)->subayasa = (rand()%40) + 20;
    (h+i)->turn = 0;
    (h+i)->seishi = 0;
  }

  for(i = 0;i < enemy_num;i++)
  {
    (e+i)->hp = (rand()%300) + 100;
    (e+i)->kougeki = (rand()%40) + 30;
    (e+i)->bougyo = (rand()%10) + 5;
    (e+i)->subayasa = (rand()%40) + 20;
    (e+i)->turn = 0;
    (e+i)->seishi = 0;
  }
  //system("clear");
  for(j = 0;j < mikata_num+1;j++)
  {
    for(i = 0;i < mikata_num;i++)
    {
      if((h+tmp2[i])->subayasa < (h+tmp2[i+1])->subayasa)
      {
        tmp = tmp2[i + 1];
        tmp2[i + 1] = tmp2[i];
        tmp2[i] = tmp;
      }
    }
  }

  for(i = 0;i<mikata_num+1;i++)
  {
    printf("%d\n",tmp2[i]);
  }

  for(j = 0;j < enemy_num - 2;j++)
  {
    for(i = 0;i < enemy_num - 1;i++)
    {
      if((e+tmp3[i])->subayasa < (e+tmp3[i+1])->subayasa)
      {
        tmp = tmp3[i + 1];
        tmp3[i + 1] = tmp3[i];
        tmp3[i] = tmp;
      }
    }
  }

  for(i = 0;i < mikata_num + 1;i++)
  {
    (h+i)->rank = tmp2[i];
  }

  for(i = 0;i< enemy_num;i++)
  {
    (e+i)->rank = tmp3[i];
  }

  FILE *hfp;
  hfp = fopen("hstatus.txt","w");
  for(i=0;i<mikata_num+1;i++)
  {
    fprintf(fp, "%d %d %d %d %s %d %d %d\n",(h+i)->hp,(h+i)->kougeki,(h+i)->bougyo,(h+i)->subayasa,(h+i)->name,(h+i)->seishi,(h+i)->turn,(h+i)->rank);
  }
  fclose(hfp);

  while(1)
  {
    for(i = 0;i < mikata_num + 1;i++)
    {
      if((h+i)->hp > 0)
        break;
      else if(i != mikata_num)
        continue;
      return 0;
    }

    for(i = 0;i < enemy_num;i++)
    {
      if((e+i)->hp > 0)
        break;
      else if(i != enemy_num - 1)
        continue;
      return 0;
    }

    printf(".\n");
    usleep(2000000);
    system("clear");

    for(i = 0;i < mikata_num+1;i++)
    {
      printf("\x1b[42m");
      printf("%s HP:%d ",(h+i)->name,(h+i)->hp);
    }
    printf("\n");

    for(i = 0;i < enemy_num;i++)
    {
      printf("\x1b[41m");
      printf("%s HP:%d ",(e+i)->name,(e+i)->hp);
    }
    printf("\n");
    printf("\x1b[49m");

    for(q=0;q<mikata_num+1;q++)
    {
      if((h+q)->turn < p)
        break;
      else if(q != mikata_num)
        continue;
      else
      {
        for(r=0;r<enemy_num;r++)
        {
          if((e+r)->turn < p)
            break;
          else if(r != enemy_num-1)
            continue;
          else
          {
            p++;
          }
        }
      }
    }

    for(j = 0;j < mikata_num + 1;j++)
    {
      if((h+j)->rank == n%(mikata_num+1))
      {
        if((h+j)->turn >= p)
        {
          n++;
          if(j == mikata_num)
          {
            hescape = 1;
            break;
          }
          continue;
        }
        else
        {
          hatacker = j;
          hescape = 0;
          break;
        }
      }
    }

    for(k = 0;k < enemy_num;k++)
    {
      if((e+k)->rank == o%enemy_num)
      {
        if((e+k)->turn >= p)
        {
          o++;
          if(k == enemy_num - 1)
          {
            eescape = 1;
            break;
          }
          continue;
        }
        else
        {
          eatacker = k;
          eescape = 0;
          break;
        }
      }
    }

    if((hescape == 0) && (eescape == 1))
    {
      if((h+hatacker)->hp < 1)
      {
        (h+hatacker)->turn += 1;
        n++;
        continue;
      }
      printf("%sのターン：誰に攻撃する?\n",(h+hatacker)->name);
      for(l = 0;l < enemy_num;l++)
      {
        if((e+l)->seishi == 0)
        {
          printf("%d:%s ",l,(e+l)->name);
        }
      }
      printf("\n");
      scanf("%d",&tmp);
      fgetc(stdin);
      use_kougeki(&hero[hatacker],&enemy[tmp]);
      n++;
      (h+hatacker)->turn += 1;
      continue;
    }

    else if((hescape == 1) && (eescape != 1))
    {
      for(m = 0;m < mikata_num + 1;m++)
      {
        if((h+m)->seishi == 0);
          break;
      }
      if((e+eatacker)->hp < 1)
      {
        (e+eatacker)->turn += 1;
        o++;
        continue;
      }
      use_kougeki(&enemy[eatacker],&hero[m]);
      o++;
      (e+eatacker)->turn += 1;
      continue;
    }

    else if((hescape == 1) && (eescape == 1))
      continue;

    if((h+hatacker)->subayasa >= (e+eatacker)->subayasa)
    {
      if((h+hatacker)->hp < 1)
      {
        (h+hatacker)->turn += 1;
        n++;
        continue;
      }
      printf("%sのターン：誰に攻撃する?\n",(h+hatacker)->name);
      for(l = 0;l < enemy_num;l++)
      {
        if((e+l)->seishi == 0)
        {
          printf("%d:%s ",l,(e+l)->name);
        }
      }
      printf("\n");
      scanf("%d",&tmp);
      fgetc(stdin);
      use_kougeki(&hero[hatacker],&enemy[tmp]);
      n++;
      (h+hatacker)->turn += 1;
    }

    else
    {
      if((e+eatacker)->hp < 1)
      {
        (e+eatacker)->turn += 1;
        o++;
        continue;
      }
      for(m = 0;m < mikata_num + 1;m++)
      {
        if((h+m)->seishi == 0)
          break;
      }
      use_kougeki(&enemy[eatacker],&hero[m]);
      o++;
      (e+eatacker)->turn += 1;
    }


    //}



    //printf("\x1b[42m");
    //printf("%s\nHP:%d\n",hero.name,hero.hp);
    //printf("\x1b[41m");
    //printf("%s\nHP:%d\n",enemy.name,enemy.hp);
    //printf("\x1b[49m");
    //printf(".\n");


  }

  return 0;

  }
