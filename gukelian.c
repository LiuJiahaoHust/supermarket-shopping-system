#include"head.h"
#include"gukelian.h"

CUST *creat_cust(void)  //����һ���µĹ˿�����
{
    CUST *head=NULL;
	head=(CUST *)malloc(sizeof(CUST));
	if(head==NULL)
	{
		printf("\nNo enough room!!!\n");
	}
	head->next=NULL;
	head->last=NULL;
	return head;
}

int custinsert(CUST *l,int i,CUST *e)  //�ڴ�ͷ���ĵ������Ա�ĵ�i��Ԫ��֮�����Ԫ��e
{
    int j=0;
    CUST *p;
    p=l;
    while(p&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1) return 0;
    e->next=p->next;
    p->next->last=e;
    e->last=p;
    p->next=e;
    return 1;
}

int custdelete(CUST *l,int i,CUST *e) //�ڴ�ͷ���ĵ������Ա�l�У�ɾ����i��Ԫ�أ�����e������ֵ
{
    int j=0;
    CUST *p,*q;
    p=l;
    while(p->next&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1) return 0;
    q=p->next;
    p->next=q->next;
    q->next->last=p;
    q->next=NULL;
    q->last=NULL;
    e=(CUST *)malloc(sizeof(CUST));
    changecust(e,q);
    free(q);
    return 1;
}

int searchcustname(CUST *l,char *p) //������Ʒ���ж���Ʒ�������е�λ�ã���������λ��
{
    int i=1,sum;
    CUST *f;
    for(f=l->next;f!=NULL;f=f->next)
    {
        if(strcmp(f->name,p)==0)
        {
            break;
        }
        else i++;
    }
    return i;
}

CUST *free_custhead(CUST *l) //�����������ÿ�
{
	CUST *q1=NULL,*q2=NULL;
	q1=l;
	q2=l->next;
	while(q2!=NULL)
	{
		q1->next=q2->next;
		free(q2);
		q2=NULL;
		q2=q1->next;
	}
	return l;
}

int changecust(CUST *head,CUST *p)  //�޸�headָ����ָ���������������Ϊpָ����ֵ������
{
    strcpy(head->name,p->name);
    strcpy(head->jifen,p->jifen);
    strcpy(head->zhanghao,p->zhanghao);
    strcpy(head->mima,p->mima);
    return 1;
}
