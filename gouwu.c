#include"head.h"
#include"lianbiao.h"
#include"wenjian.h"
#include"gouwu.h"
#include"gukelian.h"
#include"gukewen.h"
#include"tongji.h"
#include"welcome.h"

float jiesuan(GOODS *l,char *s2,char *s3,int *jife)  //������lΪͷ�����ָ��������Ʒ�ļ۸񣬽���Ʒ�Ĵ����Ϣ��ͳ����Ϣ���ص���Ʒ�ļ�,����s3��ָ����û����Ƶ��û��ļ����ҳ������޸������
{
    float sum=0,j;
    GOODS *p;
    char s1[10];
    for(p=l->next;p!=NULL;p=p->next)
    {
        j=pricecount(p);
        sum+=j;
        strcpy(s1,p->bianhao);
        switch(s1[0])
		    {
		        case 'A': cunhuo(p,1);
                          cunhuo1(p,1);
                          break;
                case 'B': cunhuo(p,2);
                          cunhuo1(p,2);
                          break;
                case 'C': cunhuo(p,3);
                          cunhuo1(p,3);
                          break;
                case 'D': cunhuo(p,4);
                          cunhuo1(p,4);
                          break;
                default: SET_SVGA_MODE(0x03);
						printf("error");
						getch();
		    }
        tongji(p,s2);
        switch(s1[0])
		    {
		        case 'A': he("cfile\\jiajuc.txt","cfile\\tongji.txt");
                          break;
                case 'B': he("cfile\\shipinc.txt","cfile\\tongji.txt");
                          break;
                case 'C': he("cfile\\guoshuc.txt","cfile\\tongji.txt");
                          break;
                case 'D': he("cfile\\xihuc.txt","cfile\\tongji.txt");
                          break;
                default: SET_SVGA_MODE(0x03);
                			printf("error");
                			getch();
		    }
    }
    *jife=jifenincrease(s3,sum);
    return sum;
}

int cunhuozeng(GOODS *l,char *num)
{
    GOODS *p;
    char ste[5];  
    char *t;
	for(p=l->next;p!=NULL;p=p->next)
    {
        strcpy(ste,p->bianhao);
        switch(ste[0])
        {
            case 'A':   cunhuoz(p,1,num);
                        cunhuoz(p,2,num);
                        break;
            case 'B':   cunhuoz(p,3,num);
                        cunhuoz(p,4,num);

                        break;
            case 'C':   cunhuoz(p,5,num);
                        cunhuoz(p,6,num);

                        break;
            case 'D':   cunhuoz(p,7,num);
                        cunhuoz(p,8,num);
                        break;
            default:  SET_SVGA_MODE(0x03);
                        printf("error");
                        getch();
        }
        cunhuoz(p,9,"40");
    }
    return 1;
}

float pricecount(GOODS *l)  //����l��ָ������ڵ����Ʒ�۸�
{
    char s[10];
    strcpy(s,l->price);
    return atof(s);
}

int cunhuo(GOODS *l,int n)  //��lָ�����Ʒ����Ʒ�ļ����ҵ�������������
{
    int temp;
    char s[10];
    GOODS *h,*p;
    h=creat_list();
    switch(n)
    {
        case 1: file_open(h,"cfile\\jiaju.txt");
                break;
        case 2: file_open(h,"cfile\\shipin.txt");
                break;
        case 3: file_open(h,"cfile\\guoshu.txt");
                break;
        case 4: file_open(h,"cfile\\xihu.txt");
                break;
    }
    //file_open(h,s1);
    for(p=h->next;p!=NULL;p=p->next)
    {
        if(strcmp(l->name,p->name)==0)
        {
            strcpy(s,p->cunhuo);
            temp=atoi(s);
            temp-=1;
            if(temp==0)  //������Ϊ�㣬������Ʒ�ļ��н���ɾ��
            {
                p->last->next=p->next;
                p->next->last=p->last;
                free(p);
            }
            else
            {
                itoa(temp,s,10);
                strcpy(p->cunhuo,s);
            }
            break;
        }
    }
    switch(n)
    {
        case 1: file_save(h,"cfile\\jiaju.txt");
                break;
        case 2: file_save(h,"cfile\\shipin.txt");
                break;
        case 3: file_save(h,"cfile\\guoshu.txt");
                break;
        case 4: file_save(h,"cfile\\xihu.txt");
                break;
    }
    //file_save(h,s1);
    free_head1(h);
    free(h);
    return 1;
}

int cunhuo1(GOODS *l,int n)  //��lָ�����Ʒ����Ʒԭ�ļ����ҵ�������������
{
    int temp;
    char s[10];
    GOODS *h,*p;
    h=creat_list();
    switch(n)
    {
        case 1: file_open(h,"cfile\\jiajuc.txt");
                break;
        case 2: file_open(h,"cfile\\shipinc.txt");
                break;
        case 3: file_open(h,"cfile\\guoshuc.txt");
                break;
        case 4: file_open(h,"cfile\\xihuc.txt");
                break;
    }
    //file_open(h,s1);
    for(p=h->next;p!=NULL;p=p->next)
    {
        if(strcmp(l->name,p->name)==0)
        {
            strcpy(s,p->cunhuo);
            temp=atoi(s);
            temp-=1;
            itoa(temp,s,10);
            strcpy(p->cunhuo,s);
            break;
        }
    }
    switch(n)
    {
        case 1: file_save(h,"cfile\\jiajuc.txt");
                break;
        case 2: file_save(h,"cfile\\shipinc.txt");
                break;
        case 3: file_save(h,"cfile\\guoshuc.txt");
                break;
        case 4: file_save(h,"cfile\\xihuc.txt");
                break;
    }
    //file_save(h,s1);
    free_head1(h);
    free(h);
    return 1;
}

int cunhuoz(GOODS *l,int n,char *num)  //��lָ�����Ʒ���ļ����ҵ������������� numΪ�µĴ����
{
    int temp;
    char s[10];
	//char *p;
	GOODS *h,*p,*q;
    //p=(char*)malloc(25*sizeof(char));
    h=creat_list();
    switch(n)
    {
        case 1: file_open(h,"cfile\\jiaju.txt");
                break;
        case 2: file_open(h,"cfile\\jiajuc.txt");
                break;
        case 3: file_open(h,"cfile\\shipin.txt");
                break;
        case 4: file_open(h,"cfile\\shipinc.txt");
                break;
        case 5: file_open(h,"cfile\\guoshu.txt");
                break;
        case 6: file_open(h,"cfile\\guoshuc.txt");
                break;
        case 7: file_open(h,"cfile\\xihu.txt");
                break;
        case 8: file_open(h,"cfile\\xihuc.txt");
                break;
        case 9: file_open(h,"cfile\\TONGJI.txt");
                break;
    }
    //file_open(h,s1);
    for(p=h->next;p!=NULL;p=p->next)
    {
        if(strcmp(l->bianhao,p->bianhao)==0)
        {
            strcpy(p->cunhuo,"50");
            break;
        }
    }
    if(p==NULL)    //�����ͳ��������û���ҵ���˵������Ʒ֮ǰû�����۹�����������������½�
        {
            for(p=h->next;p!=NULL;p=p->next)
            {
                if(strcmp(p->bianhao,l->bianhao)>0)
                {
                    q=(GOODS *)malloc(sizeof(GOODS));
                    q->next=NULL;
                    q->last=NULL;
                    strcpy(q->name,l->name);
                    strcpy(q->price,l->price);
                    strcpy(q->leixing,l->leixing);
                    strcpy(q->cunhuo,"50");
                    strcpy(q->tlujing,l->tlujing);
                    strcpy(q->xiaoliang,l->xiaoliang);
                    strcpy(q->jinjia,l->jinjia);
                    strcpy(q->bianhao,l->bianhao);
                    q->next=p;
                    q->last=p->last;
                    p->last->next=q;
                    p->last=q;
                    break;
                }
            }
        }
    switch(n)
    {
        case 1: file_save(h,"cfile\\jiaju.txt");
                break;
        case 2: file_save(h,"cfile\\jiajuc.txt");
                break;
        case 3: file_save(h,"cfile\\shipin.txt");
                break;
        case 4: file_save(h,"cfile\\shipinc.txt");
                break;
        case 5: file_save(h,"cfile\\guoshu.txt");
                break;
        case 6: file_save(h,"cfile\\guoshuc.txt");
                break;
        case 7: file_save(h,"cfile\\xihu.txt");
                break;
        case 8: file_save(h,"cfile\\xihuc.txt");
                break;
        case 9: file_save(h,"cfile\\TONGJI.txt");
                break;
    }
    //file_save(h,s1);
    free_head1(h);
    free(h);
    return 1;
}


int tongji(GOODS *l,char *s2)  //��lָ�����Ʒ��ͳ���ļ����ҵ�����û�����½�,����������
{
    int temp;
    char s[10];
    GOODS *h,*p,*q;
    h=creat_list();
    file_open(h,s2);
    for(p=h->next;p!=NULL;p=p->next)
    {
        if(strcmp(l->name,p->name)==0)
        {
            strcpy(s,p->xiaoliang);
            temp=atoi(s);
            temp+=1;
            itoa(temp,s,10);
            strcpy(p->xiaoliang,s);
            break;
        }
        if(p->next==NULL)    //�����ͳ��������û���ҵ���˵������Ʒ֮ǰû�����۹�����������������½�
        {
            q=(GOODS *)malloc(sizeof(GOODS));
			q->next=NULL;
			q->last=NULL;
			strcpy(q->name,l->name);
			strcpy(q->price,l->price);
			strcpy(q->leixing,l->leixing);
			strcpy(q->cunhuo,l->cunhuo);
			strcpy(q->tlujing,l->tlujing);
			strcpy(q->xiaoliang,l->xiaoliang);
			strcpy(q->jinjia,l->jinjia);
			strcpy(q->bianhao,l->bianhao);
			p->next=q;
			q->next=NULL;
			q->last=p;
        }
    }
    file_save(h,s2);
    free_head1(h);
    free(h);
    return 1;
}

GOODS *jinhuo(char *s1,char *s2)  //����Ʒԭʼ�ļ�s1����Ʒ�ļ�s2���Ƚϣ��Ӷ�������Ҫ��������Ʒ,������headΪͷ����������
{
    int a=0;
    GOODS *h1,*h2,*head,*p,*q,*l,*k;
    h1=creat_list();
    h2=creat_list();
    head=creat_list();
    file_open(h1,s1);
    file_open(h2,s2);
    k=head;
    for(p=h1->next;p!=NULL;p=p->next)
    {
        for(q=h2->next;q!=NULL;q=q->next)
        {
            if(strcmp(p->name,q->name)==0)
            {
                a=1;
                break;
            }
        }
        if(a==0)
        {
            l=(GOODS *)malloc(sizeof(GOODS));
			l->next=NULL;
			l->last=NULL;
			strcpy(l->name,p->name);
			strcpy(l->price,p->price);
			strcpy(l->leixing,p->leixing);
			strcpy(l->cunhuo,p->cunhuo);
			strcpy(l->tlujing,p->tlujing);
			strcpy(l->xiaoliang,p->xiaoliang);
			strcpy(l->jinjia,p->jinjia);
			strcpy(l->bianhao,p->bianhao);
			k->next=l;
			l->next=NULL;
			l->last=k;
			k=k->next;
        }
        a=0;
    }
    free_head1(h1);
    free(h1);
    free_head1(h2);
    free(h2);
    return head;
}

int jifenincrease(char *s3,int sum)  //����Ϊs3���û����û��ļ����ҵ������޸������ļ��еĻ��֣�����ͬʱ���ع˿��ڱ��ι��������û���
{
    int temp;                                  //�����ۼƵĹ����ǽ������ܼ�ת��Ϊ���κ��ʮ
    char m[10];
    CUST *h,*p;
    h=creat_cust();
    gukefile_open(h,"cfile\\GUKE.txt");
    for(p=h->next;p!=NULL;p=p->next)
    {
        if(strcmp(s3,p->zhanghao)==0)
        {
            strcpy(m,p->jifen);
            temp=atoi(m);
            temp+=sum*10;
            itoa(temp,m,10);
            strcpy(p->jifen,m);
            break;
        }
    }
    gukefile_save(h,"cfile\\GUKE.txt");
    free_custhead(h);
    free(h);
    return sum*10;
}

int xmpipei(char *s3)  //����Ϊs3���û����û��ļ����ҵ������ҵ��򷵻�1�����򷵻�0
{
    CUST *h,*p;
    h=creat_cust();
    gukefile_open(h,"cfile\\GUKE.txt");
    for(p=h->next;p!=NULL;p=p->next)
    {
        if(strcmp(s3,p->zhanghao)==0)
        {
            free_custhead(h);
            free(h);
            return 1;
        }
    }
    free_custhead(h);
    free(h);
    return 0;
}
