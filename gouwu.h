#ifndef   ___GOUWU_H__
#define   ___GOUWU_H__

float jiesuan(GOODS *l,char *s2,char *s3,int *jife);
//结算以l为头结点所指链表中商品的价格，将商品的存货信息和统计信息返回到商品文件
//并将s3所指向的用户名称的用户文件中找出，并修改其积分

int cunhuozeng(GOODS *l,char *num);

float pricecount(GOODS *l);
//返回l所指向链表节点的商品价格

int cunhuo(GOODS *l,int i);
//将l指向的商品在商品文件中找到，并减少其存货

int cunhuo1(GOODS *l,int i);
//将l指向的商品在商品原文件中找到，并减少其存货

int cunhuoz(GOODS *l,int n,char *num);
//将l指向的商品在文件中找到，并减少其存货 num为新的存货数

int tongji(GOODS *l,char *s2);
//将l指向的商品在统计文件中找到，若没有则新建,增加其销量

GOODS *jinhuo(char *s1,char *s2);
//将商品原始文件s1与商品文件s2作比较，从而发现需要进货的商品,并用以head为头结点的链表返回

int jifenincrease(char *s3,int sum);
//将名为s3的用户在用户文件s中找到，并修改其在文件中的积分，函数同时返回顾客在本次购物中所得积分

int xmpipei(char *s3);
//将名为s3的用户在用户文件中找到，若找到则返回1，否则返回0

#endif
