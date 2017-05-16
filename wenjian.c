#include"head.h"
#include"wenjian.h"
#include"welcome.h"

int file_open(GOODS *l,char *s) //��s��ָ���·�������ļ��򿪣����ļ��е��������ο�����������l���������ͷָ��
{
    FILE *fp;
    GOODS *p,*q,*t;
    t=l;
    p=creat_list();//��p����ռ�
    if((fp=fopen(s,"rt+"))==NULL)
    {
    	SET_SVGA_MODE(0x03);
    	printf("%s\n",s);
        getch();
        exit(1);
    }
    if(!feof(fp))
	{
		while(fscanf(fp,"%10s%6s%10s%5s%20s%5s%6s%5s%c",p->name,p->price,p->leixing,p->cunhuo,p->tlujing,p->xiaoliang,p->jinjia,p->bianhao)!=EOF)
		{
			q=(GOODS *)malloc(sizeof(GOODS));				//���ļ��е���Ϣ��fscanf�򿪵�������ȥ
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
	}
	free(p);//�ͷ�p
	t->next=NULL;
	fclose(fp);											//�ر��ļ�
	return 1;
}

int file_save(GOODS *l,char *s)						//��������Ϣ���浽�ļ�
{
	FILE *fp;
	GOODS *p=NULL,*q=NULL;
	if((fp = fopen(s, "w"))==NULL)
	{
		printf("%s",s);
		getch();
		exit(1);
	}
	fclose(fp);               //���ļ���ԭ�е�������գ����½���һ���ı��ļ�
	if((fp=fopen(s,"at"))==NULL)	//�ж��ܷ���ļ�
	{
		printf("%s",s);
		getch();
		exit(1);
	}
	p=l->next;

	while(p!=NULL)		//�������е���Ϣ��fprintfд���ļ���ȥ
	{
		fprintf(fp,"%10s%6s%10s%5s%20s%5s%6s%5s%c",p->name,p->price,p->leixing,p->cunhuo,p->tlujing,p->xiaoliang,p->jinjia,p->bianhao,'\n');
		p=p->next;
	}
	fclose(fp);	//�ر��ļ�
	q=l;
	p=l->next;		//�ͷ���������Ϣռ�õ��ڴ�
	while(p!=NULL)
	{
		q->next=p->next;
		free(p);
		p=q->next;
		//p=q;
		//p=p->next;
	}
	return 1;
}
