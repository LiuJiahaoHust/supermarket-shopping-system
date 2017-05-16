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
//����һ���µ���Ʒ����

int listinsert(GOODS *l,int i,GOODS *e);
//�ڴ�ͷ���ĵ������Ա�ĵ�i��Ԫ��֮�����Ԫ��e

int listdelete(GOODS *l,int i);
//�ڴ�ͷ���ĵ������Ա�l�У�ɾ����i��Ԫ�أ�����e������ֵ

int searchname(GOODS *l,char *p);
//������Ʒ���ж���Ʒ�������е�λ�ã���������λ��

GOODS *free_head(GOODS **l);
//�����������ÿ�

int change(GOODS *head,GOODS *p);
//�޸�headָ����ָ���������������Ϊpָ����ֵ������

int hebing(GOODS *head1,GOODS *head2);
//����������ϲ���һ������

GOODS *copylist(GOODS *l);
//��l�е�������Ϣ���и��ƣ�������ͷ����ַ

GOODS *free_head1(GOODS *l);
//�����������ÿ� ��һ��ָ�� 

#endif
