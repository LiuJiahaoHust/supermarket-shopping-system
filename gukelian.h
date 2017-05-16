#ifndef   ___GUKELIAN_H__
#define   ___GUKELIAN_H__

typedef struct customer
{
    char name[30];
    char jifen[20];
    char zhanghao[20];
    char mima[20];
    struct customer *next;
    struct customer *last;
}CUST;

CUST *creat_cust(void);
//创建一个新的顾客链表

int custinsert(CUST *l,int i,CUST *e);
//在带头结点的单链线性表的第i个元素之后插入元素e

int custdelete(CUST *l,int i,CUST *e);
//在带头结点的单链线性表l中，删除第i个元素，并用e返回其值

int searchcustname(CUST *l,char *p);
//根据商品名判断商品在链表中的位置，并返回其位置

CUST *free_custhead(CUST *l);
//将整个链表置空

int changecust(CUST *head,CUST *p);
//修改head指针所指向的数据区的数据为p指针所值得数据

#endif
