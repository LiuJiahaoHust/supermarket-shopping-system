#ifndef  __HANZI_H__
#define  __HANZI_H__

void hz(int x,int y,char *s,int color,int type);//使用的 type选16和24 
void get_hz(char incode[],char bytes[],int type);
void dishz(int x0,int y0,char code[],int color,int type);
void hanzi12(int x,int y,char *s,int color);
void open_hzk(char * path);

#endif
