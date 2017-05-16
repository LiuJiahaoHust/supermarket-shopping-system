#ifndef   ___OURTIME_H__
#define   ___OURTIME_H__

void get_day(int *year,int *month,int *day,int *inweek);
void get_time(int *hour,int *minute);
void showtime(int x,int y,unsigned int color);
void draw_time(int x,int y,int hour,int minute,unsigned int colorhour,unsigned int colormin); //时钟颜色，分钟颜色 
void draw_time2(int x,int y,int hour,int minute,unsigned int colorbk,unsigned int colornum);
void showday(int x,int y,int year,int month,int day,int inweek,unsigned colorbk,unsigned colornum);

#endif
