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
    b->seishi = 1;
  }
}

int main(int argc, char **argv)
{
  FILE *fp;
  int c,csum = 0,i,j,k,l,m,n = 0,o = 0,p = 0,q,r,b[3],mikata_num,enemy_num,
  tmp = 0,hatacker,eatacker,hescape = 0,eescape = 0;
  char fname[20];
  srand((unsigned)time(NULL));

  system("clear");

  printf("味方の数(0~9)を入力してください:");
  fflush(stdin);
  scanf("%d",&mikata_num);

  printf("敵の数(1~9)を入力してください:");
  fflush(stdin);
  scanf("%d",&enemy_num);

  struct status hero[mikata_num + 1],enemy[enemy_num];
  int tmp2[mikata_num + 1],tmp3[enemy_num];

  for(i = 0;i < mikata_num + 1;i++)
  {
    tmp2[i] = i;
    sprintf(hero[i].name,"hero%d",i);
  }

  for(i = 0;i < enemy_num;i++)
  {
    tmp3[i] = i;
    sprintf(enemy[i].name,"enemy%d",i);
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
  hero[0].hp = b[0] + 20;
  hero[0].kougeki = b[1] + 20;
  hero[0].bougyo = (b[2] + 20) / 10;
  hero[0].subayasa = b[3] + 20;
  strcpy(hero[0].name,fname);
  hero[0].seishi = 0;
  hero[0].turn = 0;

  for(i = 1;i <= mikata_num;i++)
  {
    hero[i].hp = (rand()%300) + 100;
    hero[i].kougeki = (rand()%40) + 10;
    hero[i].bougyo = (rand()%10) + 5;
    hero[i].subayasa = (rand()%40) + 20;
    hero[i].turn = 0;
    hero[i].seishi = 0;
  }

  for(i = 0;i < enemy_num;i++)
  {
    enemy[i].hp = (rand()%300) + 100;
    enemy[i].kougeki = (rand()%50) + 50;
    enemy[i].bougyo = (rand()%10) + 5;
    enemy[i].subayasa = (rand()%40) + 20;
    enemy[i].turn = 0;
    enemy[i].seishi = 0;
  }
  //system("clear");
  for(j = 0;j < mikata_num;j++)
  {
    for(i = 0;i < mikata_num;i++)
    {
      if(hero[tmp2[i]].subayasa < hero[tmp2[i + 1]].subayasa)
      {
        tmp = tmp2[i + 1];
        tmp2[i + 1] = tmp2[i];
        tmp2[i] = tmp;
      }
    }
  }

  for(j = 0;j < enemy_num - 2;j++)
  {
    for(i = 0;i < enemy_num - 1;i++)
    {
      if(enemy[tmp3[i]].subayasa < enemy[tmp3[i + 1]].subayasa)
      {
        tmp = tmp3[i + 1];
        tmp3[i + 1] = tmp3[i];
        tmp3[i] = tmp;
      }
    }
  }

  for(i = 0;i < mikata_num + 1;i++)
  {
    hero[i].rank = tmp2[i];
  }

  for(i = 0;i< enemy_num;i++)
  {
    enemy[i].rank = tmp3[i];
  }

  while(1)
  {
    for(i = 0;i < mikata_num + 1;i++)
    {
      if(hero[i].hp > 0)
        break;
      else if(i != mikata_num)
        continue;
      return 0;
    }

    for(i = 0;i < enemy_num;i++)
    {
      if(enemy[i].hp > 0)
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
      printf("%s HP:%d ",hero[i].name,hero[i].hp);
    }
    printf("\n");

    for(i = 0;i < enemy_num;i++)
    {
      printf("\x1b[41m");
      printf("%s HP:%d ",enemy[i].name,enemy[i].hp);
    }
    printf("\n");
    printf("\x1b[49m");

    for(q=0;q<mikata_num+1;q++)
    {
      if(hero[q].turn < p)
        break;
      else if(q != mikata_num)
        continue;
      else
      {
        for(r=0;r<enemy_num;r++)
        {
          if(enemy[r].turn < p)
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
      if(hero[j].rank == n%(mikata_num+1))
      {
        if(hero[j].turn >= p)
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
      if(enemy[k].rank == o%enemy_num)
      {
        if(enemy[k].turn >= p)
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
      if(hero[hatacker].hp < 1)
      {
        hero[hatacker].turn += 1;
        n++;
        continue;
      }
      printf("%sのターン：誰に攻撃する?\n",hero[hatacker].name);
      for(l = 0;l < enemy_num;l++)
      {
        if(enemy[l].seishi == 0)
        {
          printf("%d:%s ",l,enemy[l].name);
        }
      }
      printf("\n");
      scanf("%d",&tmp);
      fgetc(stdin);
      use_kougeki(&hero[hatacker],&enemy[tmp]);
      n++;
      hero[hatacker].turn += 1;
      continue;
    }

    else if((hescape == 1) && (eescape != 1))
    {
      for(m = 0;m < mikata_num + 1;m++)
      {
        if(hero[m].seishi == 0);
          break;
      }
      if(enemy[eatacker].hp < 1)
      {
        enemy[eatacker].turn += 1;
        o++;
        continue;
      }
      use_kougeki(&enemy[eatacker],&hero[m]);
      o++;
      enemy[eatacker].turn += 1;
      continue;
    }

    else if((hescape == 1) && (eescape == 1))
      continue;

    if(hero[hatacker].subayasa >= enemy[eatacker].subayasa)
    {
      if(hero[hatacker].hp < 1)
      {
        hero[hatacker].turn += 1;
        n++;
        continue;
      }
      printf("%sのターン：誰に攻撃する?\n",hero[hatacker].name);
      for(l = 0;l < enemy_num;l++)
      {
        if(enemy[l].seishi == 0)
        {
          printf("%d:%s ",l,enemy[l].name);
        }
      }
      printf("\n");
      scanf("%d",&tmp);
      fgetc(stdin);
      use_kougeki(&hero[hatacker],&enemy[tmp]);
      n++;
      hero[hatacker].turn += 1;
    }

    else
    {
      if(enemy[eatacker].hp < 1)
      {
        enemy[eatacker].turn += 1;
        o++;
        continue;
      }
      for(m = 0;m < mikata_num + 1;m++)
      {
        if(hero[m].seishi == 0)
          break;
      }
      use_kougeki(&enemy[eatacker],&hero[m]);
      o++;
      enemy[eatacker].turn += 1;
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
