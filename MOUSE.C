/*此代码为参考C高级所写*/
#include"head.h"
#include"mouse.h"
#include"tuxing.h"

int MousePixSave[24][24];    /*用于保存鼠标即将覆盖的区域*/
int readxy(int *mx,int *my,int *mbutt)				//读取鼠标位置与按钮状态函数
{
	int xx0=*mx,yy0=*my;
	int buto=0;
	int xnew,ynew;
	union REGS regs;
	do
	{
		regs.x.ax=3;
		int86(51,&regs,&regs);//0x33 
		xnew=regs.x.cx;
		ynew=regs.x.dx;
		*mbutt=regs.x.bx;
	}
	while(xnew==xx0&&ynew==yy0&&*mbutt==buto);
	*mx=xnew;
	*my=ynew;
	if(*mbutt)
	{
		*mx=xnew;
		*my=ynew;
		return -1;
	}
	else
	{
		*mx=xnew;
		*my=ynew;
		return 1;
	}
}
int initmouse()
{
    int	Hei=600;
    int	Wid=800;
     union REGS regs;
     int retcode,xmin=0,ymin=0,xmax=Wid-11,ymax=Hei-20;
     regs.x.ax=0;  //检测鼠标或鼠标驱动是否正确安装并初始化
     int86(0x33,&regs,&regs);
     retcode=regs.x.ax;
     if(retcode==0)
     return 0; //返回0表示鼠标或鼠标驱动程序未安装

      regs.x.ax=4;     //鼠标原点设置 似乎并没有用。。 
      regs.x.cx=0;
     regs.x.dx=0;

     regs.x.ax=7;  //设置鼠标水平边界
	 regs.x.cx=xmin;
	 regs.x.dx=xmax;
     int86(0x33,&regs,&regs);

     regs.x.ax=8; //设置鼠标垂直边界
	 regs.x.cx=ymin;
	 regs.x.dx=ymax;
     int86(0x33,&regs,&regs);
     return retcode;
}
/*
int MouseDraw[22][24]={      //设计鼠标形状，1：表示边界，3：边界所包围的区域，3：鼠标以外的区域  游戏鼠标状/
	{1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,1,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,1,2,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,1,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3},
	{3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3},
	{3,3,3,3,3,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,3,3,3},
	{3,3,3,3,3,3,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,1,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,1,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,3,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,3,1,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,3,3,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3},		
	{3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3},		
	{3,3,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,3},	
	{3,3,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,3},	
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	};*/
		
void cpymouse(int x,int y)  /*将鼠标区域原有图像储存在mousepixsave中*/
{
	int i,j;
	unsigned long pos;
    	int oldpage,newpage;
    	short far *video_buffer=(short far *)0xA0000000L;
		oldpage=(y*800L+x)/32768;
    	newpage=oldpage;
    	selectpage(newpage);
	for(i=0;i<24;i++)
	{
		for(j=0;j<24;j++)
		{
			pos=(i+y)*(800L)+j+x;
            newpage=pos/32768;
            if(oldpage!=newpage)
            {
                selectpage(newpage);
                oldpage=newpage;
            }
            MousePixSave[i][j]=video_buffer[pos%65536];
		 }
	}
	return;
}

void reshowmouse(int x,int y)/*鼠标扣取背景重现*/
{
     int i,j;
     int oldpage,newpage;
    unsigned long pos;
    short far *video_buffer=(short far *)0xA0000000L;
    oldpage=(y*(800L)+x)/32768;
    newpage=oldpage;
    selectpage(oldpage);
		for(i=0;i<24;i++)
		{
			for(j=0;j<24;j++)
			{
					pos=(i+y)*(800L)+j+x;
            newpage=pos/32768;
            if(oldpage!=newpage)
            {
                selectpage(newpage);
                oldpage=newpage;
            }
            video_buffer[pos%65536]=MousePixSave[i][j];
		}
	}
	return;
}
	
void showmouse(int x,int y)  /*鼠标显示*/
{
	int MouseDraw[22][24]={      //设计鼠标形状，1：表示边界，2 4 5 6 7：边界所包围的区域，3：鼠标以外的区域  游戏鼠标状/
	{1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,1,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,2,2,4,4,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,1,4,4,4,5,5,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,4,4,5,5,5,5,5,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,1,5,5,5,5,5,6,6,6,1,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,5,5,5,5,6,6,6,6,6,6,1,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,1,5,5,6,6,6,6,6,6,7,7,7,1,3,3,3,3,3,3,3},
	{3,3,3,3,3,5,6,6,6,6,6,6,7,7,7,7,7,7,1,3,3,3,3,3},
	{3,3,3,3,3,1,6,6,6,6,6,1,1,1,1,1,1,1,1,1,1,3,3,3},
	{3,3,3,3,3,3,6,6,6,6,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,1,6,6,7,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,6,7,7,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,1,7,7,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,3,7,7,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,3,1,7,1,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,3,3,7,1,3,3,3,3,3,3,3,3,3,3,3,3,3},		
	{3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3},		
	{3,3,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,3},	
	{3,3,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,3},	
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	};
    int i,j;
    int oldpage,newpage;
    unsigned long pos;
    short far *video_buffer=(short far *)0xA0000000L;
    oldpage=(y*(800L)+x)/32768;
    newpage=oldpage;
    selectpage(oldpage);
	for(i=0;i<22;i++)
	{
		for(j=0;j<24;j++)
		{
			pos=(i+y)*800L+j+x;
            		newpage=pos/32768;          	//原书为 newpage=pos/32600 可能是打印错误 
            		if(oldpage!=newpage)
            	{
                	selectpage(newpage);
                	oldpage=newpage;
            	}
			if(MouseDraw[i][j]==1)         //边界颜色 5678
                		video_buffer[pos%65536]=0x5678;//边界颜色 
			else if(MouseDraw[i][j]==2)    //内部颜色 
                		video_buffer[pos%65536]=0xe7bf;//0色 
            else if(MouseDraw[i][j]==4)    //内部颜色 
                		video_buffer[pos%65536]=0xcf7f;//1色 
            else if(MouseDraw[i][j]==5)    //内部颜色 
                		video_buffer[pos%65536]=0xb75f;//2色 
            else if(MouseDraw[i][j]==6)    //内部颜色 
                		video_buffer[pos%65536]=0xa71e;//3色 
            else if(MouseDraw[i][j]==7)    //内部颜色 
                		video_buffer[pos%65536]=0x96fe;//4色 96fe
                		//0xffff 0xe7bf 0xcf7f 0xb75f 0xa71e
		}
	}
	delay(5);
	return;
}
