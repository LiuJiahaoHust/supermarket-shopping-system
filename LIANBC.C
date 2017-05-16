#include"lianbiao.h"
#include"head.h"

GOODS *creat_list(void)  //创建一个新的商品链表
{
    GOODS *head=NULL;
	head=(GOODS *)malloc(sizeof(GOODS));
	if(head==NULL)
	{
		printf("\nNo enough room!!!\n");
	}
	head->next=NULL;
	head->last=NULL;
	return head;
}

int listinsert(GOODS *l,int i,GOODS *e)  //在带头结点的单链线性表的第i个元素之后插入元素e
{
    int j=0;
    GOODS *p;
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

int listdelete(GOODS *l,int i) //在带头结点的单链线性表l中，删除第i个元素，并用e返回其值
{
    int j=0;
    GOODS *p,*q;
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
    free(q);
    return 1;
}

int searchname(GOODS *l,char *p) //根据商品名判断商品在链表中的位置，并返回其位置
{
    int i=1,sum;
    GOODS *f;
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

GOODS *free_head(GOODS **l) //将整个链表置空
{
	GOODS *q1=NULL,*q2=NULL;
	q1=*l;
	q2=(*l)->next;
	while(q2!=NULL)
	{
		q1->next=q2->next;
		free(q2);
		q2=NULL;
		q2=q1->next;
	}
	free(*l);
	//*l=NULL;
	return *l;
}

int change(GOODS *head,GOODS *p)  //修改head指针所指向的数据区的数据为p指针所值得数据
{
    strcpy(head->name,p->name);
    strcpy(head->price,p->price);
    strcpy(head->cunhuo,p->cunhuo);
    strcpy(head->leixing,p->leixing);
    strcpy(head->tlujing,p->tlujing);
    strcpy(head->xiaoliang,p->xiaoliang);
    strcpy(head->jinjia,p->jinjia);
    strcpy(head->bianhao,p->bianhao);
    return 1;
}

int hebing(GOODS *head1,GOODS *head2)  //将两个链表合并成一个链表   修改后
{
    GOODS *p;
    for(p=head1;p!=NULL;p=p->next)
    {
        if(p->next==NULL)
        {
            p->next=head2->next;
            head2->next->last=p;
        	head2->next=NULL;
            //free(head2);
            break;
        }
    }
    return 1;
}

GOODS *copylist(GOODS *l) //对l中的链表信息进行复制，返回其头结点地址
{
    GOODS *h,*p,*q,*t;
    h=creat_list();
    t=h;
    for(p=l->next;p!=NULL;p=p->next)
    {
        q=(GOODS *)malloc(sizeof(GOODS));
        q->next=NULL;
        q->last=NULL;
        strcpy(q->name,p->name);
        strcpy(q->price,p->price);
        strcpy(q->leixing,p->leixing);
        strcpy(q->cunhuo,p->cunhuo);
        strcpy(q->tlujing,p->tlujing);
        strcpy(q->xiaoliang,p->xiaoliang);
        strcpy(q->jinjia,p->jinjia);
        strcpy(q->bianhao,p->bianhao);
        t->next=q;
        t->next->last=t;
        t=t->next;
    }
    return h;
}

GOODS *free_head1(GOODS *l)
{
	GOODS *q1=NULL,*q2=NULL;
	q1=l;
	q2=l->next;
	while(q2!=NULL)
	{
		q1->next=q2->next;
		free(q2);
		q2=q1->next;
	}
	//l->next=NULL;
	//free(l);
	//l=NULL;
	return l;
}
