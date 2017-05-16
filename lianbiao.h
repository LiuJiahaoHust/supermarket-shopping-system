#ifndef   ___LIANBIAO_H__
#define   ___LIANBIAO_H__

typedef struct goods
{
    char name[10];
    char price[6];
    char leixing[10];
    char cunhuo[5];
    char tlujing[20];
    char xiaoliang[5];
    char jinjia[6];
    char bianhao[5];
    struct goods *next;
    struct goods *last;
} GOODS;

GOODS *creat_list(void);
//创建一个新的商品链表

int listinsert(GOODS *l,int i,GOODS *e);
//在带头结点的单链线性表的第i个元素之后插入元素e

int listdelete(GOODS *l,int i);
//在带头结点的单链线性表l中，删除第i个元素，并用e返回其值

int searchname(GOODS *l,char *p);
//根据商品名判断商品在链表中的位置，并返回其位置

GOODS *free_head(GOODS **l);
//将整个链表置空

int change(GOODS *head,GOODS *p);
//修改head指针所指向的数据区的数据为p指针所值得数据

int hebing(GOODS *head1,GOODS *head2);
//将两个链表合并成一个链表

GOODS *copylist(GOODS *l);
//对l中的链表信息进行复制，返回其头结点地址

GOODS *free_head1(GOODS *l);
//将整个链表置空 传一重指针 

#endif
