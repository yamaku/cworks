#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define KABE '#'
#define START 'S'
#define GOAL 'G'
#define PLAYER '@'
#define TREASURE '$'
#define BOMB '*'
#define GRASS '.'
#define WARP '?'
#define HIGASHI 1
#define MINAMI 2
#define NISHI 3
#define KITA 0

char map[100][100];
int  size;

void make_map()
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n;

    srand((unsigned)time(NULL));
    printf(" ");

    for(n = 0; n < size / 10; n++)
    {
        printf("0123456789");
    }

    printf("\n");

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if((i == 1) && (j == 0) )
            {
                map[i][j] = START;
            }
            else if((i == size - 2) && (j == size - 1) )
            {
                map[i][j] = GOAL;
            }
            else if((i == 0) || (i == size - 1) )
            {
                map[i][j] = KABE;
            }
            else if((j == 0) || (j == size - 1) )
            {
                map[i][j] = KABE;
            }
            else
            {
                map[i][j] = '.';
            }
        }
    }

    for(k = 0; k < 3; k++)
    {
        a = (rand() / (double)RAND_MAX * (size - 3) + 1);
        b = (rand() / (double)RAND_MAX * (size - 3) + 1);

        while((a == 1 && b == 1) || (map[a][b] == TREASURE))
        {
            a = (rand() / (double)RAND_MAX * (size - 3) + 1);
            b = (rand() / (double)RAND_MAX * (size - 3) + 1);
        }

        map[a][b] = TREASURE;
    }

    for(l = 0; l < size - 5; l++)
    {
        c = (rand() / (double)RAND_MAX * (size - 3) + 1);
        d = (rand() / (double)RAND_MAX * (size - 3) + 1);
        e = (rand() / (double)RAND_MAX * (size - 3) + 1);
        f = (rand() / (double)RAND_MAX * (size - 3) + 1);

        while((c == 1 && d == 1) || (c == size - 2 && d == size - 1) || (map[c][d] == TREASURE) || (map[c][d] == BOMB) || (map[c][d] == KABE))
        {
            c = (rand() / (double)RAND_MAX * (size - 3) + 1);
            d = (rand() / (double)RAND_MAX * (size - 3) + 1);
        }

        map[c][d] = BOMB;

        while((e == 1 && f == 1) || (e == size - 2 && f == size - 1) || (map[e][f] == TREASURE) || (map[e][f] == BOMB) || (map[e][f] == KABE))
        {
            e = (rand() / (double)RAND_MAX * (size - 3) + 1);
            f = (rand() / (double)RAND_MAX * (size - 3) + 1);
        }

        map[e][f] = KABE;
    }

    for(m = 0; m < 2; m++)
    {
        g = (rand() / (double)RAND_MAX * (size - 3) + 1);
        h = (rand() / (double)RAND_MAX * (size - 3) + 1);

        while((g == 1 && h == 1) || (e == size - 2 && f == size - 2) || (map[g][h] == TREASURE) || (map[g][h] == BOMB) || (map[g][h] == KABE) || (map[g][h] == WARP))
        {
            g = (rand() / (double)RAND_MAX * (size - 3) + 1);
            h = (rand() / (double)RAND_MAX * (size - 3) + 1);
        }

        map[g][h] = WARP;
    }

    for(i = 0; i < size + 2; i++)
    {
        if(i < size)
        {
            printf("%d", i % 10);
        }

        for(j = 0; j < size; j++)
        {
            if((i == 1) && (j == 0) )
            {
                printf("\x1b[43m");
                printf("%c", map[i][j]);
            }
            else if((i == size - 2) && (j == size - 1) )
            {
                printf("\x1b[43m");
                printf("%c", map[i][j]);
            }
            else if(map[i][j] == TREASURE)
            {
                printf("\x1b[33m");
                printf("\x1b[46m");
                printf("%c", map[i][j]);
            }
            else if(map[i][j] == BOMB)
            {
                printf("\x1b[31m");
                printf("\x1b[46m");
                printf("%c", map[i][j]);
            }
            else if(map[i][j] == KABE)
            {
                printf("\x1b[30m");
                printf("\x1b[47m");
                printf("%c", map[i][j]);
            }
            else if(map[i][j] == WARP)
            {
                printf("\x1b[35m");
                printf("\x1b[46m");
                printf("%c", map[i][j]);
            }
            else if((i == size) && (j == 0) )
            {
                printf(" ");

                for(n = 0; n < size / 10; n++)
                {
                    printf("0123456789");
                }
            }
            else if(i == size)
            {
            }
            else if((i == size + 1) && (j == 0) )
            {
                printf("Enter Command(forward = F,back = B,turn right = R,turn left = L)\nmax step = 300");
            }
            else if(i == size + 1)
            {
            }
            else
            {
                printf("\x1b[46m");
                printf("\x1b[35m");
                printf("%c", map[i][j]);
            }

            printf("\x1b[49m");
            printf("\x1b[39m");
        }

        if(i < size)
        {
            printf("%d", i % 10);
        }

        printf("\n");
    }

    printf("\n");
}

void map_display(int treasure_count, int length, int command_count, char command[])
{
    int l, m, n;

    for(l = 0; l < size + 3; l++)
    {
        for(m = 0; m < size; m++)
        {
            if((l == 1) && (m == 0) )
            {
                printf("\x1b[43m");
                printf("%c", map[l][m]);
                printf("\x1b[49m");
            }
            else if(map[l][m] == PLAYER)
            {
                printf("\x1b[39m");
                printf("%c", map[l][m]);
            }
            else if((l == size - 2) && (m == size - 1) )
            {
                printf("\x1b[43m");
                printf("%c", map[l][m]);
            }
            else if(map[l][m] == ' ')
            {
                printf("\x1b[49m");
                printf("%c", map[l][m]);
            }
            else if(map[l][m] == TREASURE)
            {
                printf("\x1b[33m");
                printf("\x1b[46m");
                printf("%c", map[l][m]);
            }
            else if(map[l][m] == BOMB)
            {
                printf("\x1b[31m");
                printf("\x1b[46m");
                printf("%c", map[l][m]);
            }
            else if(map[l][m] == KABE)
            {
                printf("\x1b[30m");
                printf("\x1b[47m");
                printf("%c", map[l][m]);
            }
            else if(map[l][m] == WARP)
            {
                printf("\x1b[35m");
                printf("\x1b[46m");
                printf("%c", map[l][m]);
            }
            else if((l == size) && (m == 0) )
            {
                printf("$ : %d\tstep : %d", treasure_count, command_count);
            }
            else if(l == size)
            {
                ;
            }
            else if((l == size + 1) && (m == 0) )
            {
                for(n = 0; n < length; n++)
                {
                    if(n == command_count)
                    {
                        printf("\x1b[41m");
                        printf("%c", command[n]);
                        printf("\x1b[39m");
                        printf("\x1b[49m");
                    }
                    else
                    {
                        printf("%c", command[n]);
                    }
                }

                command_count++;
            }
            else if(l == size + 1)
            {
                ;
            }
            else
            {
                printf("\x1b[46m");
                printf("\x1b[35m");
                printf("%c", map[l][m]);
            }

            printf("\x1b[49m");
            printf("\x1b[39m");
        }

        printf("\n");
    }

    printf("\n\n");
    usleep(500000);
    system("clear");
}

int player_move(char command[], int length)
{
    int count = 1, vector = 1, i = 0, j = 1, k = 0, treasure_count = 0, a, b, command_count = 0;

    for(i = 0; i < length - 1; i++)
    {
        map[j][k] = ' ';

        if(command[i] == 'R')
        {
            count++;
            vector = count % 4;
        }
        else if(command[i] == 'L')
        {
            count += 3;
            vector = count % 4;
        }
        else if(command[i] == 'F')
        {
            switch (vector)
            {
              case HIGASHI:
                k++;

                if(map[j][k] == KABE)
                {
                    k--;
                }

                break;
              case MINAMI:
                j++;

                if(map[j][k] == KABE)
                {
                    j--;
                }

                break;
              case NISHI:
                k--;

                if(map[j][k] == KABE)
                {
                    k++;
                }

                break;
              case KITA:
                j--;

                if(map[j][k] == KABE)
                {
                    j++;
                }

                break;
            }
        }
        else if(command[i] == 'B')
        {
            switch (vector)
            {
              case HIGASHI:
                k--;

                if(map[j][k] == KABE)
                {
                    k++;
                }

                break;
              case MINAMI:
                j--;

                if(map[j][k] == KABE)
                {
                    j++;
                }

                break;
              case NISHI:
                k++;

                if(map[j][k] == KABE)
                {
                    k--;
                }

                break;
              case KITA:
                j++;

                if(map[j][k] == KABE)
                {
                    j--;
                }

                break;
            }
        }
        else
        {
            continue;
        }

        if(map[j][k] == BOMB)
        {
            system("clear");
            printf("~GAMEOVER~\nBomb exploded...\n");
            return 0;
        }

        if(map[j][k] == TREASURE)
        {
            treasure_count++;
        }

        if(map[j][k] == WARP)
        {
            for(a = 1; a < size - 1; a++)
            {
                for(b = 1; b < size - 1; b++)
                {
                    if(map[a][b] == WARP)
                    {
                        if((a != j) && (b != k) )
                        {
                            j = a;
                            k = b;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }

        if(map[j][k] == GOAL)
        {
            system("clear");
            printf("Goal!\n");

            if(treasure_count == 3)
            {
                printf("You got all treasures!Wondarful\n");
            }
            else
            {
                printf("You got %d Treasure\n", treasure_count);
            }

            return 1;
        }

        map[j][k] = PLAYER;
        map[1][0] = START;
        system("clear");
        map_display(treasure_count, length, command_count, command);
        command_count++;
    }

    printf("~GAMEOVER~\nYou could not goal...\n");
    return 0;
}

int main(int argc, char** argv)
{
    int  length, i, j, a, b, level;
    char repeat[10], title[17] = "Treasure Get Game", input[15];

    system("clear");
    printf("\x1b[33m");

    for(j = 0; j < 17; j++)
    {
        printf("%c", title[j]);
        fflush(stdout);
        usleep(50000);
    }

    printf("\x1b[39m");
    printf("\n");
    sleep(2);
    system("clear");
    printf("LEVEL SERECT(1~5):");
    fgets(input, 10, stdin);

    level = atoi(input);

    while(level < 1 || level > 5)
    {
        system("clear");
        printf("LEVEL SERECT(1~5):");
        fgets(input, 10, stdin);
        level = atoi(input);
    }

    for(i = level; i < 11; i++)
    {
        size = 10 * i;

        char command[100];

        system("clear");
        printf("\x1b[36m");
        printf("~LEVEL%d~\n", i);
        printf("\x1b[49m");
        printf("\x1b[39m");
        sleep(2);
        system("clear");
        make_map(i * 10);
        fgets(command, 100, stdin);
        length = strlen(command);
        a      = player_move(command, length);

        if(a == 0)
        {
            printf("Try again?(YES=1,NO=0):");
            fgets(repeat, 10, stdin);
            b = atoi(repeat);

            if(b == 1)
            {
                i--;
                continue;
            }
            else
            {
                break;
            }
        }

        sleep(2);
    }

    return 0;
}
