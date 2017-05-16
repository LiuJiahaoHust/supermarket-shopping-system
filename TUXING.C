#include"head.h"
#include"tuxing.h"

static int Writemode=SVGA_COPY;//设为静态，默认为复制画点 

unsigned int get16color(long int x)
{
	long int x1=x>>16;
	long int x2=(x-(x1<<16))>>8;
	long int x3=x-(x1<<16)-(x2<<8);
	x1=x1>>3;
	x2=x2>>2;
	x3=x3>>3;
	x=(x1<<11)+(x2<<5)+x3;
	return x;
}
void SvgaSetWriteMode(int mode)
{
	if((mode>=SVGA_COPY)&&(mode<=SVGA_NOT))
		Writemode=mode;
}
void setsvga()
{
	union REGS r;
	r.x.ax=0x4f02;
	r.x.bx=0x114;
	int86(0x10,&r,&r);
}

void heng_line(int x1,int x2,int y,unsigned int color)
{
	int x;
	for(x=x1;x<=x2;x++)
		drawpoint(x,y,color);
}
void shu_line(int x,int y1,int y2,unsigned int color)
{
	int y;
	for(y=y1;y<=y2;y++)
		drawpoint(x,y,color);
}
int drawellipse(int x,int y,int a,int b,unsigned int color,int flag)
{
	int i=0,j=0;
	float af=a,bf=b;
	if((x-a<0)||(x+a>800)||(y-b<0)||(y+b>600))
		return 0;
	else
	{
		if(flag==1)
		{
			for(i=0;i<=a;i++)
			{
				j=(int)(sqrt(bf*bf-bf*bf/af/af*i*i));
				for(;j>=0;j--)
				{
					drawpoint(x+i,y+j,color);
					drawpoint(x+i,y-j,color);
					drawpoint(x-i,y+j,color);
					drawpoint(x-i,y-j,color);
				}
			}
		}
		else
		{
			for(i=0;i<=a;i++)
			{
				j=(int)(sqrt(bf*bf-bf*bf/af/af*i*i));
				drawpoint(x+i,y+j,color);
				drawpoint(x+i,y-j,color);
				drawpoint(x-i,y+j,color);
				drawpoint(x-i,y-j,color);
			}
			for(j=0;j<=b;j++)
			{
				i=(int)(sqrt(af*af-af*af/bf/bf*j*j));
				drawpoint(x+i,y+j,color);
				drawpoint(x+i,y-j,color);
				drawpoint(x-i,y+j,color);
				drawpoint(x-i,y-j,color);
			}
		}
		return 1;
	}
}
int drawcircle(int x,int y,int r,unsigned int color,int flag)//shi xin 1,xu xin 0
{
	int i=0,j=0;
	if((x-r<0)||(x+r>800)||(y-r<0)||(y+r>600))
		return 0;
	else
	{
		if(flag==1)
		{
			for(i=0;i<=r;i++)
			{
				j=(int)(sqrt(r*r-i*i));
				for(;j>=0;j--)
				{
					drawpoint(x+i,y+j,color);
					drawpoint(x+i,y-j,color);
					drawpoint(x-i,y+j,color);
					drawpoint(x-i,y-j,color);
				}
			}
		}
		else
		{
			for(i=0;i<=r;i++)
			{
				j=(int)(sqrt(r*r-i*i));
				drawpoint(x+i,y+j,color);
				drawpoint(x+i,y-j,color);
				drawpoint(x-i,y+j,color);
				drawpoint(x-i,y-j,color);
			}
			for(j=0;j<=r;j++)
			{
				i=(int)(sqrt(r*r-j*j));
				drawpoint(x+i,y+j,color);
				drawpoint(x+i,y-j,color);
				drawpoint(x-i,y+j,color);
				drawpoint(x-i,y-j,color);
			}
		}
		return 1;
	}
}
void drawbkcolor(unsigned int color)
{
	int x=0,y=0;
	for(x=0;x<=800;x++)
		for(y=0;y<=600;y++)
			drawpoint(x,y,color);
}

void drawpoint(int x,int y,unsigned int color)
{

  unsigned short far *video_buffer=(unsigned short far *)0xA0000000L;
  long pos=(y*800L+x);
  unsigned int page=pos*2/65536L;
  selectpage(page);
  switch(Writemode)
  {
	case SVGA_AND:
			*((unsigned short far *)(video_buffer+pos))&=color;
			break;
	case SVGA_OR:
			*((unsigned short far *)(video_buffer+pos))|=color;
			break;
	case SVGA_XOR:
			*((unsigned short far *)(video_buffer+pos))^=color;
			break;
	case SVGA_COPY:
			*((unsigned short far *)(video_buffer+pos))=color;
			break;
  }
}

void selectpage(register char page)	//换页函数
{
	union REGS r;
	r.x.ax=0x4f05;
	r.x.bx=0x00;
	r.x.dx=page;	//选择页面
	int86(0x10,&r,&r);//通用8086软中断接口
}

void drawbar(int left,int top,int right,int bottom,unsigned int color)
{
    unsigned short far *video_buffer=(unsigned short far *)0xA0000000L;
    long pos;
    unsigned int oldpage,newpage;  
	int i=0,j=0;
	
	for(j=top;j<=bottom;j++)
		for(i=left;i<=right;i++)
		{
			pos=(j*800L+i);
			newpage=pos*2/65536L;
				if(newpage!=oldpage)//是否翻页 
				{
					selectpage(newpage);
					oldpage=newpage;
				}
			*((unsigned short far *)(video_buffer+pos))=color;
		} 
}

void Read_Asc16(char key,unsigned char *buf)
{
int handle;
long address;
handle=open("asc16",O_RDONLY|O_BINARY);//io.h
address=key*16l;
lseek(handle,address,SEEK_SET);//io.h
read(handle,buf,16);//io.h
close(handle);
}

void Put_Asc16(int cx,int cy,char key,unsigned int fcolor)
{
int a,b;
unsigned char buf[16];
Read_Asc16(key,buf);
for(a=0;a<16;a++)
for(b=0;b<8;b++)
if((buf[a]>>7-b)&1)
drawpoint(cx+a,cy+b,fcolor);
}

void Put_Asc16_Size(int cx,int cy,int xsize,int ysize,char key,unsigned int fcolor)
{
	unsigned short far *video_buffer=(unsigned short far *)0xA0000000L;
    long pos;
    unsigned int oldpage,newpage;  
	int a,b,o,k;
	unsigned char buf[16];
	Read_Asc16(key,buf);
	for(a=0;a<16;a++)
		for(o=1;o<=ysize;o++)
			for(b=0;b<8;b++)
				for(k=1;k<=xsize;k++)
					if((buf[a]>>7-b)&1)
					{
						pos=((cy+o+a*ysize)*800L+cx+b*xsize+k);
						newpage=pos*2/65536L;
						if(newpage!=oldpage)//是否翻页 
						{
							selectpage(newpage);
							oldpage=newpage;
						}
						*((unsigned short far *)(video_buffer+pos))=fcolor;
					}
				   //drawpoint(cx+b*xsize+k,cy+o+a*ysize,fcolor);
}
void put_asc(int cx,int cy,int xsize,int ysize,char *s,unsigned int color )
{
	int index;
    for(index=0;s[index]!=0;index++)
	{
		Put_Asc16_Size(cx+index*xsize*8,cy,xsize,ysize,s[index],color);
    }
}
void CLOSE_SVGA(void)
{
	union REGS r;
	r.x.ax=0x03;
	int86(0x10,&r,&r);
}   

void drawbarcir(int left,int top,int right,int bottom,int r,unsigned int color,int flag)
{
	int left2,top2,right2,bottom2;
	left2=left+r; 
	top2=top+r; 
	right2=right-r; 
	bottom2=bottom-r;
	if(flag==1)//实心。。调circle函数就好 
	{
		drawcircle(left2,top2,r,color,1); 
		drawcircle(left2,bottom2,r,color,1); 
		drawcircle(right2,top2,r,color,1); 
		drawcircle(right2,bottom2,r,color,1); 
		drawbar(left2,top,right2,bottom,color);
		drawbar(left,top2,right,bottom2,color);
	}
	else if(flag==0)//空心。。难画 
	{
		drawline(left2,top,right2,top,color);
		drawline(left2,bottom,right2,bottom,color);
		drawline(left,top2,left,bottom,color);
		drawline(right,top,right,bottom,color);
	}
}

void drawline(int x1,int y1,int x2,int y2,unsigned int color)//这个算法不算代码量 
{
	int dx,dy,x_inc=1,y_inc=1,x,y;
   int index,error=0;
   unsigned short far *video_buffer=(unsigned short far *)0xA0000000L;
    long pos2;
    unsigned int oldpage,newpage;  
   x=x1;y=y1;
   dx=x2-x1;dy=y2-y1;
   if(dx<0)
	{
	 dx=-dx;
	 x_inc=-1;
	}
   if(dy<0)
	{
	 dy=-dy;
	 y_inc=-1;
	}
	if(dx>dy)
	{
		 for(index=0;index<=dx;index++)
		 {
		  drawpoint(x,y,color);
		  error+=dy;
		  x+=x_inc;
		  drawpoint(x,y,color);
			if(error>dx)
				{
				 error-=dx;
				 y+=y_inc;
				 pos2=(y*800L+x);
					newpage=pos2*2/65536L;
					if(newpage!=oldpage)//是否翻页 
					{
						selectpage(newpage);
						oldpage=newpage;
					}
					*((unsigned short far *)(video_buffer+pos2))=color;
				}
		 }
	}
	else
		{
		 for(index=0;index<=dy;index++)
			   {
				drawpoint(x,y,color);
				error+=dx;
				y+=y_inc;
				drawpoint(x,y,color);
				if(error>dy)
					{
					 error-=dy;
					 x+=x_inc;
					 pos2=(y*800L+x);
					newpage=pos2*2/65536L;
					if(newpage!=oldpage)//是否翻页 
					{
						selectpage(newpage);
						oldpage=newpage;
					}
					*((unsigned short far *)(video_buffer+pos2))=color;
					}
			   }
		}
}
