#ifndef  __MOUSE_H__
#define  __MOUSE_H__

int initmouse(void);
int readxy(int *mx,int *my,int *mbutt);
void drawcursor(int x,int y);
void showmouse(int x,int y);/*鼠标显示*/

void cpymouse(int x,int y);/*鼠标区域背景扣取*/
void reshowmouse(int x,int y);/*鼠标扣取背景重现*/
void readmouse(int *mouse_x,int * mouse_y,int * mouse_butt);/*读取鼠标状态*/
#endif
