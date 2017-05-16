#include"head.h"
#include"wenjian.h"
#include"welcome.h"

int file_open(GOODS *l,char *s) //将s所指向的路径处的文件打开，将文件中的内容依次考入链表，并用l返回链表的头指针
{
    FILE *fp;
    GOODS *p,*q,*t;
    t=l;
    p=creat_list();//给p分配空间
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
			q=(GOODS *)malloc(sizeof(GOODS));				//将文件中的信息以fscanf打开到链表中去
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
	free(p);//释放p
	t->next=NULL;
	fclose(fp);											//关闭文件
	return 1;
}

int file_save(GOODS *l,char *s)						//将链表信息保存到文件
{
	FILE *fp;
	GOODS *p=NULL,*q=NULL;
	if((fp = fopen(s, "w"))==NULL)
	{
		printf("%s",s);
		getch();
		exit(1);
	}
	fclose(fp);               //将文件中原有的内容清空，或新建立一个文本文件
	if((fp=fopen(s,"at"))==NULL)	//判断能否打开文件
	{
		printf("%s",s);
		getch();
		exit(1);
	}
	p=l->next;

	while(p!=NULL)		//将链表中的信息以fprintf写入文件中去
	{
		fprintf(fp,"%10s%6s%10s%5s%20s%5s%6s%5s%c",p->name,p->price,p->leixing,p->cunhuo,p->tlujing,p->xiaoliang,p->jinjia,p->bianhao,'\n');
		p=p->next;
	}
	fclose(fp);	//关闭文件
	q=l;
	p=l->next;		//释放链表中信息占用的内存
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
