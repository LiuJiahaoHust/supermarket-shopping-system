#ifndef   ___GUKEWEN_H__
#define   ___GUKEWEN_H__

#include"gukelian.h"

int gukefile_open(CUST *l,char *s);
//将s所指向的路径处的文件打开，将文件中的内容依次考入链表，并用l返回链表的头指针

int gukefile_save(CUST *l,char *s);
//将链表信息保存到文件，若查找不到文件，则新建

#endif
