#ifndef   ___welcome_H__
#define   ___welcome_H__
void welcome(int *flag);
void put_pic(int x,int y,char *filename,int putflag);//指定位置放置65536色r5g6b5的bmp图片 putflag 0设置羽化 1设置正常贴图 2设置大图显示 
void SET_SVGA_MODE(int mode);//设立svga模式 使用0x114 800*600像素16位色（r5g6b5） error时设立文本0x103模式，输出错误信号 
void drawwelcome(void);
void orangedonghua(int x,int y);
//void interrupt handler();
//#define INTR 0X1C

#endif
