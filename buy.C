#include"head.h"
#include"welcome.h"
#include"buy.h"
#include"tuxing.h"
#include"input.h"
#include"mouse.h"
#include"wenjian.h"
#include"gukelian.h"
#include"gukewen.h"
#include"gouwu.h"
#include"hanzi.h"

void buy(int *flag,int *whobuy)
{
	unsigned int color;
	int x1,y1,x2,y2,buttons;
	int i,j;
	int a;  //判断结算过程中是否能够找到顾客
	int cau=0,dataa=0;
    char str1[15];
    GOODS *l,*p,*f,*h,*h1;
    l=creat_list();
    h=creat_list();
    h1=h;
    f=NULL;
	buybk(whobuy);//画购物界面。。。
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
		if(x2>634&&y2>565&&x2<800&&y2<600&&buttons==1)	//点击右下角返回
		{
			free_head1(h);
				free(h);
			if(*whobuy==1)
			{
				*flag=7;//回到shop界面
				return;
			}
			else
			{
				*flag=2;
				return;
			}
			delay(80);
		}
		if(x2>68&&y2>526&&x2<337&&y2<564&&buttons==1&&(*whobuy==0))	//进入展示页面
		{
				*flag=4;//回到展示页面
				free_head1(h);
				free(h);
				return;
		}
        if(x2>457&&y2>397&&x2<597&&y2<434&&buttons==1)	//点击左上按钮加入购物车
		{
		    if(f!=NULL)
            {
                h1->next=f;
                f->last=h1;
                h1=h1->next;
                f=NULL;
                put_asc(43,203+cau*60,1,1,h1->bianhao,0x0000);
                hz(146,203+cau*60,h1->name,0x0000,16);
                hz(246,203+cau*60,h1->leixing,0x0000,16);
                put_asc(346,203+cau*60,1,1,h1->price,0x0000);
                cau++;
                delay(300);
            }
		}
		if(x2>635&&y2>400&&x2<775&&y2<434&&buttons==1)	//点击右上按钮删除商品
		{
		    listdelete(h,dataa-1);
		    for(h1=h;h1->next!=NULL;h1=h1->next);
		    drawbar(21,180,419,479,0xeffd);
		    for(i=0;i<=6;i++)
                drawline(20,120+60*i,420,120+60*i,0);
            for(i=0;i<=4;i++)
                drawline(20+100*i,120,20+100*i,480,0);
            zhanshi(h);
            dataa=0;
            cau--;
            delay(300);
		}
		if(x2>458&&y2>458&&x2<599&&y2<496&&buttons==1)	//点击左下按钮清空购物车
		{
            free_head1(h);
            free(h);
            *flag=13;
		   	return;
		}
		if(x2>635&&y2>459&&x2<775&&y2<496&&buttons==1)	//点击右下按钮购物结算
		{
            float su;
            int jife;
            char sss1[10],sss2[10];
            put_pic(90,220,"shuruk.bmp",1);
            str1[0]='\0';
            input(157,307,8,0,0x0000,0xffff,1,str1);
            su=jiesuan(h,"cfile\\tongji.txt",str1,&jife);
            hz(94,600,"结算成功",0x0000,24);
            free_head1(h);
            free(h);
            itoa(jife,sss1,10);
            gcvt(su,7,sss2);
            drawbar(21,120,419,479,0xeffd);
            hz(94,200,"本次购物的价格",0x0000,24);
            put_asc(100,240,2,2,sss2,0x0000);
            hz(94,300,"所得积分",0x0000,24);
            put_asc(100,340,2,2,sss1,0x0000);
            hz(94,400,"按任意键继续购物",0x0000,24);
            getch();
            *flag=13;
		   	return;
		}
		if(x2>503&&y2>155&&x2<692&&y2<184&&buttons==1)	//点击搜索框
		{
		    drawbar(522,164,685,182,0xffff);
		    str1[0]='\0';
		    input(523,165,8,0,0x0000,0xffff,1,str1);
		}
		if(x2>690&&y2>155&&x2<734&&y2<184&&buttons==1)	//点击搜索按钮
		{
		    int gh=0;
		    switch(str1[0])
		    {
		        case 'A': file_open(l,"cfile\\jiaju.txt");
                          break;
                case 'B': file_open(l,"cfile\\shipin.txt");
                          break;
                case 'C': file_open(l,"cfile\\guoshu.txt");
                          break;
                case 'D': file_open(l,"cfile\\xihu.txt");
                          break;
                default: hz(607,165,"输入错误！",0x0000,16);
                        gh=1;
		    }
		    drawbar(675,218,746,236,0xffff);
		    drawbar(675,255,746,278,0xffff);
		    drawbar(675,305,729,330,0xffff);
            for(p=l->next;p!=NULL;p=p->next)
            {
                if(strcmp(p->bianhao,str1)==0)
                {
                    put_pic(485,200,p->tlujing,1);
                    hz(677,222,p->name,0x0000,16);
                    hz(677,260,p->leixing,0x0000,16);
                    put_asc(677,305,2,2,p->price,0x0000);
                    f=(GOODS *)malloc(sizeof(GOODS));
                    change(f,p);
                    f->last=NULL;
                    f->next=NULL;
                    break;
                }
            }
            if(p==NULL&&gh==0)
            {
                hz(607,165,"商品售空",0x0000,16);
            }
            free_head1(l);
        }
		if(x2>110&&y2>515&&x2<250&&y2<580&&buttons==1&&(*whobuy==1))	//点击进入商品界面
		{
			*flag=12;
			free_head1(h);
			free(h);
			delay(80);
		   	return;
		}
		if(x2>390&&y2>515&&x2<530&&y2<580&&buttons==1&&(*whobuy==1))	//点击进入统计界面
		{
			*flag=14;
			free_head1(h);
			free(h);
			delay(80);
		   	return;
		}

        for(j=1;j<=6;j++)
        {
            if(x2>20&&y2>60+60*j&&x2<420&&y2<120+60*j&&buttons==1)//如果点到i行j列的话
            {
                unsigned int color1;
                color1=get16color(0xFFD700);
                if(dataa!=0)
                {
                    drawline(20,120+60*dataa,420,120+60*dataa,0);
                    drawline(20,120+60*(dataa-1),420,120+60*(dataa-1),0);
                    drawline(20,120+60*(dataa-1),20,120+60*dataa,0);
                    drawline(420,120+60*(dataa-1),420,120+60*dataa,0);
                }
                dataa=j;
                drawline(20,120+60*dataa,420,120+60*dataa,color1);
                drawline(20,120+60*(dataa-1),420,120+60*(dataa-1),color1);
                drawline(20,120+60*(dataa-1),20,120+60*dataa,color1);
                drawline(420,120+60*(dataa-1),420,120+60*dataa,color1);
            }
        }
	}
}
void buybk(int *whobuy)//画商品界面
{
	int i;
	if(*whobuy==1)
		put_pic(0,0,"buy.bmp",1);
	else
		put_pic(0,0,"zizhu.bmp",1);
	put_pic(488,152,"search.bmp",0) ;

	hz(485,404,"加入购物车",0xffff,16);
	hz(664,404,"删除商品",0xffff,16);
	hz(485,464,"清空购物车",0xffff,16);
	hz(664,464,"购物结算",0xffff,16);
	if(*whobuy==1)
	{
		drawellipse(180,545,70,30,0xffff,0);
		hz(180-34,545-8,"商品页面",0xffff,16);
		drawellipse(460,545,70,30,0xffff,0);
		hz(460-34,545-8,"统计页面",0xffff,16);
	}
	for(i=0;i<=6;i++)
		drawline(20,120+60*i,420,120+60*i,0);
	for(i=0;i<=4;i++)
		drawline(20+100*i,120,20+100*i,480,0);
    hz(22,134,"商品编号",0x0000,24);
    hz(145,134,"品名",0x0000,24);
    hz(245,134,"类型",0x0000,24);
    hz(345,134,"售价",0x0000,24);
}

int zhanshi(GOODS *l)
{
    GOODS *p;
    int i;
    for(i=0,p=l->next;p!=NULL;p=p->next,i++)
    {
        put_asc(43,203+i*60,1,1,p->bianhao,0x0000);
        hz(146,203+i*60,p->name,0x0000,16);
        hz(246,203+i*60,p->leixing,0x0000,16);
        put_asc(346,203+i*60,1,1,p->price,0x0000);
    }
    return 0;
}
