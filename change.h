#ifndef  __CHANGE_H__
#define  __CHANGE_H__

#include"lianbiao.h"

void changegoods(int *flag);
void changebk(char (*p)[9]);//����Ʒ����
void display(GOODS *l,int *sta);  //�����ָ��ָ���һ����Ʒ�ڵ㣬����ָ��ͷ��㣬չʾ���߸���Ʒ
int downppy(GOODS *l,int *sta);  //���øú��������·�ҳ������lָ��ҳ��ҳ��ĵ�һ����Ʒ�ڵ�
int upppy(GOODS *l,int *sta);  //���øú��������Ϸ�ҳ������lָ��ҳ��ҳ��ĵ�һ����Ʒ�ڵ�
int paixu(GOODS *l,int *sta,int n);
int zhans(GOODS *l,int *sta);

#endif
