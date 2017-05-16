#ifndef  __INPUT_H__
#define  __INPUT_H__

#define Bksp 0x08
#define Enter 0x0D
int input(int x,int y,int n,int m,unsigned int color1,unsigned int color2,int size,char *s);
//在指定位置输入字符串函数，n表示输入字符串的最大个数，m判断是以明文还是暗文显示,color1表示输入的字体颜色，
//color2表示输入框的背景颜色，size表示字体大小,s字符串 

#endif
