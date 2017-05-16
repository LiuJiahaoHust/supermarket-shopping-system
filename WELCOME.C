#include"head.h"
#include"welcome.h"
#include"tuxing.h"
#include"hanzi.h"
#include"mouse.h"

//unsigned char countt=0;
//unsigned char iii=0;
	
void welcome(int *flag)
{
	int x1,y1,x2,y2,buttons,mode,i,ifbreak=0;
		char s[17]="film2\\1.bmp";
	char ss[17]="film2\\10.bmp";	
	//void interrupt( *oldhandler)();
	x1=y1=x2=y2=buttons=0;
	//oldhandler = getvect(INTR);
    //setvect(INTR, handler);
		for(i=1;i<=51;i++)
		{
			if(i<=9)
			{
				s[6]='0'+i;
				put_pic(0,0,s,1);
			}
			else
			{
				ss[6]=i/10+'0';
				ss[7]='0'+i%10;
				put_pic(0,0,ss,1);
			}
			//delay(60);
			if(kbhit())
			{
				ifbreak=1;
				break;
			}
		}
	drawwelcome();
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
		if(x2>200&&x2<=550&&y2>=400&&y2<=500&&buttons==1)
		{
			*flag=2;
			return;
		}
		if(x2>=0&&x2<=200&&y2>=0&&y2<=200&&buttons==1)	
		{		
			*flag=7;//点左上直接进入商户选择。。代码全部完成后删除该部分。。 
			return;
		}
		//delay(10); 
	}
	*flag=2;
	//setvect(INTR, oldhandler);
	return; 
}

void SET_SVGA_MODE(int mode)
{
 union REGS r;
 r.x.ax=0x4f02;
 r.x.bx=mode;
 int86(0x10,&r,&r);
}
void drawwelcome()
{
	unsigned int color;
	int i;
	put_pic(0,0,"welcome.bmp",1);
	delay(300);
	color=get16color(0xE6E6FA);
	drawline(220,490,220,540,color);
	drawline(220,540,540,540,color);
	drawline(540,540,540,490,color);
	drawline(540,490,220,490,color);
	color=get16color(0x7b68ee);
	hz(280,502,"载",color,24);
	hz(350,502,"入",color,24);
	hz(420,502,"中",color,24);
	put_asc(460,507,2,1,".",color);
	put_asc(480,507,2,1,".",color);
	put_asc(500,507,2,1,".",color);
	delay(100);
	drawbar(220,490,220+4*1,540,color);
	for(i=2;i<=80;i++)
	{
		drawbar(214+4*i,490,220+4*i,540,color);
		delay(5);
	}
	delay(10);
	put_pic(211,483,"copy1.bmp",1);
	put_pic(200,400,"welcome2.bmp",0);
}
/*
void interrupt handler()
{
  	countt++;
 	 if(countt==18)
 	 {	countt==0;
  		iii++;}
  	if(countt%3==0)
	drawbar(countt*10,iii*10,10+countt*10,10+iii*10,0);
}*/
void put_pic(int x,int y,char *filename,int putflag)//putflag 0设置羽化 1设置正常贴图 2设置大图显示(2不需要了。。) 
{
 int i,j;
 unsigned int color;//65536个颜色 
 //extern short far *buffer;// 111111111111111111111 
 FILE *fp;
 long Width,Height,oldpage,newpage;
 unsigned long position;//偏移量 
 short far *buffer;//222222222222222222222
 short far *video_buffer=(short far *)0xA0000000L;//显存初始地址指针 

 if((fp=fopen(filename,"rb"))==NULL)
	{
		SET_SVGA_MODE(0x03);
		printf("Cannot install image\n%s",filename);
		getch();
		exit(1);
	}
	fseek(fp,18,SEEK_SET);//bmp编码方式，偏移18位 后读取尺寸 
	fread(&Width,sizeof(long),1,fp);
	fread(&Height,sizeof(long),1,fp);

	buffer=(short far*)malloc(Width*2);//申请内存 2222222222222222

	if(buffer==NULL)//申请失败 
	{
		SET_SVGA_MODE(0x03);
		printf("malloc error!");
		getch();
		exit(1);
	}
	fseek(fp,70,SEEK_SET);//文件指针偏移70位至颜色 ps好的颜色采用r5g6b5的编码方式，可直接读至0x114显存 
	oldpage=((Height-1+y)*(long)800+x)*2/65536L;//一定要转成long。。惨痛的回忆。。 
	newpage=oldpage;//初始化新页 
	selectpage(oldpage);//初始化第一页 
	if(putflag==0)
	{
		for(i=Height-1;i>=0;i--)
		{
			fread(buffer,Width*2,1,fp);//读文件的颜色入buffer内 
			for(j=0;j<Width;j++)
			{
				position=((i+y)*(long)800+j+x);//位置偏移量 
				newpage=position*2/65536;//第几页 
				if(newpage!=oldpage)//是否翻页 
				{
					selectpage(newpage);
					oldpage=newpage;
				}
			color=get16color(0xffffff);//白色不打印--因为在ps下bmp图形会有白边，为了打印的漂亮（除去边界的白色） 
			if(buffer[j]!=color)//white(color)-bkcolor
				*(video_buffer+(i+y)*800+x+j)=buffer[j];//写内存 
			}
		}
	}else if(putflag==1)
	{
		for(i=Height-1;i>=0;i--)
		{
			fread(buffer,Width*2,1,fp);//读文件的颜色入buffer内 
			for(j=0;j<Width;j++)
			{
				position=((i+y)*(long)800+j+x);//位置偏移量 
				newpage=position*2/65536;//第几页 
				if(newpage!=oldpage)//是否翻页 
				{
					selectpage(newpage);
					oldpage=newpage;
				}
				*(video_buffer+(i+y)*800+x+j)=buffer[j];//写内存 
			}
		}
	}
	fclose(fp);//关文件 
	free(buffer);//释放内存 222222222222222222
}

void orangedonghua(int x,int y)
{
	int i;
	char s[17]="film1\\1.bmp";
		for(i=1;i<=18;i++)
		{
			if(i<=9)
			{
				s[6]='0'+i;
				put_pic(x,y,s,1);
			}
			else
			{
				s[6]=i%10+'a';
				put_pic(x,y,s,1);
			}
			delay(45);
		}
	delay(400);
}
