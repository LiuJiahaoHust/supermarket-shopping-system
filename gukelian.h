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
//����һ���µĹ˿�����

int custinsert(CUST *l,int i,CUST *e);
//�ڴ�ͷ���ĵ������Ա�ĵ�i��Ԫ��֮�����Ԫ��e

int custdelete(CUST *l,int i,CUST *e);
//�ڴ�ͷ���ĵ������Ա�l�У�ɾ����i��Ԫ�أ�����e������ֵ

int searchcustname(CUST *l,char *p);
//������Ʒ���ж���Ʒ�������е�λ�ã���������λ��

CUST *free_custhead(CUST *l);
//�����������ÿ�

int changecust(CUST *head,CUST *p);
//�޸�headָ����ָ���������������Ϊpָ����ֵ������

#endif
