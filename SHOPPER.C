#include"head.h"
#include"welcome.h"
#include"shopper.h"
#include"tuxing.h"
#include"input.h"
#include"gukewen.h"
#include"gukelian.h"
#include"hanzi.h"
#include"mouse.h"
#include"lianbiao.h"

void shopper(int *flag)
{
	FILE *fp1=NULL;
	CUST *l,*p;
	int mode=0;
    char str1[50];
    int x1,y1,x2,y2,buttons;
    char zhsr[]="cfile\\zhsr.txt",gukefile[]="cfile\\guke.txt";
   	x1=y1=x2=y2=buttons=0;
   //文件处理部分 
	if((fp1=fopen(zhsr,"r"))==NULL)
    {
        SET_SVGA_MODE(0x03);
		printf("%s",zhsr);
        exit(1);
    }
    l=creat_cust();//                                                            给l申请了空间 需freehead释放再free释放 
    gukefile_open(l,gukefile);     
    fgets(str1,7,fp1);
	fclose(fp1);
    for(p=l->next;p!=NULL;p=p->next)//使p指向那个用户 
    {
        if(strcmp(str1,p->zhanghao)==0)
           {
                break;
            }
    }          
	//绘图部分 
	put_pic(0,0,"guke.bmp",1);
	if(strcmp(p->name,"匿名")!=0)
		hz(216,139,p->name,0,24);
	else
		put_asc(220,141,2,2,p->zhanghao,0);
	hz(350,141,"积分为",0,24);
	put_asc(440,139,2,2,p->jifen,0);
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
		if(x2>345&&y2>218&&x2<551&&y2<267&&buttons==1)//点击积分抽奖 
		{
			*flag=17;
			free_custhead(l);//那个界面再打开一次文件吧，否则传参数需经过主函数（不希望看到）； 
			free(l); 
			return; 
		}
		if(x2>345&&y2>297&&x2<551&&y2<350&&buttons==1)//点击帮助页面 
		{
			*flag=3;
			free_custhead(l);
			free(l); 
			return; 
		}
		if(x2>345&&y2>382&&x2<551&&y2<428&&buttons==1)//点击修改密码  
		{
            char str[50];
            input(325,445,8,1,0x0000,0xffff,1,str);
            if(str[0]=='\0')
            {
            	unsigned int color=get16color(0xff0000);
            	hz(340,460,"密码不能为空",color,24); 
            	delay(1600);
            	*flag=2;
           		 free_custhead(l);
            	free(l); 
				return;
			}
            p->mima[0]='\0';
            strcpy(p->mima,str);
            gukefile_save(l,gukefile);
            *flag=2;
            free_custhead(l);
            free(l); 
			return;
		}
		if(x2>40&&y2>400&&x2<210&&y2<570&&mode!=1)//放在购物车上提醒  
		{
            put_pic(245,519,"copy9.bmp",1);
            mode=1;
		}
		if(!(x2>40&&y2>400&&x2<210&&y2<570)&&mode!=0)//不放在购物车上 返回 
		{
            put_pic(245,519,"copy8.bmp",1);
            mode=0;
		}
		if(x2>40&&y2>400&&x2<210&&y2<570&&buttons==1)//点击购物车自助购物  
		{
            *flag=13;
            free_custhead(l);
            free(l);
			return; 
		}
		if(x2>580&&y2>500&&x2<800&&y2<600&&buttons==1)//回到主界面 
		{			
			free_custhead(l);
			free(l); 
			*flag=2;
			return;
		}
	}
}
