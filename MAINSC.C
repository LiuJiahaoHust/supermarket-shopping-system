#include"head.h"
#include"mainsc.h"
#include"tuxing.h"
#include"welcome.h"
#include"mouse.h"
#include"hanzi.h"
#include"input.h"
#include"gukewen.h"
#include"gukelian.h"
#include"lianbiao.h"

void mainscreen(int *flag)
{
	int x1,y1,x2,y2,buttons,mode=0;
	int i;
	int page_flag=0; //为1时商户登录，为2时用户登录
	char strx[5],stry[5],str[2]; //测试像素点位置
	char shop_acc[10]={0};
	char shop_pas[10]={0};
	char aqm_acc[10]={0};
	x1=y1=x2=y2=buttons=0;
	put_pic(0,0,"main.bmp",1);
	put_pic(125,160,"caidan1.bmp",0);
	put_pic(699,1,"opsign.bmp",0);
	showhzmain(0);
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
			//测试像素点位置再不乱删
			itoa(x2,strx,10);
			itoa(y2,stry,10);
			itoa(buttons,str,10);
			drawbar(100,490,350,550,0xffff);
			put_asc(100,500,2,2,strx,1);
			put_asc(200,500,2,2,stry,1);
			put_asc(300,500,2,2,str,1);
			//测试像素点位置再不乱删
		}
			mainscreendonghua(x2,y2,buttons,&mode,&page_flag);
			if(x2>375&&x2<=475&&y2>=172&&y2<=192&&buttons==1)	//展示
			{
				*flag=4;//展示进入查询界面 无法修改，订制
				return;
			}
			if(x2>475&&x2<=575&&y2>=172&&y2<=192&&buttons==1)	//帮助
			{
				*flag=3;//进入帮助界面
				return;
			}
			if(x2>575&&x2<=670&&y2>=172&&y2<=192&&buttons==1)	//退出
			{
				*flag=1;//进入感谢界面
				return;
			}

			if(x2>180&&y2>340&&x2<445&&y2<370&&buttons==1&&page_flag==1)//商户点击账号框实现功能
			{
			
				input(190,350,8,0,0x0000,0xffff,1,shop_acc); //0明1暗
			}
			if(x2>180&&y2>385&&x2<445&&y2<415&&buttons==1&&page_flag==1)
			{
				input(190,395,8,1,0x0000,0xffff,1,shop_pas);				//商户点击密码框实现功能
			}
			if(x2>360&&y2>450&&x2<445&&y2<480&&buttons==1&&page_flag==1)				//商户点击login实现功能
			{
				char key[10]="admin";
				char errorinf[20]="账号或密码错误"; 
				if(strcmp(shop_acc,key)==0&&strcmp(shop_pas,key)==0)
				{
					*flag=7;
					return;
				}else
				{
					hz(190,430,errorinf,0xffff,16);
					delay(500);
                    *flag=2;
                    return;
				}
			}
			if(x2>527&&y2>416&&x2<610&&y2<440&&buttons==1&&page_flag==1)
			{
				put_pic(0,0,"shsign.bmp",1);//商户点击sign up实现功能 -- 404 not found
				delay(500);
				getch();
				*flag=2;//重新开始此界面。。。
				return;
			}

			if(x2>180&&y2>340&&x2<445&&y2<370&&buttons==1&&page_flag==2)//顾客点击账号框实现功能
			{
				FILE *fp=NULL;
                char str[50];
                char filename[20]="cfile\\zhsr.txt";
                if((fp = fopen(filename, "w"))==NULL)
                {
                    printf("%s",filename);
                    getch();
                    exit(1);
                }
                fclose(fp);
                if((fp=fopen(filename,"w"))==NULL)
                {
                    printf("%s",filename);
                    getch();
                    exit(1);
                }
                input(190,350,8,0,0x0000,0xffff,1,str);
                fputs(str,fp);
                fclose(fp);
			}
			if(x2>180&&y2>385&&x2<445&&y2<415&&buttons==1&&page_flag==2)	//顾客点击密码框实现功能
			{
				FILE *fp=NULL;
                char str[50];
                char filename[20]="cfile\\mmsr.txt";
                if((fp = fopen(filename, "w"))==NULL)
                {
                    printf("%s",filename);
                    getch();
                    exit(1);
                }
                fclose(fp);
                if((fp=fopen(filename,"w"))==NULL)
                {
                    printf("%s",filename);
                    getch();
                    exit(1);
                }
                input(190,395,8,1,0x0000,0xffff,1,str);
                fputs(str,fp);
                fclose(fp);
			}
			if(x2>360&&y2>450&&x2<445&&y2<480&&buttons==1&&page_flag==2)
			{
				//顾客点击login框实现功能
				FILE *fp1=NULL,*fp2=NULL;
				CUST *l,*p;
                char str1[50],str2[50],str3[50],str4[50];
                char filename[3][20]={"cfile\\zhsr.txt","cfile\\mmsr.txt","cfile\\guke.txt"};
                char errorinf[20]="账号或密码错误";
                if((fp1=fopen(filename[0],"r"))==NULL)
                {
                	SET_SVGA_MODE(0x03);
                    printf("%s",filename[0]);
                    exit(1);
                }
                if((fp2=fopen(filename[1],"r"))==NULL)
                {
                	SET_SVGA_MODE(0x03);
                    printf("%s",filename[1]);
                    exit(1);
                }
                l=creat_cust();
                gukefile_open(l,filename[2]);
                fgets(str1,9,fp1);
                fgets(str2,9,fp2);
                fclose(fp1);
                fclose(fp2);
                for(p=l->next;p!=NULL;p=p->next)
                {
                    if(strcmp(str1,p->zhanghao)==0&&strcmp(str2,p->mima)==0)
                    {
                        *flag=8;
                        free_custhead(l);
                        free(l);
                        return;
                    }
                }
                if(p==NULL)
                {
                    hz(190,430,errorinf,0xffff,16);
                    delay(1000);
                    *flag=2;
                    free_custhead(l);
                    free(l);
                    return;
                }
			}
			if(x2>527&&y2>416&&x2<610&&y2<440&&buttons==1&&page_flag==2)					//顾客点击sign up框实现功能注册
			{
				*flag=18;
				return;
			}

			if(x2>650&&y2>548&&x2<735&&y2<570&&buttons==1&&page_flag==1)
			{
				put_pic(228,198,"aqm.bmp",1);										//	商户点击忘记密码。。 --设置安全码
				input(228+70,198+75,8,0,0x0000,0xffff,1,aqm_acc);
				if(strcmp(aqm_acc,"123456")==0)
				{
					hz(228+20,198+160,"口令为",0,16);
					put_asc(228+80,198+163,1,1,"admin",0); 
					delay(1000);
					getch(); 
					*flag=2;
					return;
				}else
				{
					hz(228+30,198+160,"安全码错误",0,16);
					delay(1000);
                    *flag=2;
                    return;
				}
			}
			if(x2>650&&y2>548&&x2<735&&y2<570&&buttons==1&&page_flag==2)
			{
				put_pic(0,0,"gly.bmp",1);											//    顾客点击忘记密码。。 -- 请联系管理员
				getch();
				*flag=2;//重新开始此界面。。。（暂时不设置此功能）
				return;
			}
			if(x2>183&&y2>461&&x2<192&&y2<470&&buttons==1&&(page_flag==1||page_flag==2))
			{
				put_pic(0,0,"404.bmp",1);											//此功能可能会造成混乱。。。先不做了。。
				getch();
				*flag=2;//重新开始此界面。。。
				return;
			}
	}
}

void showhzmain(int flag)
{
	int i;
	char hzsr[6][8]={"选择","商户","顾客","展示","帮助","退出"};
	char bmpname[] ="caidan1.bmp";
	unsigned int color,white[6];
	color=get16color(0xFFD700);
	for(i=0;i<=5;i++)
		white[i]=0xffff;
	for(i=0;i<=5;i++)
		if(flag==i)
		{
			if(i>=1)
				white[i]=color;
			put_pic(125,160,bmpname,0);
			hz(140,172,hzsr[0],white[0],24);
			hz(217,172,hzsr[1],white[1],24);
			hz(302,172,hzsr[2],white[2],24);
			hz(391,172,hzsr[3],white[3],24);
			hz(490,172,hzsr[4],white[4],24);
			hz(590,172,hzsr[5],white[5],24);
		}
}
void forgetmm()
{
	unsigned int color;
	color=get16color(0xf0ffff);
	drawbarcir(650,548,735,570,8,color,1);//空心未实现
	color=get16color(0xffa500);
	hz(659,551,"忘记密码",color,16);
}
void mainscreendonghua(int x2,int y2,int buttons,int *mode,int *page_flag)
{
	if(x2>205&&x2<=290&&y2>=172&&y2<=192&&*mode!=1)
		{
			showhzmain(1);
			*mode=1;
		}
	if(x2>290&&x2<=375&&y2>=172&&y2<=192&&*mode!=2)
		{
			showhzmain(2);
			*mode=2;
		}
	if(x2>375&&x2<=475&&y2>=172&&y2<=192&&*mode!=3)
		{
			showhzmain(3);
			*mode=3;
		}
	if(x2>475&&x2<=575&&y2>=172&&y2<=192&&*mode!=4)
		{
			showhzmain(4);
			*mode=4;
		}
	if(x2>575&&x2<670&&y2>=172&&y2<=192&&*mode!=5)
		{
			showhzmain(5);
			*mode=5;
		}
	if(!(x2>205&&x2<670&&y2>=172&&y2<=192)&&*mode!=0)
		{
			showhzmain(0);
			*mode=0;
		}
	if(x2>205&&x2<=290&&y2>=172&&y2<=192&&buttons==1)	//商户
		{
			drawbar(175,286,314,314,0xffff);
			drawbar(491,333,613,357,0xffff);
			put_pic(130,250,"login1.bmp",0);
			forgetmm();
			*page_flag=1;
		}
	if(x2>290&&x2<=375&&y2>=172&&y2<=192&&buttons==1)	//顾客
		{
			drawbar(175,286,314,314,0xffff);
			drawbar(491,333,613,357,0xffff);
			put_pic(130,250,"login1.bmp",0);
			forgetmm();
			*page_flag=2;
		}
}
