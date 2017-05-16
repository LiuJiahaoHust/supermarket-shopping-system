#ifndef  __CHANGE_H__
#define  __CHANGE_H__

#include"lianbiao.h"

void changegoods(int *flag);
void changebk(char (*p)[9]);//画商品界面
void display(GOODS *l,int *sta);  //传入得指针指向第一个商品节点，而非指向头结点，展示出七个商品
int downppy(GOODS *l,int *sta);  //调用该函数即向下翻页，并令l指向翻页后页面的第一个商品节点
int upppy(GOODS *l,int *sta);  //调用该函数即向上翻页，并令l指向翻页后页面的第一个商品节点
int paixu(GOODS *l,int *sta,int n);
int zhans(GOODS *l,int *sta);

#endif
