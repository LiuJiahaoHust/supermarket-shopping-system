#ifndef  __STATI_H__
#define  __STATI_H__

#include"lianbiao.h"

void statistics_count(int *flag);
void statibk(void);
void drawanniupic1(GOODS **l);  //画智能进货推荐
void drawanniupic2(GOODS **l,GOODS **h);  //画手动进货
void drawanniupic3(GOODS **l);       //画销售统计
int youfan(GOODS *l);  //调用该函数即向下翻页，并令l指向翻页后页面的第一个商品节点
int zuofan(GOODS *l);  //调用该函数即向上翻页，并令l指向翻页后页面的第一个商品节点
int zhanshi1(GOODS *l);

#endif
