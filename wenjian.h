#ifndef   ___WENJIAN_H__
#define   ___WENJIAN_H__

#include"lianbiao.h"

int file_open(GOODS *l,char *s);
//将s所指向的路径处的文件打开，将文件中的内容依次考入链表，并用l返回链表的头指针

int file_save(GOODS *l,char *s);
//将链表信息保存到文件,若查找不到文件则新建

#endif
