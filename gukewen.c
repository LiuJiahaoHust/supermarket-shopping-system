#include"head.h"
#include"gukewen.h"
#include"welcome.h"

int gukefile_open(CUST *l,char *s) //��s��ָ���·�������ļ��򿪣����ļ��е��������ο�����������l���������ͷָ��
{
    FILE *fp;
    CUST *p,*q,*t;
    t=l;
    p=creat_cust();
    if((fp=fopen(s,"rt+"))==NULL)
    {
    	SET_SVGA_MODE(0x03);
        printf("%s",s);
        getch();
        exit(1);
    }
    if(!feof(fp))
	{
		while(fscanf(fp,"%30s%20s%20s%20s%c",p->name,p->jifen,p->zhanghao,p->mima)!=EOF)
		{
			q=(CUST *)malloc(sizeof(CUST));				//���ļ��е���Ϣ��fscanf�򿪵�������ȥ
			q->next=NULL;
			q->last=NULL;
			strcpy(q->name,p->name);
			strcpy(q->jifen,p->jifen);
			strcpy(q->zhanghao,p->zhanghao);
			strcpy(q->mima,p->mima);
			t->next=q;
			t->next->last=t;
			t=t->next;
		}
	}
	free(p);
	//p=NULL;
	t->next=NULL;
	fclose(fp);											//�ر��ļ�
	return 1;
}

int gukefile_save(CUST *l,char *s)						//��������Ϣ���浽�ļ�
{
	FILE *fp;
	CUST *p=NULL,*q=NULL;
    if((fp = fopen(s, "w"))==NULL)
	{
		printf("%s",s);
		getch();
		exit(1);
	}
	fclose(fp);    //���ļ���ԭ�е�������գ����½���һ���ı��ļ�
	if((fp=fopen(s,"at"))==NULL)	//�ж��ܷ���ļ�
	{
		//SET_SVGA_MODE(0x03);
		printf("%s",s);
		getch();
		exit(1);
	}
	p=l->next;

	while(p!=NULL)		//�������е���Ϣ��fprintfд���ļ���ȥ
	{
		fprintf(fp,"%30s%20s%20s%20s%c",p->name,p->jifen,p->zhanghao,p->mima,'\n');
		p=p->next;
	}
	q=l;
	p=l->next;		//�ͷ���������Ϣռ�õ��ڴ�
	while(p!=NULL)
	{
		q->next=p->next;
		free(p);
		p=NULL;
		p=q->next;
		//p=q;
		//p=p->next;
	}
	fclose(fp);	//�ر��ļ�
	return 1;
}
