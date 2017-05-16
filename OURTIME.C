#include"head.h"
#include"ourtime.h"
#include"tuxing.h"
#include"hanzi.h"

#define size1 75  	//表盘外尺寸 
#define size2 65	//表盘内尺寸 
#define size3 30	//时钟长 
#define size4 50	//分钟长 
#define pi 3.1415927 
float angle1=30.0*pi/180.0;
float angle2=60.0*pi/180.0; 
void get_day(int *year,int *month,int *day,int *inweek)
{
	union REGS in,out;
	in.h.ah=0x2a;
	int86(0x21,&in,&out);
	*year=out.x.cx;
	*month=out.h.dh;
	*day=out.h.dl;
	*inweek=out.h.al;
}
void get_time(int *hour,int *minute)
{
	union REGS in,out;
	in.h.ah=0x2c;
	int86(0x21,&in,&out);
	*hour=out.h.ch;
	*minute=out.h.cl;
}

void showtime(int x,int y,unsigned int color)//画钟表外壳函数。。无法用循环简化（每4个1循环，还需判断，循环后代码更复杂） 
{
	float a[10],b[10],c[10],d[10];
	int i;
	{ 
		a[0]=size1*cos(angle1);
		a[1]=size1*cos(angle2);
		a[2]=-size1*cos(angle2);
		a[3]=-size1*cos(angle1);
		a[4]=-size1*cos(angle1);
		a[5]=-size1*cos(angle2);
		a[6]=size1*cos(angle2);
		a[7]=size1*cos(angle1);
		b[0]=size1*sin(angle1);
		b[1]=size1*sin(angle2);
		b[2]=size1*sin(angle2);
		b[3]=size1*sin(angle1);
		b[4]=-size1*sin(angle1);
		b[5]=-size1*sin(angle2);
		b[6]=-size1*sin(angle2);
		b[7]=-size1*sin(angle1);
		c[0]=size2*cos(angle1);
		c[1]=size2*cos(angle2);
		c[2]=-size2*cos(angle2);
		c[3]=-size2*cos(angle1);
		c[4]=-size2*cos(angle1);
		c[5]=-size2*cos(angle2);
		c[6]=size2*cos(angle2);
		c[7]=size2*cos(angle1);
		d[0]=size2*sin(angle1);
		d[1]=size2*sin(angle2);
		d[2]=size2*sin(angle2);
		d[3]=size2*sin(angle1);
		d[4]=-size2*sin(angle1);
		d[5]=-size2*sin(angle2);
		d[6]=-size2*sin(angle2);
		d[7]=-size2*sin(angle1);
	} 
	drawpoint(x,y,color);
	drawpoint(x-1,y,color);
	drawpoint(x+1,y,color);
	drawpoint(x,y-1,color);
	drawpoint(x-1,y-1,color);
	drawpoint(x+1,y-1,color);
	drawpoint(x,y+1,color);
	drawpoint(x-1,y+1,color);
	drawpoint(x+1,y+1,color);
	drawcircle(x,y,size1,color,0);		
	for(i=0;i<=7;i++)
		drawline((int)(x+a[i]),(int)(y+b[i]),(int)(x+c[i]),(int)(y+d[i]),color);
	put_asc(x-3,y+size2-5,1,1,"6",color);
	put_asc(x-4,y-size2-1,1,1,"12",color);
	put_asc(x+size2-3,y-6,1,1,"3",color);
	put_asc(x-size2-2,y-7,1,1,"9",color);
}

void draw_time(int x,int y,int hour,int minute,unsigned int colorhour,unsigned int colormin)//画钟表指针函数 
{
	float phour,pmin; 
	float fhour;
	float dx_hour,dx_min,dy_hour,dy_min;
	if(hour>=12)
		hour-=12;
	fhour=hour+minute/60.0;
	phour=fhour/12.0*2*pi-pi/2.0;
	pmin=minute/60.0*2*pi-pi/2.0; 
	dx_hour=size3*cos(phour);
	dy_hour=size3*sin(phour);
	dx_min=size4*cos(pmin);
	dy_min=size4*sin(pmin);
	drawline(x,y,(int)(x+dx_hour),(int)(y+dy_hour),colorhour);
	drawline(x,y,(int)(x+dx_min),(int)(y+dy_min),colormin); 
} 

void draw_time2(int x,int y,int hour,int minute,unsigned int colorbk,unsigned int colornum)//写时间的函数 
{
	int dx=78;
	char chour[5];
	char cmin[5];
	itoa(hour,chour,10);
	itoa(minute,cmin,10);
	if(strlen(cmin)==1)
	{
		cmin[1]=chour[0];
		cmin[0]='0';
		cmin[2]='\0';
	} 
	if(strlen(chour)==1)
		put_asc(x-60,y-4,2,2,chour,colornum);
	else
		put_asc(x-44,y-3,2,2,chour,colornum);
	put_asc(x+37,y-3,2,2,cmin,colornum);
	hz(x,y,"时",colornum,24); 
	hz(x+dx,y,"分",colornum,24);
} 

void showday(int x,int y,int year,int month,int day,int inweek,unsigned colorbk,unsigned colornum)//写日期的函数 星期几为大写 
{
	int dx=82;
	int dy=60;
	int dx2=50;
	char cyear[6];
	char cmonth[5];
	char cday[5];
	char xingqi[7][10]={"星期一","星期二","星期三","星期四","星期五","星期六","星期日"}; 
	itoa(year,cyear,10);
	itoa(month,cmonth,10);
	itoa(day,cday,10);
	put_asc(x-85,y-4,2,2,cyear,colornum);
	hz(x,y,"年",colornum,24); 
	if(strlen(cmonth)==1)
		put_asc(x+dx-60,y-4,2,2,cmonth,colornum);	
	else
		put_asc(x+dx-44,y-3,2,2,cmonth,colornum);
	hz(x+dx,y,"月",colornum,24);
	if(strlen(cday)==1)
		put_asc(x+2*dx-60,y-4,2,2,cday,colornum);
	else
		put_asc(x+2*dx-44,y-3,2,2,cday,colornum);
	hz(x+dx*2,y,"日",colornum,24);
	if(inweek==1)	
		hz(x+dx2,y+dy,xingqi[0],colornum,24);
	if(inweek==2)
		hz(x+dx2,y+dy,xingqi[1],colornum,24);
	if(inweek==3)
		hz(x+dx2,y+dy,xingqi[2],colornum,24);
	if(inweek==4)
		hz(x+dx2,y+dy,xingqi[3],colornum,24);
	if(inweek==5)	
		hz(x+dx2,y+dy,xingqi[4],colornum,24);
	if(inweek==6)	
		hz(x+dx2,y+dy,xingqi[5],colornum,24);
	if(inweek==7)
		hz(x+dx2,y+dy,xingqi[6],colornum,24);
}
