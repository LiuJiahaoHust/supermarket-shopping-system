#include"head.h"
#include"welcome.h"
#include"userinf.h"
#include"tuxing.h"
#include"gukewen.h"
#include"gukelian.h"
#include"wenjian.h"
#include"mouse.h"
#include"hanzi.h"

void userinf(int *flag)
{
	CUST *l;
    int x1,y1,x2,y2,buttons,sta;
   	x1=y1=x2=y2=buttons=sta=0;//文件处理部分    
    l=creat_cust();//                                                            给l申请了空间 需freehead释放再free释放 
    gukefile_open(l,"cfile\\guke.txt");  
	drawuserinf(l,&sta);//绘图部分 
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
		if(x2>623&&y2>159&&x2<729&&y2<205&&buttons==1)//点击上翻
		{
			int i;
			if(sta!=0)
			{
				sta--;
				drawbar(20,120+76,580,500,0xeffd);
				for(i=0;i<=5;i++)//heng 
					drawline(20,120+76*i,580,120+76*i,0);       
				for(i=0;i<=4;i++)//shu 
					drawline(20+140*i,120,20+140*i,500,0);
				showuserinf(l,&sta);
			}
		}
		if(x2>623&&y2>400&&x2<729&&y2<450&&buttons==1)//点击下翻
		{
			int i;
			sta++;
			drawbar(20,120+76,580,500,0xeffd);
			for(i=0;i<=5;i++)//heng 
				drawline(20,120+76*i,580,120+76*i,0);       
			for(i=0;i<=4;i++)//shu 
				drawline(20+140*i,120,20+140*i,500,0);
			showuserinf(l,&sta);
		}
		if(x2>660&&y2>540&&x2<800&&y2<600&&buttons==1)//回到商户选择界面 
		{
			*flag=7;
			free_custhead(l);
			delay(300);
			//free(l);
			return;
		}
		if(x2>202&&y2>544&&x2<424&&y2<590&&buttons==1)//显示advice和评分 
		{
			showadvice();
			if(getchar()==' ')
			{
				FILE *fp1=NULL,*fp2=NULL;
				if((fp1=fopen("cfile\\class.txt","w"))==NULL)
   				{
     				SET_SVGA_MODE(0x03);
       				printf("cant open userinf");
        			exit(1);
    			}
   				if((fp2=fopen("cfile\\advice.txt","w"))==NULL)
    			{
        			SET_SVGA_MODE(0x03);
       				printf("cant open userinf");
       				exit(1);
    			}
    			fputs("\0",fp1);
    			fputs("\0",fp2);
   				fclose(fp1);
   				fclose(fp2);   
			}
			else
			{
				delay(1000);
			}
			*flag=16;
			free_custhead(l);
			return;
		}
	}
}

void drawuserinf(CUST *l,int *sta)
{
	int i; 
	char ss[5][8]={"姓名","积分","账号","密码","\0"};
	put_pic(0,0,"userinf.bmp",1);
	drawbar(20,120,580,500,0xeffd);		//140*76格子 4个140 5个76 
	for(i=0;i<=5;i++)//heng 
		drawline(20,120+76*i,580,120+76*i,0);       
	for(i=0;i<=4;i++)//shu 
		drawline(20+140*i,120,20+140*i,500,0);	
    for(i=0;i<=4;i++)
        hz(42+20+140*i,22+120,ss[i],0x0000,24); 
    showuserinf(l,sta);
}

void showuserinf(CUST *l,int *sta)
{
	int j;
	CUST *p=l->next;
	if(*sta!=0)
		for(j=1;j<=4*(*sta);j++)
			{
				if(p==NULL)
				{	
					*sta=*sta-1;
					return;
				}
				p=p->next;
			}
	for(j=0;j<=3&&p!=NULL;j++)
    {
    	hz(42+20+140*0,22+120+76*(j+1),p->name,0x0000,24);
        put_asc(37+20+140*1,17+120+76*(j+1),2,2,p->jifen,0x0000);
        put_asc(37+20+140*2,17+120+76*(j+1),2,2,p->zhanghao,0x0000);
        put_asc(37+20+140*3,17+120+76*(j+1),2,2,p->mima,0x0000);
        p=p->next;
	}
}
void showadvice()
{
	FILE *fp1=NULL,*fp2=NULL;
	char str1[30],str2[256],classstr[4],advicestr[4][65]={"\0","\0","\0","\0"};
	int long_str1,long_str2,i;
	int hang=1,lie=1,hangmax=64,liemax;
	float average=0; 
	if((fp1=fopen("cfile\\class.txt","rt"))==NULL)
    {
        SET_SVGA_MODE(0x03);
        printf("cant open userinf");
        exit(1);
    }
    if((fp2=fopen("cfile\\advice.txt","rt"))==NULL)
    {
        SET_SVGA_MODE(0x03);
        printf("cant open userinf");
        exit(1);
    }
    fgets(str1,30,fp1);
    fgets(str2,256,fp2);
    long_str1=strlen(str1);
    long_str2=strlen(str2);
    fclose(fp1);
    fclose(fp2);   
	drawbar(80,60,720,560,get16color(0xf7ffce));
	hz(140,100,"超市的平均评分为",0,24);
	for(i=1;i<=long_str1;i++)
		average+=str1[i-1]-'0';
	average=average/long_str1;
	classstr[0]=(int)average+'0';
	classstr[1]='.';
	classstr[2]=(int)((average-(int)average)*10)+'0';
	classstr[3]='\0';
	put_asc(365,96,2,2,classstr,0);
	hz(140,180,"下面是客户的评价",0,24);
	if(long_str2==0)
	{
		hz(140,230,"无客户评价",0,24);
	}
	else
	{ 
	liemax=(long_str2-1)/hangmax+1; 
	liemax=2;
	for(lie=1;lie<=liemax;lie++)
		for(i=(lie-1)*64;i<64*lie;i++)
			 {
			 	advicestr[lie-1][i%64]=str2[64*(lie-1)+i%64];
			 	advicestr[lie-1][64]='\0';
			}
	for(i=1;i<=4;i++)
		put_asc(108,180+40*i,1,1,advicestr[i-1],0);
	} 
	hz(150,400,"清除评价信息请按空格",0,24);
	hz(122,440,"保留评价并退出请按其他键",0,24);
}
