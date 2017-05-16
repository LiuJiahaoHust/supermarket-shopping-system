#include"head.h"
#include"welcome.h"
#include"advice.h"
#include"tuxing.h"
#include"mouse.h"
#include"input.h"

void advice(int *flag)
{	
	int x1,y1,x2,y2,buttons,i,classnum;
	char str[300];
	char classtxt[25]="cfile\\class.txt";
	char advicetxt[25]="cfile\\advice.txt";
	FILE *fp,*fp1; //class&advice file 
	if((fp=fopen(classtxt,"at+"))==NULL)
	{
		printf("classtxt file cannot be open");
		getch();
		exit(1); 
	}
	if((fp1=fopen(advicetxt,"at+"))==NULL)
	{
		printf("advicetxt file cannot be open");
		getch();
		exit(1); 
	}
	x1=y1=x2=y2=buttons=classnum=0;
	drawadvice(); 
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
		for(i=1;i<=5;i++)
			if(x2>46+70*i&&y2>477&&x2<110+70*i&&y2<477+64&&buttons==1)
			{
				put_pic(95,468,"copy6.bmp",1);
				starnum(i);	
				classnum=i;
			} 	
		if(x2>710&&y2>530&&x2<780&&y2<580&&buttons==1)
		{
			*flag=3;//回到help界面
			if(classnum!=0)
				fprintf(fp,"%d",classnum);	
			if(str[0]!='\0')
				fprintf(fp1,"----next----%s",str);
			fclose(fp);	
			fclose(fp1);
			return;
		}
		if(x2>50&&y2>160&&x2<500&&y2<400&&buttons==1)
		{
			drawbar(72,170,542,281,0xffff);
			input(75,170,290,0,0,0xffff,1,str);
		}
	}
}

void drawadvice()
{
	put_pic(0,0,"advice.bmp",1);
	delay(300); 
} 
void starnum(int num)
{
	char yellowstar[15]="yellow.bmp";
	int i;
	for(i=1;i<=5;i++)
	{
		if(num>=i)
			put_pic(46+70*i,477,yellowstar,0);		
	}
}
