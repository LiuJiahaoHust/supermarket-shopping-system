#include"head.h"
#include"welcome.h"
#include"change.h"
#include"tuxing.h"
#include"mouse.h"
#include"wenjian.h"
#include"HANZI.h"
#include"tongji.h"
#include"lianbiao.h"
#include"gouwu.h"
#include"input.h"

//存在序号无法更改的问题

void changegoods(int *flag)
{
	unsigned int color;
	int x1,y1,x2,y2,buttons;
	int i,j,sta=1,a=0;
	int hour,minutenew,minuteold;
	GOODS *l,*p;
	char dis[8][9]={"序列号","编号","品名","类型","售价","进价","存货","销量"};
	changebk(dis);//画change界面。。。
	l=creat_list();
	display(l,&sta);
    p=l->next;
    l=p->last;
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
		if(x2>745&&y2>550&&x2<800&&y2<600&&buttons==1)	//点击右下角返回
		{
				delay(100);
				*flag=7;//回到shop界面
				free_head1(l);
				free(l);
				return;
		}

		if(x2>687&&y2>184&&x2<764&&y2<210&&buttons==1)	//点击销量排序
		{
            sta=1;
            paixu(l,&sta,1);
            p=l->next;
            l=p->last;
            delay(100);
		}
		if(x2>687&&y2>266&&x2<764&&y2<294&&buttons==1)	//点击收入排序
		{
			sta=1;
			paixu(l,&sta,2);
			p=l->next;
            l=p->last;
            delay(100);
		}

		if(x2>687&&y2>348&&x2<764&&y2<376&&buttons==1)	//点击存货排序
		{
			sta=1;
			paixu(l,&sta,3);
            p=l->next;
            l=p->last;
            delay(100);
		}
		if(x2>687&&y2>427&&x2<764&&y2<455&&buttons==1)	//点击查看售空
		{
            sta=1;
            free_head1(l);
            free(l);
            p=NULL;
            sta=0;
            l=jinhuo("cfile\\shipinc.txt","cfile\\shipin.txt");
            p=jinhuo("cfile\\xihuc.txt","cfile\\xihu.txt");
            hebing(l,p);
			free(p);
            p=jinhuo("cfile\\guoshuc.txt","cfile\\guoshu.txt");
            hebing(l,p);
			free(p);
            p=jinhuo("cfile\\jiajuc.txt","cfile\\jiaju.txt");
            hebing(l,p);
            free(p);
            zhans(l,&sta);
            p=l->next;
            l=p->last;
            delay(100);
		}
		if(x2>708&&y2>127&&x2<741&&y2<146&&buttons==1&&sta!=(1+7))	//点击向上翻页按钮
		{
			sta-=7;
		    a=upppy(p,&sta);
            if(a==1)
            {
                for(i=0;i<7;i++)
                {
                    p=p->last;
                }
            }
            a=0;
            delay(80);
		}
		if(x2>708&&y2>496&&x2<741&&y2<516&&buttons==1)	//点击向下翻页按钮
		{
		    a=downppy(p,&sta);
		    if(a==1)
            {
                for(i=0;i<7;i++)
                {
                    p=p->next;
                }
            }
            a=0;
            delay(80);
		}
		if(x2>110&&y2>535&&x2<250&&y2<600&&buttons==1)	//点击进入购物界面
		{
			*flag=13;
			free_head1(l);
			free(l);
			delay(80);
		   	return;
		}
		if(x2>390&&y2>535&&x2<530&&y2<600&&buttons==1)	//点击进入统计界面
		{
			*flag=14;
			free_head1(l);
			free(l);
			delay(80);
		   	return;
		}
        for(j=1;j<=7;j++)
            if(x2>320&&y2>114+52*j&&x2<399&&y2<166+52*j&&buttons==1)//如果点到i行j列的话
            {
                GOODS *p1,*hj,*p2;
                char scd[5],scd1[5];
                hj=creat_list();
                for(p1=p,i=1;i<j&p1!=NULL;p1=p1->next,i++);
                strcpy(scd1,p1->bianhao);
                drawbar(322,116+52*j,397,161+52*j,0xeffd);
                input(345,134+j*52,8,0,0x0000,0xeffd,1,scd);
                switch(scd1[0])
                {
                    case 'A': file_open(hj,"cfile\\jiaju.txt");
                          break;
                    case 'B': file_open(hj,"cfile\\shipin.txt");
                          break;
                    case 'C': file_open(hj,"cfile\\guoshu.txt");
                          break;
                    case 'D': file_open(hj,"cfile\\xihu.txt");
                          break;
                    default: hz(607,165,"输入错误！",0x0000,16);
                }
                for(p2=hj->next;p2!=NULL;p2=p2->next)
                {
                    if(strcmp(p2->bianhao,scd1)==0)
                    {
                        strcpy(p2->price,scd);
                        switch(scd1[0])
                        {
                            case 'A': file_save(hj,"cfile\\jiaju.txt");
                                break;
                            case 'B': file_save(hj,"cfile\\shipin.txt");
                                break;
                            case 'C': file_save(hj,"cfile\\guoshu.txt");
                                break;
                            case 'D': file_save(hj,"cfile\\xihu.txt");
                                break;
                            default: hz(607,165,"输入错误！",0x0000,16);
                        }
                        break;
                    }
                }
                free_head1(hj);
                free(hj);
                hj=creat_list();
                switch(scd1[0])
                {
                    case 'A': file_open(hj,"cfile\\jiajuc.txt");
                          break;
                    case 'B': file_open(hj,"cfile\\shipinc.txt");
                          break;
                    case 'C': file_open(hj,"cfile\\guoshuc.txt");
                          break;
                    case 'D': file_open(hj,"cfile\\xihuc.txt");
                          break;
                    default: hz(607,165,"输入错误！",0x0000,16);
                }
                for(p2=hj->next;p2!=NULL;p2=p2->next)
                {
                    if(strcmp(p2->bianhao,scd1)==0)
                    {
                        strcpy(p2->price,scd);
                        switch(scd1[0])
                        {
                            case 'A': file_save(hj,"cfile\\jiajuc.txt");
                                break;
                            case 'B': file_save(hj,"cfile\\shipinc.txt");
                                break;
                            case 'C': file_save(hj,"cfile\\guoshuc.txt");
                                break;
                            case 'D': file_save(hj,"cfile\\xihuc.txt");
                                break;
                            default: hz(607,165,"输入错误！",0x0000,16);
                        }
                        break;
                    }
                }
                free_head1(hj);
                free(hj);
            }
	}
}

void changebk(char (*p)[9])//画商品界面
{
	int i;
	put_pic(0,0,"change.bmp",1);
	hz(693,189,"销量排序",0xffff,16);
	hz(693,272,"收入排序",0xffff,16);
	hz(693,354,"存货排序",0xffff,16);
	hz(693,433,"查看售空",0xffff,16);
	drawellipse(180,565,70,30,0xffff,0);
	hz(180-34,565-8,"购物页面",0xffff,16);
	drawellipse(460,565,70,30,0xffff,0);
	hz(460-34,565-8,"统计页面",0xffff,16);
	drawline(0,109,640,109,0);
	for(i=1;i<=8;i++)
		drawline(0,114+52*i,640,114+52*i,0);
	for(i=0;i<=8;i++)
		drawline(80*i,110,80*i,530,0);
    for(i=0;i<8;i++)
        hz(17+80*i,130,p[i],0x0000,16);
}

void display(GOODS *l,int *sta)  //传入得指针指向第一个商品节点，而非指向头结点，展示出七个商品
{
    GOODS *p,*pp;
    int i;
    char sta1[5];
    p=creat_list();//给p分配了空间
    file_open(l,"cfile\\jiajuc.txt");
    file_open(p,"cfile\\shipinc.txt");
    hebing(l,p);//不释放p
    file_open(p,"cfile\\guoshuc.txt");
    hebing(l,p);
    file_open(p,"cfile\\xihuc.txt");
    hebing(l,p);
    free(p);//释放p
    pp=l->next;
    for(i=0;i<7;i++)
    {
        itoa(*sta,sta1,10);
        put_asc(30,186+i*52,1,1,sta1,0x0000);
        put_asc(100,186+i*52,1,1,pp->bianhao,0x0000);
        hz(180,186+i*52,pp->name,0x0000,16);
        hz(255,186+i*52,pp->leixing,0x0000,16);
        put_asc(345,186+i*52,1,1,pp->price,0x0000);
        put_asc(425,186+i*52,1,1,pp->jinjia,0x0000);
        put_asc(505,186+i*52,1,1,pp->cunhuo,0x0000);
        put_asc(587,186+i*52,1,1,pp->xiaoliang,0x0000);
        (*sta)++;
        pp=pp->next;
    }
}

int downppy(GOODS *l,int *sta)  //调用该函数即向下翻页，并令l指向翻页后页面的第一个商品节点
{
    int i;
    GOODS *p;
    char sta1[5];
    p=l;
    for(i=0;i<7;i++)
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
    drawbar(1,170,639,529,0xeffd);
    for(i=1;i<=8;i++)
		drawline(0,114+52*i,640,114+52*i,0);
	for(i=0;i<=8;i++)
		drawline(80*i,110,80*i,530,0);
    for(i=0;i<7;i++)
    {
        if(p!=NULL)
        {
            itoa(*sta,sta1,10);
            put_asc(30,186+i*52,1,1,sta1,0x0000);
            put_asc(100,186+i*52,1,1,p->bianhao,0x0000);
            hz(180,186+i*52,p->name,0x0000,16);
            hz(255,186+i*52,p->leixing,0x0000,16);
            put_asc(345,186+i*52,1,1,p->price,0x0000);
            put_asc(425,186+i*52,1,1,p->jinjia,0x0000);
            put_asc(505,186+i*52,1,1,p->cunhuo,0x0000);
            put_asc(587,186+i*52,1,1,p->xiaoliang,0x0000);
            (*sta)++;
            p=p->next;
        }
        else
        {
            break;
        }
    }
    return 1;
}

int upppy(GOODS *l,int *sta)  //调用该函数即向上翻页，并令l指向翻页后页面的第一个商品节点
{
    int i;
    GOODS *p;
    char sta1[5];
    p=l;
    if(p->last->last==NULL)
    {
        return 0;
    }
    drawbar(1,170,639,529,0xeffd);
    for(i=1;i<=8;i++)
		drawline(0,114+52*i,640,114+52*i,0);
	for(i=0;i<=8;i++)
		drawline(80*i,110,80*i,530,0);
    for(i=0;i<7;i++)
    {
        p=p->last;
        (*sta)--;
    }
    for(i=0;i<7;i++)
    {
        itoa(*sta,sta1,10);
        put_asc(30,186+i*52,1,1,sta1,0x0000);
        put_asc(100,186+i*52,1,1,p->bianhao,0x0000);
        hz(180,186+i*52,p->name,0x0000,16);
        hz(255,186+i*52,p->leixing,0x0000,16);
        put_asc(345,186+i*52,1,1,p->price,0x0000);
        put_asc(425,186+i*52,1,1,p->jinjia,0x0000);
        put_asc(505,186+i*52,1,1,p->cunhuo,0x0000);
        put_asc(587,186+i*52,1,1,p->xiaoliang,0x0000);
        (*sta)++;
        p=p->next;
    }
    return 1;
}

int paixu(GOODS *l,int *sta,int n)   //
{
    int i;
    char sta1[5];
    GOODS *p;
    //(*sta)=1;
    free_head1(l);
    //free(l);
    //l=creat_list();
    file_open(l,"cfile\\tongji.txt");
    if(n==1)
        xiaoliangp(l,1);
    else if(n==2)
        shourup(l,1);
    else if(n==3)
        cunhuop(l,1);
    p=(l)->next;
    drawbar(1,170,639,529,0xeffd);
    for(i=1;i<=8;i++)
		drawline(0,114+52*i,640,114+52*i,0);
	for(i=0;i<=8;i++)
		drawline(80*i,110,80*i,530,0);
    for(i=0;i<7&p!=NULL;i++)
    {
        itoa(*sta,sta1,10);
        put_asc(30,186+i*52,1,1,sta1,0x0000);
        put_asc(100,186+i*52,1,1,p->bianhao,0x0000);
        hz(180,186+i*52,p->name,0x0000,16);
        hz(255,186+i*52,p->leixing,0x0000,16);
        put_asc(345,186+i*52,1,1,p->price,0x0000);
        put_asc(425,186+i*52,1,1,p->jinjia,0x0000);
        put_asc(505,186+i*52,1,1,p->cunhuo,0x0000);
        put_asc(587,186+i*52,1,1,p->xiaoliang,0x0000);
        (*sta)++;
        p=p->next;
    }
    return 0;
}

int zhans(GOODS *l,int *sta)
{
    GOODS *p;
    char sta1[5];
    int i;
    p=l->next;
    drawbar(1,170,639,529,0xeffd);
    for(i=1;i<=8;i++)
		drawline(0,114+52*i,640,114+52*i,0);
	for(i=0;i<=8;i++)
		drawline(80*i,110,80*i,530,0);
    for(i=0;i<7&p!=NULL;i++)
    {
        itoa(*sta,sta1,10);
        put_asc(30,186+i*52,1,1,sta1,0x0000);
        put_asc(100,186+i*52,1,1,p->bianhao,0x0000);
        hz(180,186+i*52,p->name,0x0000,16);
        hz(255,186+i*52,p->leixing,0x0000,16);
        put_asc(345,186+i*52,1,1,p->price,0x0000);
        put_asc(425,186+i*52,1,1,p->jinjia,0x0000);
        put_asc(505,186+i*52,1,1,p->cunhuo,0x0000);
        put_asc(587,186+i*52,1,1,p->xiaoliang,0x0000);
        (*sta)++;
        p=p->next;
    }
    return 0;
}
