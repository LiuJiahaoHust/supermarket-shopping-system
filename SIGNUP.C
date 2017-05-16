#include"head.h"
#include"welcome.h"
#include"signup.h"
#include"tuxing.h"
#include"mouse.h"
#include"input.h"
#include"gukelian.h"
#include"gukewen.h"
#include"hanzi.h"
#include"lianbiao.h"

void signup(int *flag)
{
	CUST *l,*p;
	char str1[30],str2[30],str3[30],str4[30];
	char gukefile[]="cfile\\guke.txt";
	unsigned int color=get16color(0xefefef);
    int x1,y1,x2,y2,buttons;
   	x1=y1=x2=y2=buttons=0;
   //文件处理部分 
    l=creat_cust();//                                                            给l申请了空间 需freehead释放再free释放 
    gukefile_open(l,gukefile);     
    for(p=l->next;(p->next)!=NULL;p=p->next)//使p指向尾端 
 	{;}   
	put_pic(0,0,"signup.bmp",1);
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
		if(x2>430&&y2>199&&x2<606&&y2<229&&buttons==1)//点击输入账号 0xefefef
		{
			drawbar(430,199,606,229,color);
            input(440,199+7,8,0,0x0000,color,1,str1);
		}
		if(x2>430&&y2>289&&x2<606&&y2<319&&buttons==1)//点击输入密码 
		{
			drawbar(430,289,606,319,color);
            input(440,289+7,8,1,0x0000,color,1,str2);
		}
		if(x2>430&&y2>379&&x2<606&&y2<409&&buttons==1)//点击再次输入密码 
		{
			drawbar(430,379,606,409,color);
            input(440,379+7,8,1,0x0000,color,1,str3);
		}
		if(x2>430&&y2>469&&x2<606&&y2<499&&buttons==1)//点击邀请码----------先不做 
		{
			drawbar(430,469,606,499,color);
            input(440,469+7,8,1,0x0000,color,1,str4);
		}
		if(x2>334&&y2>531&&x2<468&&y2<576&&buttons==1)//点击确定存入文件 
		{
			if(str1!=NULL&&(strcmp(str2,str3)==0)&&str2!=NULL)
			{
				CUST *q;
				q=(CUST *)malloc(sizeof(CUST));
				strcpy(q->name,"匿名");
				strcpy(q->jifen,"0"); 
				strcpy(q->zhanghao,str1); 
				strcpy(q->mima,str2);
				p->next=q;
				p->next->last=p;
				p->next->next=NULL;
				gukefile_save(l,gukefile); 
				hz(335,331,"保存成功",0,24);
				delay(600); 
				free_custhead(l);
				free(l);	
				*flag=2;
				return;
			}
			else
			{
				hz(335,331,"输入错误",0,24);
				delay(1500);
				free_custhead(l);
				free(l);
				*flag=2;
				return;
			}
		}
		if(x2>564&&y2>546&&x2<800&&y2<600&&buttons==1)//回到主界面 
		{
			free_custhead(l);
			free(l);
			*flag=2;
			return;
		}
	}
}
