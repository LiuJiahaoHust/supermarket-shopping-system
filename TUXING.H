#ifndef  __TUXING_H__
#define  __TUXING_H__

#define SVGA_COPY 0  //覆盖
#define SVGA_XOR  1  //异或
#define SVGA_OR   2  //或
#define SVGA_AND  3  //与
#define SVGA_NOT  4  //非
void setsvga(void);//建立svga模式 
void selectpage(register char page);
void SvgaSetWriteMode(int mode);
unsigned int get16color(long int x);//从网上得到0xffffff格式的r8g8b8颜色，显示为0xffff格式的r5g6b5格式 
void CLOSE_SVGA(void);

void drawpoint(int x,int y,unsigned int color);//画点 
void drawbkcolor(int unsigned color);//设置背景色 
void drawbar(int left,int top,int right,int bottom,unsigned int color);//画矩形，左，上，右，下，颜色 
void heng_line(int x1,int x2,int y,unsigned int color);//画横线 左，右，纵坐标，颜色 
void shu_line(int x,int y1,int y2,unsigned int color);//画竖线 横坐标，上，下，颜色 
void drawline(int x1,int y1,int x2,int y2,unsigned int color);//画线，第一个点，第二个点，颜色 
int drawcircle(int x,int y,int r,unsigned int color,int flag);//画圆 圆心位置，半径，颜色，是否实心 
int drawellipse(int x,int y,int a,int b,unsigned int color,int flag);//画椭圆 圆心位置，x方向半径，y方向半径，颜色，是否实心 
void drawbarcir(int left,int top,int right,int bottom,int r,unsigned int color,int flag);//画圆角矩形，左，上，右，下，半径，颜色，是否实心（这个算法要吃人。。） 
 
void put_asc(int cx,int cy,int xsize,int ysize,char *s,unsigned int color );//放置字符串， 位置，x方向大小，y方向大小，字符串，颜色 
void Put_Asc16_Size(int cx,int cy,int xsize,int ysize,char key,unsigned int fcolor);
void Put_Asc16(int cx,int cy,char key,unsigned int fcolor);
void Read_Asc16(char key,unsigned char *buf);


#endif
