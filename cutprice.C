#include"head.h"
#include"welcome.h"
#include"mouse.h"
#include"cutprice.h"
#include"tuxing.h"

void cutprice(int *flag)
{
	int x1,y1,x2,y2,buttons;
	x1=y1=x2=y2=buttons=0;
	put_pic(0,0,"cutprice.bmp",1);	
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
				*flag=3;//回到help界面
				return;
		}
	}
}
