#include"head.h"
#include"welcome.h"
#include"shop.h"
#include"tuxing.h"
#include"hanzi.h"
#include"mouse.h"

void shop(int *flag,int *whobuy)
{
	int x1,y1,x2,y2,buttons;
	int num=2;
	int mode=1;//�ı���ʵģʽ�����ڻ�һ���ÿ��Ľ��档����
	int yidong=0;//win8ģ�黯������ƶ���λ���ж�
	unsigned int gold=get16color(0xfee123);
	unsigned int white=get16color(0xffffff);
	x1=y1=x2=y2=buttons=0;
	*whobuy=1;//�̻���������
	put_pic(0,0,"shop1.bmp",1);
	drawfunbar(mode);
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
		if(x2>288&&y2>526&&x2<512&&y2<556&&buttons==1)//�л���ʾģʽ
		{
			if(mode==1)
				mode=2;
			else if(mode==2)
				mode=1;
			drawfunbar(mode);
			num=2;
		}
		if(x2>220&&y2>160&&x2<580&&y2<380&&buttons==1&&mode==1)//����м书�ܿ�
		{
			*flag=(num+11);
			return;
		}
		if(x2>55&&y2>220&&x2<185&&y2<320&&buttons==1&&mode==1)//������ܿ�
		{
			if(num!=1)
				num--;
			else
				num=6;
			shophz(1,num-1);
			drawnum(num);
			shophz(2,num+1);
			delay(80);
		}
		if(x2>615&&y2>220&&x2<745&&y2<320&&buttons==1&&mode==1)//����ҹ��ܿ�
		{
			if(num!=6)
				num++;
			else
				num=1;
			shophz(1,num-1);
			drawnum(num);
			shophz(2,num+1);
			delay(80);
		}
		if(x2>100&&y2>105&&x2<280&&y2<285&&mode==2&&yidong!=1)//�ƶ������ܿ�1
		{
			redraw(yidong,white);
			yidong=1;
			redraw(yidong,gold);
		}
		if(x2>310&&y2>105&&x2<490&&y2<285&&mode==2&&yidong!=2)//�ƶ������ܿ�2
		{
			redraw(yidong,white);
			yidong=2;
			redraw(yidong,gold);
		}
		if(x2>520&&y2>105&&x2<700&&y2<285&&mode==2&&yidong!=3)//�ƶ������ܿ�3
		{
			redraw(yidong,white);
			yidong=3;
			redraw(yidong,gold);
		}
		if(x2>100&&y2>315&&x2<220&&y2<435&&mode==2&&yidong!=4)//�ƶ������ܿ�4
		{
			redraw(yidong,white);
			yidong=4;
			redraw(yidong,gold);
		}
		if(x2>250&&y2>315&&x2<550&&y2<435&&mode==2&&yidong!=5)//�ƶ������ܿ�5
		{
			redraw(yidong,white);
			yidong=5;
			redraw(yidong,gold);
		}
		if(x2>580&&y2>315&&x2<700&&y2<435&&mode==2&&yidong!=6)//�ƶ������ܿ�6
		{
			redraw(yidong,white);
			yidong=6;
			redraw(yidong,gold);
		}

		if(x2>100&&y2>105&&x2<280&&y2<285&&buttons==1&&mode==2)//��������ܿ�1
		{
			*flag=12;
			return;
		}
		if(x2>310&&y2>105&&x2<490&&y2<285&&buttons==1&&mode==2)//��������ܿ�2
		{
			*flag=13;
			return;
		}
		if(x2>520&&y2>105&&x2<700&&y2<285&&buttons==1&&mode==2)//��������ܿ�3
		{
			*flag=14;
			return;
		}
		if(x2>100&&y2>315&&x2<220&&y2<435&&buttons==1&&mode==2)//��������ܿ�4
		{
			*flag=15;
			return;
		}
		if(x2>250&&y2>315&&x2<550&&y2<435&&buttons==1&&mode==2)//��������ܿ�5
		{
			*flag=16;
			return;
		}
		if(x2>580&&y2>315&&x2<700&&y2<435&&buttons==1&&mode==2)//��������ܿ�6
		{
			*flag=17;
			return;
		}
		if(x2>666&&y2>555&&x2<800&&y2<600&&buttons==1)//�������
		{
			*flag=2;
			*whobuy=0;
			delay(80);
			return;
		}
	}
}

void drawfunbar(int mode)
{
	unsigned int white=get16color(0xffffff);
	if(mode==1)//���ҵ��
	{
		put_pic(0,0,"shop1.bmp",1);
		shophz(1,1);
		drawnum(2);
		shophz(2,3);
	}
	else if(mode==2)//win8ģ�黯
	{	//��6���ÿ��Ŀ򣬺����ӽ�ȥ����
		char bmpname[][10]={"cut_4.bmp","cut_5.bmp","cut_6.bmp","cut_1.bmp","cut_2.bmp","cut_3.bmp"};
		put_pic(0,0,"shop.bmp",1);
		put_pic(100,315,bmpname[0],1);
		redraw(4,white);
		put_pic(250,315,bmpname[1],1);
		redraw(5,white);
		put_pic(580,315,bmpname[2],1);
		redraw(6,white);
		put_pic(100,105,bmpname[3],1);
		redraw(1,white);
		put_pic(310,105,bmpname[4],1);
		redraw(2,white);
		put_pic(520,105,bmpname[5],1);//�Ȼ����ٻ��ϲ�Υ�͡���
		redraw(3,white);
	 }
}

void redraw(int yidong,unsigned int color)
{
		switch(yidong)
		{
			case 1:
			  	drawline(100,105,100,285,color);
				drawline(100,285,280,285,color);
				drawline(280,285,280,105,color);
				drawline(280,105,100,105,color);
			   	break;
			case 2:
				drawline(310,105,310,285,color);
				drawline(310,285,490,285,color);
				drawline(490,285,490,105,color);
				drawline(490,105,310,105,color);
				break;
			case 3:
				drawline(520,105,520,285,color);
				drawline(520,285,700,285,color);
				drawline(700,285,700,105,color);
				drawline(700,105,520,105,color);
				break;
			case 4:
				drawline(100,315,100,435,color);
				drawline(100,435,220,435,color);
				drawline(220,435,220,315,color);
				drawline(220,315,100,315,color);
				break;
			case 5:
				drawline(250,315,250,435,color);
				drawline(250,435,550,435,color);
				drawline(550,435,550,315,color);
				drawline(550,315,250,315,color);
				break;
			case 6:
				drawline(580,315,580,435,color);
				drawline(580,435,700,435,color);
				drawline(700,435,700,315,color);
				drawline(700,315,580,315,color);
				break;
		}
}

void drawnum(int num)//����λ�÷��õ�num��ͼ
{
	char path[15]="1cut.bmp";
	path[0]=num+'0';
	put_pic(220,160,path,1);
}

void shophz(int i,int num)
{
	char funbar[9][12]={"����齱","�޸���Ʒ","����ҳ��","��Ʒͳ��","��������","�û���Ϣ","����齱","�޸���Ʒ","\0"};
	int x=55,y=220,k=0;
	if(i==1)
		put_pic(45,210,"copy3.bmp",1);
	if(i==2)
	{
		x=615;
		put_pic(605,210,"copy4.bmp",1);
	}
	for(k=0;k<=7;k++)
		if(num==k)
			hz(x+30,y+42,funbar[k],0xffff,16);
}
