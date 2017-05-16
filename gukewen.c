#include"head.h"
#include"gukewen.h"
#include"welcome.h"

int gukefile_open(CUST *l,char *s) //将s所指向的路径处的文件打开，将文件中的内容依次考入链表，并用l返回链表的头指针
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
			q=(CUST *)malloc(sizeof(CUST));				//将文件中的信息以fscanf打开到链表中去
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
	fclose(fp);											//关闭文件
	return 1;
}

int gukefile_save(CUST *l,char *s)						//将链表信息保存到文件
{
	FILE *fp;
	CUST *p=NULL,*q=NULL;
    if((fp = fopen(s, "w"))==NULL)
	{
		printf("%s",s);
		getch();
		exit(1);
	}
	fclose(fp);    //将文件中原有的内容清空，或新建立一个文本文件
	if((fp=fopen(s,"at"))==NULL)	//判断能否打开文件
	{
		//SET_SVGA_MODE(0x03);
		printf("%s",s);
		getch();
		exit(1);
	}
	p=l->next;

	while(p!=NULL)		//将链表中的信息以fprintf写入文件中去
	{
		fprintf(fp,"%30s%20s%20s%20s%c",p->name,p->jifen,p->zhanghao,p->mima,'\n');
		p=p->next;
	}
	q=l;
	p=l->next;		//释放链表中信息占用的内存
	while(p!=NULL)
	{
		q->next=p->next;
		free(p);
		p=NULL;
		p=q->next;
		//p=q;
		//p=p->next;
	}
	fclose(fp);	//关闭文件
	return 1;
}
