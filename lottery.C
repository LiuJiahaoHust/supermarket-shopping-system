#include"head.h"
#include"welcome.h"
#include"lottery.h"
#include"tuxing.h"
#include"mouse.h"
#include"hanzi.h"
#include"input.h"
#include"gukewen.h"
#include"gukelian.h"
#include"lianbiao.h"

void lottery(int *flag)
{
	
	int x1,y1,x2,y2,buttons;
	x1=y1=x2=y2=buttons=0;
	put_pic(0,0,"chouj.bmp",1);
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
		if(x2>80&&y2>186&&x2<230&&y2<221&&buttons==1)//顾客账号 
		{ 
			FILE *fp=NULL;
                char str[50];
                char filename[20]="cfile\\zhsrcj.txt";
                drawbar(80,186,230,221,0xffff); 
                /*if((fp = fopen(filename, "wt"))==NULL)
                {
                    printf("%s",filename);
                    getch();
                    exit(1);
                }
                fclose(fp);*/
                if((fp=fopen(filename,"w"))==NULL)
                {
                    printf("%s",filename);
                    getch();
                    exit(1);
                }
                input(105,196,8,0,0x0000,0xffff,1,str);
                fputs(str,fp);
                fclose(fp);	
		}
		if(x2>80&&y2>241&&x2<230&&y2<276&&buttons==1)//顾客密码 
		{
				FILE *fp=NULL;
                char str[50];
                char filename[20]="cfile\\mmsrcj.txt";
                drawbar(80,241,230,276,0xffff);
                /*if((fp = fopen(filename, "wt"))==NULL)
                {
                    printf("%s",filename);
                    getch();
                    exit(1);
                }
                fclose(fp);*/
                if((fp=fopen(filename,"w"))==NULL)
                {
                    printf("%s",filename);
                    getch();
                    exit(1);
                }
                input(105,251,8,1,0x0000,0xffff,1,str);
                fputs(str,fp);
                fclose(fp);
		}
		if(x2>666&&y2>540&&x2<800&&y2<600&&buttons==1)//返回 
		{
				*flag=2;//回到主界面
				return;
		}
		if(x2>360&&y2>316&&x2<441&&y2<394&&buttons==1)//点击抽奖 
		{
			FILE *fp1=NULL,*fp2=NULL;
				CUST *l,*p;
                char str1[50],str2[50],str3[50],str4[50];
                char filename[3][20]={"cfile\\zhsrcj.txt","cfile\\mmsrcj.txt","cfile\\guke.txt"};
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
                    	int numsave;
                    	char resulthz[10][16]={"食用油","储物盒","洗衣液","抽纸","精品棉袜","酸奶","笔记本","相册","谢谢惠顾","手机一台"};
                        numsave=atoi(p->jifen);
                        if(numsave>=1000)
                        {
                        	int ii; 
                        	unsigned int result;
                        	numsave-=1000;
                        	srand((unsigned)time(NULL));
                        	result=rand()%1024;
                        	itoa(numsave,p->jifen,10);
                        	gukefile_save(l,filename[2]);
                        	hz(310,551,"抽奖结果为",0xffff,24);
                        	for(ii=0;ii<=7;ii++)
                        	{
								if(result<=100+100*ii&&result>100*ii)
                        			hz(450,551,resulthz[ii],0xffff,24);
                        		if(result<=1022&&result>800)
                        			hz(450,551,resulthz[8],0xffff,24);
                        		if(result>1022)
                        			hz(450,551,resulthz[9],0xffff,24);
                        	}
                        	delay(1000);
                      		getch();
                      		*flag=17;
                        	free_custhead(l);
                        	free(l);
                        	return;
						}
						else
						{
							hz(310,551,"您的积分不足",0xffff,24);
                    		delay(1000);
                    		getch(); 
                   			*flag=17;
                   			free_custhead(l);
                   			free(l);
                    		return;
						}
                        
                    }
                }
                if(p==NULL)
                {
                    hz(310,551,errorinf,0xffff,24);
                    delay(1000);
                    *flag=17;
                    free_custhead(l);
                    free(l);
                    return;
                }
		}
	}
}
