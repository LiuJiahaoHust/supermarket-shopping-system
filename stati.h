#ifndef  __STATI_H__
#define  __STATI_H__

#include"lianbiao.h"

void statistics_count(int *flag);
void statibk(void);
void drawanniupic1(GOODS **l);  //�����ܽ����Ƽ�
void drawanniupic2(GOODS **l,GOODS **h);  //���ֶ�����
void drawanniupic3(GOODS **l);       //������ͳ��
int youfan(GOODS *l);  //���øú��������·�ҳ������lָ��ҳ��ҳ��ĵ�һ����Ʒ�ڵ�
int zuofan(GOODS *l);  //���øú��������Ϸ�ҳ������lָ��ҳ��ҳ��ĵ�һ����Ʒ�ڵ�
int zhanshi1(GOODS *l);

#endif
