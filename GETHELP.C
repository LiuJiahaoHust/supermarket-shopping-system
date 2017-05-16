#include"head.h"
#include"welcome.h"
#include"tuxing.h"
#include"mouse.h"
#include"hanzi.h"
#include"gethelp.h" 

void gethelp(int *flag)
{
	unsigned int color;
	int x1,y1,x2,y2,buttons;
	int i;
	int mode=0;
	int hour,minutenew,minuteold;
	put_pic(0,0,"help.bmp",1);
	help_inf();//画帮助界面。。。 
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
		if(x2>710&&y2>530&&x2<780&&y2<580&&buttons==1)		
		{
				*flag=2;//回到主界面 
				return;
		}
		donghua_gethelp(x2,y2,&mode);
		if(x2>100&&y2>190&&x2<470&&y2<223&&buttons==1)		
		{
			*flag=10;//查看功能界面 与help类似。。。 
			return;
		}
		if(x2>100&&y2>270&&x2<470&&y2<303&&buttons==1)		
		{
			*flag=11;//得到时间
			return; 
		}
		if(x2>100&&y2>350&&x2<470&&y2<383&&buttons==1)		
		{
			*flag=5;//查看今日特价商品 
			return;
		}
		if(x2>100&&y2>430&&x2<470&&y2<463&&buttons==1)		
		{
			*flag=6;//向该超市或系统提出意见界面   与help类似。。。 
			return;
		}
		if(x2>617&&y2>21&&x2<760&&y2<191&&buttons==1)		
		{
			*flag=1;//点击画像 快速退出（这里取代了X的效果） 
			return;
		}
	}
}

void help_inf(void)
{
	unsigned int color;	
	int i;
	color=get16color(0xffda00);
	drawcircle(55,220,4,color,1); 
	color=get16color(0xfdd1a3);
	drawcircle(55,300,4,color,1); 
	color=get16color(0xa3fdc7);
	drawcircle(55,380,4,color,1);
	color=get16color(0xb7dafa);
	drawcircle(55,460,4,color,1); 
	color=get16color(0xf7f7f7);
	for(i=0;i<4;i++)
		drawline(100,223+80*i,470,223+80*i,color);
	helphz(0); 
}

void helphz(int flag)
{
	unsigned int color;
	char hzsr[4][30]={"查看超市购物系统的功能","获取当前日期和时间","查看今日特价商品","向该超市或系统提出意见"};
	color=get16color(0xf7f7f7);
	switch(flag)
		{
			case 0:
				hz(148,190,hzsr[0],color,24); 
				hz(172,270,hzsr[1],color,24); 
				hz(188,350,hzsr[2],color,24); 
				hz(148,430,hzsr[3],color,24); 
				break;
			case 1:
				color=get16color(0xfee123);
				hz(148,190,hzsr[0],color,24); 
				break; 
			case 2:
				color=get16color(0xfee123);
				hz(172,270,hzsr[1],color,24);
				break;
			case 3:
				color=get16color(0xfee123);
				hz(188,350,hzsr[2],color,24); 
				break;
			case 4:
				color=get16color(0xfee123);
				hz(148,430,hzsr[3],color,24); 
				break;
		}
}

void donghua_gethelp(int x2,int y2,int *mode)//动画效果 
{
	int i;
	for(i=1;i<=4;i++)
		if(x2>100&&y2>(110+80*i)&&x2<470&&y2<(143+80*i)&&*mode!=1)		
		{
			helphz(0);
			helphz(i);
			*mode=i;
		}
}
