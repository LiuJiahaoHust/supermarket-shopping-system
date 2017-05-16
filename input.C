#include"mouse.h"
#include"TUXING.h"
#include"input.h"
#include"head.h"

int input(int x,int y,int n,int m,unsigned int color1,unsigned int color2,int size,char *s)		//在指定位置输入字符串函数，n表示输入字符串的最大个数，m判断是以明文还是暗文显示,color1表示输入的字体颜色，color2表示输入框的背景颜色，size表示字体大小
{
	int i=0,a=0,x1=x,y1=y;
	int k=46;//每行字数 
	char j;
	while(1)
	{
        shu_line(x1-1,y1,y1+13*size,color1);  //黑色竖线
		while(1)
		{
			if(kbhit()==0)
			{
                shu_line(x1-1,y1,y1+13*size,color2);
                delay(200);
                shu_line(x1-1,y1,y1+13*size,color1);
			}
			else
			{
				j=getch();
				shu_line(x1-1,y1,y1+13*size,color2);
				break;
			}
			delay(200);
		}
		if(j==Bksp)			//删除
		{
			int number;
			for(number=1;number<=6;number++)
				if(a=number&&i==a*k)
				{
					a=number-1;
					x1=x+10*size*k;
					y1=y1-16*size;
				}
			if(x1>x)
			{

				i=i-1;
				x1=x1-10*size;
				if(m==0)
                {
                    put_asc(x1,y1,size,size,s+i,color2);
                }
                if(m==1)
                {
                    put_asc(x1,y1,size,size,"*",color2);
                }
				s[i]='\0';
			}
		}
		else if(j==Enter)			//确定
		{
			break;
		}
		else if(i<n)
		{
			int number;
		 	s[i]=j;
			s[i+1]='\0';
			if(m==0)		//明文
		 		put_asc(x1,y1,size,size,s+i,color1);
			if(m==1)		//暗文
				put_asc(x1,y1,size,size,"*",color1);
			x1=x1+10*size;
			i++;
			for(number=0;number<=5;number++)
				if((i>(k-1+number+a*(k-1)))&&a==number)
				{
					y1=y1+16*size;
					x1=x;
					a++;
				}
		}
	}
	return i;
}
