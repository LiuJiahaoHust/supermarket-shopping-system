#ifndef  __EXHI_H__
#define  __EXHI_H__

#include"lianbiao.h"

void exhibition(int *flag);
void exh_bk(void);
void showgoods(GOODS *l);  //�����ָ��ָ���һ����Ʒ�ڵ㣬����ָ��ͷ���
void showhzex(int flag);
void anniu(int x2,int y2,int buttons,int* mode);
int downpage(GOODS *l);  //���øú��������·�ҳ������lָ��ҳ��ҳ��ĵ�һ����Ʒ�ڵ�
int uppage(GOODS *l);  //���øú��������Ϸ�ҳ������lָ��ҳ��ҳ��ĵ�һ����Ʒ�ڵ�
void showtype(GOODS *l,int i);  //�����ָ��ָ���һ����Ʒ�ڵ㣬����ָ��ͷ��㣬i�������Ʒ����

#endif
