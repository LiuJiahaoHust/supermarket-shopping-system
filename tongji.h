#ifndef   ___TONGJI_H__
#define   ___TONGJI_H__

#include"gukelian.h"
#include"lianbiao.h"

float xiaoshoue(GOODS *l);
//判断由l指向的统计文件中的总的销售额

float chengbene(GOODS *l);
//判断由l指向的统计文件中的总的商品成本

float shourue(GOODS *l);
//判断由l指向的统计文件中的总的收入

int shourup(GOODS *l,int i);
//将销售的商品按其收入进行排序,其中若i=0，则按升序排列，若i=1，则按照降序排列

int xiaoliangp(GOODS *l,int i);
//将销售的商品按其销量进行排序,其中若i=0，则按升序排列，若i=1，则按照降序排列

int cunhuop(GOODS *l,int i);
//将销售的商品按其存货量进行排序,其中若i=0，则按升序排列，若i=1，则按照降序排列

int gukejifen(CUST *l,int i);
//将顾客按照其积分进行排序，其中若i=0，则按升序排列，若i=1，则按照降序排列

GOODS *dinghuotuijian(char *s2);
//该函数通过对统计文件中商品收入的分析

int he(char*s1,char *s2);
//将商品文件和统计文件中的信息合并 ps:由于之前结算时统计文件中没有对存货进行操作，商品文件中没有对销量进行操作

int quanzhong(char *s,GOODS *h1,GOODS *h2,GOODS *h3);
//改函数返回商品的权重，从而确定商品订货的顺序

#endif
