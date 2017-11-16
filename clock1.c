#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  time_t tt;
  struct tm *ts;
  int y,mon,d,you,h,min,sec;
  char youbi[3];

  while(1)
  {
    time(&tt);
    ts = localtime(&tt);

    y = ts->tm_year;
    mon = ts->tm_mon;
    d = ts->tm_mday;
    you = ts->tm_wday;
    h = ts->tm_hour;
    min = ts->tm_min;
    sec = ts->tm_sec;

    if(you == 0) strcpy(youbi,"日");
    else if(you == 1) strcpy(youbi,"月");
    else if(you == 2) strcpy(youbi,"火");
    else if(you == 3) strcpy(youbi,"水");
    else if(you == 4) strcpy(youbi,"木");
    else if(you == 5) strcpy(youbi,"金");
    else strcpy(youbi,"土");

    printf("%d年%d月%d日（%s）%d時%d分%d秒\n", y+1900, mon+1, d, youbi, h, min, sec);
    usleep(1000000);
    system("clear");
  }

  return 0;
}
