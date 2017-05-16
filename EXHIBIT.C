#include"head.h"
#include"welcome.h"
#include"tuxing.h"
#include"mouse.h"
#include"hanzi.h"
#include"exhibit.h"
#include"wenjian.h"


void exhibition(int *flag)
{
	int mode=0;
	int x1,y1,x2,y2,buttons;
	int i,a=0;
	GOODS *l,*p;
	GOODS *aa,*bb;
    l=creat_list();
	exh_bk();
	showhzex(0);
	showgoods(l);
	p=l->next;
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
		if(x2>674&&y2>40&&x2<766&&y2<100&&buttons==1)//回到主界面
		{
			free_head1(l);
			free(l);
			l=NULL;
			*flag=2;
			delay(50);
			return;
		}
		if(x2>524&&y2>40&&x2<616&&y2<100&&buttons==1)//自助购物
		{
			free_head1(l);
			free(l);
			*flag=13;
			return;
		}
		if(x2>700&&y2>500&&x2<750&&y2<550&&buttons==1)  //向下翻页
        {
            a=downpage(p);
            if(a==1)
            {
                for(i=0;i<6;i++)
                {
                    p=p->next;
                }
            }
            a=0;
            delay(80);
        }
        if(x2>700&&y2>200&&x2<750&&y2<250&&buttons==1)  //向上翻页
        {
            a=uppage(p);
            if(a==1)
            {
                for(i=0;i<6;i++)
                {
                    p=p->last;
                }
            }
            a=0;
            delay(80);
        }
        if(x2>670&&x2<=780&&y2>=277&&y2<=316&&buttons==1)
        {
            showhzex(0);
            showhzex(1);
            free_head1(l);
            showtype(l,1);//显示不同类型的商品  类型1
            p=l->next;
        }
        if(x2>670&&x2<=780&&y2>=337&&y2<=370&&buttons==1)
        {
            showhzex(0);
            showhzex(2);
            free_head1(l);
            showtype(l,2);//显示不同类型的商品  类型2
            p=l->next;
        }
        if(x2>670&&x2<=780&&y2>=395&&y2<=425&&buttons==1)
        {
            showhzex(0);
            showhzex(3);
            free_head1(l);
            showtype(l,3);//显示不同类型的商品  类型3
            p=l->next;
        }
        if(x2>670&&x2<=780&&y2>=443&&y2<480&&buttons==1)
        {
            showhzex(0);
            showhzex(4);
            free_head1(l);
            showtype(l,4);//显示不同类型的商品  类型4
            p=l->next;
        }
        anniu(x2,y2,buttons,&mode);
	}
}

void exh_bk()
{
	unsigned int color;
	color=get16color(0x000000);
	put_pic(0,0,"exhbk.bmp",1);
	/*
	drawline(30,180,30,580,color);
	drawline(30,580,630,580,color);
	drawline(630,580,630,180,color);
	drawline(630,180,30,180,color);
	drawline(30,380,630,380,color);
	drawline(230,180,230,580,color);
	drawline(430,180,430,580,color);*/
	put_pic(689,188,"up1.bmp",0);
	put_pic(689,497,"down1.bmp",0);
	color=get16color(0xf0f8ff);
	drawellipse(720,70,46,30,color,0);
	hz(694,58,"返回",color,24);
	drawellipse(570,70,46,30,color,0);
	hz(544,58,"购物",color,24);
}

void showgoods(GOODS *l)  //传入得指针指向第一个商品节点，而非指向头结点
{
    GOODS *p;
    int i;
    file_open(l,"cfile\\guoshu.txt");
    for(i=0;i<3;i++)
    {
        drawbar(200*i+32,182,200*i+227,375,0xffff);
    }
    for(i=0;i<3;i++)
    {
        drawbar(200*i+32,382,200*i+227,575,0xffff);
    }
    p=l->next;
    put_pic(40,183,p->tlujing,1);
    hz(110,330,p->name,0x0000,16);
    put_asc(105,350,2,2,p->price,0x0000);
    p=p->next;
    put_pic(240,183,p->tlujing,1);
    hz(310,330,p->name,0x0000,16);
    put_asc(305,350,2,2,p->price,0x0000);
    p=p->next;
    put_pic(440,183,p->tlujing,1);
    hz(510,330,p->name,0x0000,16);
    put_asc(505,350,2,2,p->price,0x0000);
    p=p->next;
    put_pic(40,383,p->tlujing,1);
    hz(110,530,p->name,0x0000,16);
    put_asc(105,550,2,2,p->price,0x0000);
    p=p->next;
    put_pic(240,383,p->tlujing,1);
    hz(310,530,p->name,0x0000,16);
    put_asc(305,550,2,2,p->price,0x0000);
    p=p->next;
    put_pic(440,383,p->tlujing,1);
    hz(510,530,p->name,0x0000,16);
    put_asc(505,550,2,2,p->price,0x0000);
    p=NULL;
}

void showtype(GOODS *l,int i)  //传入得指针指向第一个商品节点，而非指向头结点
{
    GOODS *p;
    int j;
    for(j=0;j<3;j++)
    {
        drawbar(200*j+32,182,200*j+227,375,0xffff);
    }
    for(j=0;j<3;j++)
    {
        drawbar(200*j+32,382,200*j+227,575,0xffff);
    }
    switch(i)
    {
        case 1: file_open(l,"cfile\\guoshu.txt");
                break;
        case 2: file_open(l,"cfile\\shipin.txt");
                break;
        case 3: file_open(l,"cfile\\xihu.txt");
                break;
        case 4: file_open(l,"cfile\\jiaju.txt");
                break;
    }
    p=l->next;
    put_pic(40,183,p->tlujing,1);
    hz(110,330,p->name,0x0000,16);
    put_asc(105,350,2,2,p->price,0x0000);
    p=p->next;
    put_pic(240,183,p->tlujing,1);
    hz(310,330,p->name,0x0000,16);
    put_asc(305,350,2,2,p->price,0x0000);
    p=p->next;
    put_pic(440,183,p->tlujing,1);
    hz(510,330,p->name,0x0000,16);
    put_asc(505,350,2,2,p->price,0x0000);
    p=p->next;
    put_pic(40,383,p->tlujing,1);
    hz(110,530,p->name,0x0000,16);
    put_asc(105,550,2,2,p->price,0x0000);
    p=p->next;
    put_pic(240,383,p->tlujing,1);
    hz(310,530,p->name,0x0000,16);
    put_asc(305,550,2,2,p->price,0x0000);
    p=p->next;
    put_pic(440,383,p->tlujing,1);
    hz(510,530,p->name,0x0000,16);
    put_asc(505,550,2,2,p->price,0x0000);
}

int downpage(GOODS *l)  //调用该函数即向下翻页，并令l指向翻页后页面的第一个商品节点
{
    int i;
    GOODS *p;
    p=l;
    for(i=0;i<6;i++)
    {
        if(p!=NULL)
        {
            p=p->next;
        }
        else
        {
            return 0;
        }
    }
    for(i=0;i<3;i++)
    {
        drawbar(200*i+32,182,200*i+227,375,0xffff);
    }
    for(i=0;i<3;i++)
    {
        drawbar(200*i+32,382,200*i+227,575,0xffff);
    }
    for(i=0;i<3;i++)
    {
        if(p!=NULL)
        {
            put_pic(200*i+40,183,p->tlujing,1);
            hz(200*i+110,330,p->name,0x0000,16);
            put_asc(200*i+105,350,2,2,p->price,0x0000);
            p=p->next;
        }
        else
        {
            put_pic(200*i+30,180,"cfile\\3.bmp",1);
        }
    }
    for(i=0;i<3;i++)
    {
        if(p!=NULL)
        {
            put_pic(200*i+40,383,p->tlujing,1);
            hz(200*i+110,530,p->name,0x0000,16);
            put_asc(200*i+105,550,2,2,p->price,0x0000);
            p=p->next;
        }
        else
        {
            put_pic(200*i+30,380,"cfile\\3.bmp",1);
        }
    }
    return 1;
}

int uppage(GOODS *l)  //调用该函数即向上翻页，并令l指向翻页后页面的第一个商品节点
{
    int i;
    GOODS *p;
    p=l;
    for(i=0;i<6;i++)
    {
        if(p!=NULL)
        {
            p=p->last;
        }
        else
        {
            return 0;
        }
    }
    for(i=0;i<3;i++)
    {
        drawbar(200*i+32,182,200*i+227,375,0xffff);
    }
    for(i=0;i<3;i++)
    {
        drawbar(200*i+32,382,200*i+227,575,0xffff);
    }
    for(i=0;i<3;i++)
    {
        put_pic(200*i+40,183,p->tlujing,1);
        hz(200*i+110,330,p->name,0x0000,16);
        put_asc(200*i+105,350,2,2,p->price,0x0000);
        p=p->next;
    }
    for(i=0;i<3;i++)
    {
        put_pic(200*i+40,383,p->tlujing,1);
        hz(200*i+110,530,p->name,0x0000,16);
        put_asc(200*i+105,550,2,2,p->price,0x0000);
        p=p->next;
    }
    return 1;
}

void showhzex(int flag)
{
	unsigned int color;
	color=get16color(0xFFD700);
	switch(flag)
		{
			case 0:
				hz(680,284,"果蔬",0x0000,24);
				hz(680,337,"食品饮料",0x0000,24);
				hz(680,394,"洗护",0x0000,24);
				hz(680,450,"家居用品",0x0000,24);
				break;
			case 1:
				hz(680,284,"果蔬",color,24);
			   	break;
			case 2:
				hz(680,337,"食品饮料",color,24);
				break;
			case 3:
				hz(680,394,"洗护",color,24);
				break;
			case 4:
				hz(680,450,"家居用品",color,24);
				break;
		}
}

void anniu(int x2,int y2,int buttons,int *mode)
{
	if(x2>670&&x2<=780&&y2>=277&&y2<=316&&*mode!=1)
	{
		showhzex(0);
		showhzex(1);
		*mode=1;
	}
	if(x2>670&&x2<=780&&y2>=337&&y2<=370&&*mode!=2)
	{
		showhzex(0);
		showhzex(2);
		*mode=2;
	}
	if(x2>670&&x2<=780&&y2>=395&&y2<=425&&*mode!=3)
	{
		showhzex(0);
		showhzex(3);
		*mode=3;
	}
	if(x2>670&&x2<=780&&y2>=443&&y2<480&&*mode!=4)
	{
		showhzex(0);
		showhzex(4);
		*mode=4;
	}
}
