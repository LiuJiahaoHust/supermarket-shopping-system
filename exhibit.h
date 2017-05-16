#ifndef  __EXHI_H__
#define  __EXHI_H__

#include"lianbiao.h"

void exhibition(int *flag);
void exh_bk(void);
void showgoods(GOODS *l);  //传入得指针指向第一个商品节点，而非指向头结点
void showhzex(int flag);
void anniu(int x2,int y2,int buttons,int* mode);
int downpage(GOODS *l);  //调用该函数即向下翻页，并令l指向翻页后页面的第一个商品节点
int uppage(GOODS *l);  //调用该函数即向上翻页，并令l指向翻页后页面的第一个商品节点
void showtype(GOODS *l,int i);  //传入得指针指向第一个商品节点，而非指向头结点，i代表的商品类型

#endif
