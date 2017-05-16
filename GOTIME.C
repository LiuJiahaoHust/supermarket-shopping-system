#include"head.h"
#include"welcome.h"
#include"gotime.h"
#include"tuxing.h"
#include"ourtime.h"
#include"mouse.h"
void gotime(int *flag)
{
	unsigned int colorbk,colornum;
	int x1,y1,x2,y2,buttons;
	int hour,minute,year,month,day,inweek;
	x1=y1=x2=y2=buttons=0;
	put_pic(0,0,"time.bmp",1);
	get_time(&hour,&minute);
	get_day(&year,&month,&day,&inweek);
	puttime(hour,minute,year,month,day,inweek);
	cpymouse(0,0);
	while(1)
	{ 
		readxy(&x1,&y1,&buttons);
		if(x1!=x2||y1!=y2)
		{
			reshowmouse(x2,y2);
			cpymouse(x1,y1);
			showmouse(x1,y1);
			x2=x1;
			y2=y1;
		}
		if(x2>415&&y2>55&&x2<470&&y2<105&&buttons==1)//重画时间 需贴图覆盖原图 
		{
			get_time(&hour,&minute);
			get_day(&year,&month,&day,&inweek);
			puttime(hour,minute,year,month,day,inweek);
		}
		if(x2>710&&y2>530&&x2<780&&y2<580&&buttons==1)
		{
				*flag=3;//回到help界面
				return;
		}
	}
}

void puttime(int hour,int minute,int year,int month,int day,int inweek) 
{
	unsigned int colorhour,colormin,colorline,colorbk,colornum;
	colorhour=get16color(0xf0fff0);//时针颜色  稍带绿的白 
	colormin=get16color(0xdcdcdc);//分针颜色 	灰 
	colorbk=get16color(0x9579d3);//背景颜色 	淡紫色     测试后透明好看，即不需要该参数。。 
	colornum=get16color(0x99ed74);//框子模式数字	绿色
	colorline=get16color(0xffffff);//线的颜色 	 白 
			showtime(245,415,colorline);
			draw_time(245,415,hour,minute,colorhour,colormin);//时间 钟表模式 
			draw_time2(450,410,hour,minute,colorbk,colornum);//时间 框子模式 
	showday(325,220,year,month,day,inweek,colorbk,colornum);//日期 框子模式 
}
