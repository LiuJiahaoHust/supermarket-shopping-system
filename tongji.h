#ifndef   ___TONGJI_H__
#define   ___TONGJI_H__

#include"gukelian.h"
#include"lianbiao.h"

float xiaoshoue(GOODS *l);
//�ж���lָ���ͳ���ļ��е��ܵ����۶�

float chengbene(GOODS *l);
//�ж���lָ���ͳ���ļ��е��ܵ���Ʒ�ɱ�

float shourue(GOODS *l);
//�ж���lָ���ͳ���ļ��е��ܵ�����

int shourup(GOODS *l,int i);
//�����۵���Ʒ���������������,������i=0�����������У���i=1�����ս�������

int xiaoliangp(GOODS *l,int i);
//�����۵���Ʒ����������������,������i=0�����������У���i=1�����ս�������

int cunhuop(GOODS *l,int i);
//�����۵���Ʒ����������������,������i=0�����������У���i=1�����ս�������

int gukejifen(CUST *l,int i);
//���˿Ͱ�������ֽ�������������i=0�����������У���i=1�����ս�������

GOODS *dinghuotuijian(char *s2);
//�ú���ͨ����ͳ���ļ�����Ʒ����ķ���

int he(char*s1,char *s2);
//����Ʒ�ļ���ͳ���ļ��е���Ϣ�ϲ� ps:����֮ǰ����ʱͳ���ļ���û�жԴ�����в�������Ʒ�ļ���û�ж��������в���

int quanzhong(char *s,GOODS *h1,GOODS *h2,GOODS *h3);
//�ĺ���������Ʒ��Ȩ�أ��Ӷ�ȷ����Ʒ������˳��

#endif
