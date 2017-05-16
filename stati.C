#include"head.h"
#include"welcome.h"
#include"stati.h"
#include"tuxing.h"
#include"tongji.h"
#include"mouse.h"
#include"hanzi.h"
#include"wenjian.h"
#include"gouwu.h"
#include"input.h"

void statistics_count(int *flag)
{
	unsigned int color;
	int x1,y1,x2,y2,buttons;
	int i,j;
	int a;  //判断是否翻页成功
	int cau=0,dataa=0;
	GOODS *l,*p,*h,*f,*h1;
	int mode=0;//默认推荐
	char str1[15];
	statibk();//画统计界面。。。
	//drawanniupic(mode);
	cpymouse(0,0);
	l=NULL;
	p=NULL;
	f=NULL;
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
		if(x2>710&&y2>560&&x2<800&&y2<600&&buttons==1)	//点击右下角返回
		{
            *flag=7;//回到shop界面
            if(l!=NULL)
            {
                free_head1(l);
                free(l);
                l=NULL;
            }
            delay(80);
            return;
		}
        if(x2>628&&y2>160&&x2<768&&y2<200&&buttons==1&&mode!=1)	//点击 按钮1
        {
            put_pic(0,105,"copy7.bmp",1);                       //设置遮盖 最高105最低覆盖520最左0最右600
            drawanniupic1(&l);//画界面
            mode=1;
            p=l->next;
        }
        if(x2>628&&y2>275&&x2<768&&y2<315&&buttons==1&&mode!=2)	//点击 按钮2
        {
            put_pic(0,105,"copy7.bmp",1);                      //设置遮盖 最高105最低覆盖520最左0最右600
            drawanniupic2(&l,&h);//画界面
            p=l;
            h1=h;
            mode=2;
        }
        if(x2>628&&y2>390&&x2<768&&y2<430&&buttons==1&&mode!=3)	//点击 按钮3
        {
            put_pic(0,105,"copy7.bmp",1);                          //设置遮盖 最高105最低覆盖520最左0最右600
            drawanniupic3(&l);//画界面
            mode=3;
        }
		if(mode==1)
        {
            if(x2>55&&y2>460&&x2<109&&y2<514&&buttons==1)//点击左翻
            {
                a=zuofan(p);
                if(a==1)
                {
                    for(i=0;i<6;i++)
                    {
                        p=p->last;
                    }
                }
                a=0;
            }
            if(x2>470&&y2>460&&x2<524&&y2<514&&buttons==1)//点击右翻
            {
                a=youfan(p);
                if(a==1)
                {
                    for(i=0;i<6;i++)
                    {
                        p=p->next;
                    }
                }
                a=0;
            }
            if(x2>230&&y2>470&&x2<330&&y2<510&&buttons==1)//点击一键进货
            {
            	char hzsr[4][30]={"一键进货成功","正在紧急配货中","预计明天中午可送达","按任意键返回统计界面"};
                cunhuozeng(l,"40");
                free_head1(l);
                free(l);
                drawbar(0,120,560,460,0xeffd);
                hz(120,160,hzsr[0],0x0000,24);
                delay(350);
                hz(120,200,hzsr[1],0x0000,24);
                delay(350);
                hz(120,240,hzsr[2],0x0000,24);
                delay(350);
                hz(120,280,hzsr[3],0x0000,24);
                getch();
                *flag=14;
                return;
            }
        }
        else if(mode==2)
        {
            if(x2>50&&y2>127&&x2<228&&y2<157&&buttons==1)	//点击搜索框
            {
                drawbar(65,130,227,152,0xffff);
                str1[0]='\0';
                input(66,132,8,0,0x0000,0xffff,1,str1);
            }
            if(x2>240&&y2>127&&x2<270&&y2<150&&buttons==1)	//点击搜索按钮
            {
            	char openfile[4][25]={"cfile\\jiaju.txt","cfile\\shipin.txt","cfile\\guoshu.txt","cfile\\xihu.txt"};
                switch(str1[0])
                {
                    case 'A': file_open(h,openfile[0]);
                            break;
                    case 'B': file_open(h,openfile[1]);
                            break;
                    case 'C': file_open(h,openfile[2]);
                            break;
                    case 'D': file_open(h,openfile[3]);
                            break;
                    default: hz(153,131,"输入错误！",0x0000,16);
                }

                drawbar(509,141,579,163,0xffff);
                drawbar(509,183,579,205,0xffff);
                drawbar(509,224,561,250,0xffff);
                for(h1=h->next;h1!=NULL;h1=h1->next)
                {
                    if(strcmp(h1->bianhao,str1)==0)
                    {
                        put_pic(312,133,h1->tlujing,1);
                        hz(512,143,h1->name,0x0000,16);
                        hz(512,183,h1->leixing,0x0000,16);
                        put_asc(512,223,2,2,h1->cunhuo,0x0000);
                        f=(GOODS *)malloc(sizeof(GOODS));
                        change(f,h1);
                        f->last=NULL;
                        f->next=NULL;
                        break;
                    }
                }
                free_head1(h);
                free(h);
                h=creat_list();
            }
            if(x2>29&&y2>202&&x2<143&&y2<231&&buttons==1)	//点击添加按钮
            {
                if(f!=NULL)
                {
                    p->next=f;
                    f->last=p;
                    p=p->next;
                    f=NULL;
                    put_asc(25,380+cau*50,1,1,p->bianhao,0x0000);
                    hz(105,380+cau*50,p->name,0x0000,16);
                    hz(169,380+cau*50,p->leixing,0x0000,16);
                    put_asc(265,380+cau*50,1,1,p->price,0x0000);
                    put_asc(345,380+cau*50,1,1,p->jinjia,0x0000);
                    put_asc(425,380+cau*50,1,1,p->cunhuo,0x0000);
                    put_asc(505,380+cau*50,1,1,p->xiaoliang,0x0000);
                    cau++;
                    delay(300);
                }
            }
            if(x2>178&&y2>201&&x2<291&&y2<229&&buttons==1)	//点击删除按钮
            {
                listdelete(l,dataa);
                drawbar(0,368,560,510,0xeffd);
                for(i=4;i<=8;i++)
                    drawline(0,110+50*i,560,110+50*i,0);
                for(i=0;i<=7;i++)
                    drawline(80*i,310,80*i,510,0);
                zhanshi1(l);
                dataa=0;
                cau--;
                delay(300);
            }
            if(x2>30&&y2>254&&x2<144&&y2<286&&buttons==1)	//点击清空按钮
            {
                free_head(&l);
                l=creat_list();
                p=l;
                dataa=0;
                cau=0;
                drawbar(0,368,560,510,0xeffd);
                for(i=4;i<=8;i++)
                    drawline(0,110+50*i,560,110+50*i,0);
                for(i=0;i<=7;i++)
                    drawline(80*i,310,80*i,510,0);
                delay(300);

            }
            if(x2>178&&y2>257&&x2<292&&y2<284&&buttons==1)	//点击保存按钮
            {
            	char hzsr[4][30]={"进货成功","正在紧急配货中","预计明天中午可送达","按任意键返回统计界面"};
                cunhuozeng(l,"50");
                free_head1(l);
                free(l);
                drawbar(0,310,560,510,0xeffd);
                hz(120,320,hzsr[0],0x0000,24);
                delay(350);
                hz(120,360,hzsr[1],0x0000,24);
                delay(350);
                hz(120,400,hzsr[2],0x0000,24);
                delay(350);
                hz(120,440,hzsr[3],0x0000,24);
                getch();
                *flag=14;
                return;
            }
            for(j=1;j<=3;j++)
            {
                if(x2>0&&y2>300+50*j&&x2<560&&y2<350+50*j&&buttons==1)//如果点到i行j列的话
                {
                    unsigned int color1;
                    color1=get16color(0xFFD700);
                    if(dataa!=0)
                    {
                        drawline(0,360+50*dataa,560,360+50*dataa,0);
                        drawline(0,360+50*(dataa-1),560,360+50*(dataa-1),0);
                        drawline(0,360+50*(dataa-1),0,360+50*dataa,0);
                        drawline(560,360+50*(dataa-1),560,360+50*dataa,0);
                    }
                    dataa=j;
                    drawline(0,360+50*dataa,560,360+50*dataa,color1);
                    drawline(0,360+50*(dataa-1),560,360+50*(dataa-1),color1);
                    drawline(0,360+50*(dataa-1),0,360+50*dataa,color1);
                    drawline(560,360+50*(dataa-1),560,360+50*dataa,color1);
                }
            }
        }
		if(x2>110&&y2>505&&x2<250&&y2<590&&buttons==1)	//点击进入商品界面
		{
			*flag=12;
			if(l!=NULL)
            {
                free_head1(l);
                free(l);
            }
            delay(80);
		   	return;
		}
		if(x2>390&&y2>505&&x2<530&&y2<590&&buttons==1)	//点击进入购买界面
		{
			*flag=13;
			if(l!=NULL)
            {
                free_head1(l);
                free(l);
            }
            delay(80);
		   	return;
		}
	}
}
void statibk()//画商品界面
{
	int i;
	put_pic(0,0,"stati.bmp",1);

	drawellipse(180,555,70,30,0xffff,0);
	hz(180-34,555-8,"商品页面",0xffff,16);
	drawellipse(460,555,70,30,0xffff,0);
	hz(460-34,555-8,"购买页面",0xffff,16);
}

void drawanniupic1(GOODS **l)
{
	char hzsr[][10]={"商品编号","品名","类型","售价","进价","存货","销量"};
	int i;
	GOODS *p;
    drawbar(0,110,560,460,0xeffd); //80*50黄金比例格子
    for(i=0;i<=7;i++)
        drawline(0,110+50*i,560,110+50*i,0);
    for(i=0;i<=7;i++)
        drawline(80*i,110,80*i,460,0);
    hz(12,130,hzsr[0],0x0000,16);
    for(i=1;i<=6;i++)
    	hz(20+80*i,130,hzsr[i],0x0000,16);
    drawellipse(280,490,50,20,0xffff,0);
    hz(280-32-2,490-8,"一键进货",0x0000,16);
    put_pic(55,460,"left.bmp",0);
    put_pic(470,460,"right.bmp",0);
    if(*l!=NULL)
    {
        free_head(l);
    }
    *l=dinghuotuijian("cfile\\TONGJI.txt");
    p=(*l)->next;
    for(i=0;i<6&&p!=NULL;i++)
    {
        put_asc(20,184+i*50,1,1,p->bianhao,0x0000);
        hz(100,184+i*50,p->name,0x0000,16);
        hz(175,184+i*50,p->leixing,0x0000,16);
        put_asc(258,184+i*50,1,1,p->price,0x0000);
        put_asc(345,184+i*50,1,1,p->jinjia,0x0000);
        put_asc(425,184+i*50,1,1,p->cunhuo,0x0000);
        put_asc(505,184+i*50,1,1,p->xiaoliang,0x0000);
        p=p->next;
    }
}

void drawanniupic2(GOODS **l,GOODS **h)   //此处对l的初始化可能会出现未知的错误
{
	int i;
	char hzsr[][15]={"商品编号","品名","类型","售价","进价","存货","销量","添加","删除","清空","保存"};
	if(*l!=NULL)
    {
        free_head(l);
        *l=creat_list();
    }
    else
    {
        *l=creat_list();
    }
    *h=creat_list();
    put_pic(19,191,"anniu1.bmp",1);
    put_pic(31,122,"search.bmp",0);//搜索框内部颜色 f7f7f7
    drawbar(0,310,560,510,0xeffd);
    for(i=4;i<=8;i++)
        drawline(0,110+50*i,560,110+50*i,0);
    for(i=0;i<=7;i++)
        drawline(80*i,310,80*i,510,0);
    hz(9,330,hzsr[0],0x0000,16);
    for(i=1;i<=6;i++)
        hz(25+80*i,330,hzsr[i],0x0000,16);
    hz(65,206,hzsr[7],0x0000,16);
    hz(214,206,hzsr[8],0x0000,16);
    hz(65,262,hzsr[9],0x0000,16);
    hz(214,262,hzsr[10],0x0000,16);
}

void drawanniupic3(GOODS **l)
{
	float a,b,c;
	char a1[10],b1[10],c1[10];
	if(*l!=NULL)
    {
        free_head(l);
    }
    *l=creat_list();
    file_open(*l,"cfile\\TONGJI.txt");
    a=xiaoshoue(*l);
    b=chengbene(*l);
    c=shourue(*l);
    gcvt(a,7,a1);
    gcvt(b,7,b1);
    gcvt(c,7,c1);
    hz(120,160,"总的销售额为：",0x0000,24);
    put_asc(140,200,2,2,a1,0x0000);
    hz(120,240,"总的销售成本为：",0x0000,24);
    put_asc(140,280,2,2,b1,0x0000);
    hz(120,320,"总的收入为：",0x0000,24);
    put_asc(140,360,2,2,c1,0x0000);
    free_head(l);
    *l=NULL;
}


int youfan(GOODS *l)  //调用该函数即向下翻页，并令l指向翻页后页面的第一个商品节点
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
    drawbar(0,166,560,460,0xeffd); //80*50黄金比例格子
    for(i=0;i<=7;i++)
        drawline(0,110+50*i,560,110+50*i,0);
    for(i=0;i<=7;i++)
        drawline(80*i,110,80*i,460,0);
    for(i=0;i<6;i++)
    {
        if(p!=NULL)
        {
            put_asc(20,184+i*50,1,1,p->bianhao,0x0000);
            hz(100,184+i*50,p->name,0x0000,16);
            hz(175,184+i*50,p->leixing,0x0000,16);
            put_asc(258,184+i*50,1,1,p->price,0x0000);
            put_asc(345,184+i*50,1,1,p->jinjia,0x0000);
            put_asc(425,184+i*50,1,1,p->cunhuo,0x0000);
            put_asc(505,184+i*50,1,1,p->xiaoliang,0x0000);
            p=p->next;
        }
        else
        {
            break;
        }
    }
    return 1;
}

int zuofan(GOODS *l)  //调用该函数即向上翻页，并令l指向翻页后页面的第一个商品节点
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
    drawbar(0,166,560,460,0xeffd); //80*50黄金比例格子
    for(i=0;i<=7;i++)
        drawline(0,110+50*i,560,110+50*i,0);
    for(i=0;i<=7;i++)
        drawline(80*i,110,80*i,460,0);
    for(i=0;i<6;i++)
    {
        put_asc(20,184+i*50,1,1,p->bianhao,0x0000);
        hz(100,184+i*50,p->name,0x0000,16);
        hz(175,184+i*50,p->leixing,0x0000,16);
        put_asc(258,184+i*50,1,1,p->price,0x0000);
        put_asc(345,184+i*50,1,1,p->jinjia,0x0000);
        put_asc(425,184+i*50,1,1,p->cunhuo,0x0000);
        put_asc(505,184+i*50,1,1,p->xiaoliang,0x0000);
        p=p->next;
    }
    return 1;
}

int zhanshi1(GOODS *l)
{
    GOODS *p;
    int i;
    for(i=0,p=l->next;p!=NULL;p=p->next,i++)
    {
        put_asc(25,380+i*50,1,1,p->bianhao,0x0000);
        hz(105,380+i*50,p->name,0x0000,16);
        hz(169,380+i*50,p->leixing,0x0000,16);
        put_asc(265,380+i*50,1,1,p->price,0x0000);
        put_asc(345,380+i*50,1,1,p->jinjia,0x0000);
        put_asc(425,380+i*50,1,1,p->cunhuo,0x0000);
        put_asc(505,380+i*50,1,1,p->xiaoliang,0x0000);
    }
    return 1;
}

