#ifndef  __MOUSE_H__
#define  __MOUSE_H__

int initmouse(void);
int readxy(int *mx,int *my,int *mbutt);
void drawcursor(int x,int y);
void showmouse(int x,int y);/*�����ʾ*/

void cpymouse(int x,int y);/*������򱳾���ȡ*/
void reshowmouse(int x,int y);/*����ȡ��������*/
void readmouse(int *mouse_x,int * mouse_y,int * mouse_butt);/*��ȡ���״̬*/
#endif
