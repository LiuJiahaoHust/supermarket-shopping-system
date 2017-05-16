#include"tongji.h"
#include"wenjian.h"
#include"gukewen.h"
#include"head.h"

float xiaoshoue(GOODS *l)  //判断由l指向的统计文件中的总的销售额
{
    float sum=0,temp,i;
    GOODS *p;
    for(p=l->next;p!=NULL;p=p->next)
    {
        temp=atof(p->price);
        i=atof(p->xiaoliang);
        sum+=temp*i;
    }
    return sum;
}

float chengbene(GOODS *l)  //判断由l指向的统计文件中的总的商品成本
{
    float sum=0,temp,i;
    GOODS *p;
    for(p=l->next;p!=NULL;p=p->next)
    {
        temp=atof(p->jinjia);
        i=atof(p->xiaoliang);
        sum+=temp*i;
    }
    return sum;
}

float shourue(GOODS *l)  //判断由l指向的统计文件中的总的收入
{
    float sum1,sum2;
    sum1=xiaoshoue(l);
    sum2=chengbene(l);
    return sum1-sum2;
}

int shourup(GOODS *l,int i)  //将销售的商品按其收入进行排序,其中若i=0，则按升序排列，若i=1，则按照降序排列
{
    float j1,j2,j3,j,k,k1,k2,k3;
    GOODS *p,*q,temp;
    for(p=l->next;p->next!=NULL;p=p->next)
    {
        j1=atof(p->price);
        j2=atof(p->jinjia);
        j3=atof(p->xiaoliang);
        j=j3*(j1-j2);
        for(q=p->next;q!=NULL;q=q->next)
        {
            k1=atof(q->price);
            k2=atof(q->jinjia);
            k3=atof(q->xiaoliang);
            k=k3*(k1-k2);
            switch(i)
            {
                case 0: if(k<j)
                        {
                            change(&temp,p);
                            change(p,q);
                            change(q,&temp);
                            j1=atof(p->price);
                            j2=atof(p->jinjia);
                            j3=atof(p->xiaoliang);
                            j=j3*(j1-j2);
                        }
                        break;
                case 1: if(k>j)
                        {
                            change(&temp,p);
                            change(p,q);
                            change(q,&temp);
                            j1=atof(p->price);
                            j2=atof(p->jinjia);
                            j3=atof(p->xiaoliang);
                            j=j3*(j1-j2);
                        }
                        break;
            }
        }
    }
    return 1;
}

int xiaoliangp(GOODS *l,int i)  //将销售的商品按其销量进行排序,其中若i=0，则按升序排列，若i=1，则按照降序排列
{
    float j,k;
    GOODS *p,*q,temp;
    for(p=l->next;p->next!=NULL;p=p->next)
    {
        j=atof(p->xiaoliang);
        for(q=p->next;q!=NULL;q=q->next)
        {
            k=atof(q->xiaoliang);
            switch(i)
            {
                case 0: if(k<j)
                        {
                            change(&temp,p);
                            change(p,q);
                            change(q,&temp);
                            j=atof(p->xiaoliang);
                        }
                        break;
                case 1: if(k>j)
                        {
                            change(&temp,p);
                            change(p,q);
                            change(q,&temp);
                            j=atof(p->xiaoliang);
                        }
                        break;
            }
        }
    }
    return 1;
}

int cunhuop(GOODS *l,int i) //将销售的商品按其存货量进行排序,其中若i=0，则按升序排列，若i=1，则按照降序排列
{
    int j,k;
    GOODS *p,*q,temp;
    for(p=l->next;p->next!=NULL;p=p->next)
    {
        j=atoi(p->cunhuo);
        for(q=p->next;q!=NULL;q=q->next)
        {
            k=atoi(q->cunhuo);
            switch(i)
            {
                case 0: if(k<j)
                        {
                            change(&temp,p);
                            change(p,q);
                            change(q,&temp);
                            j=atoi(p->cunhuo);
                        }
                        break;
                case 1: if(k>j)
                        {
                            change(&temp,p);
                            change(p,q);
                            change(q,&temp);
                            j=atoi(p->cunhuo);
                        }
                        break;
            }
        }
    }
    return 1;
}

int gukejifen(CUST *l,int i)  //将顾客按照其积分进行排序，其中若i=0，则按升序排列，若i=1，则按照降序排列
{
    int j,k;
    CUST *p,*q,temp;
    for(p=l->next;p->next!=NULL;p=p->next)
    {
        j=atoi(p->jifen);
        for(q=p->next;q!=NULL;q=q->next)
        {
            k=atoi(q->jifen);
            switch(i)
            {
                case 0: if(k<j)
                        {
                            changecust(&temp,p);
                            changecust(p,q);
                            changecust(q,&temp);
                        }
                        break;
                case 1: if(k>j)
                        {
                            changecust(&temp,p);
                            changecust(p,q);
                            changecust(q,&temp);
                        }
                        break;
            }
        }
    }
    return 1;
}

GOODS *dinghuotuijian(char *s2)  //该函数通过对统计文件中商品收入的分析,
{
    int i=0,j,k;
    int tem[30];
    GOODS *h,*h1,*h2,*h3,*p,*q,temp;
    for(i=0;i<30;i++)
		tem[i]=0;
    i=0;
    h=creat_list();
    file_open(h,s2);
    h1=copylist(h);
    h2=copylist(h);
    h3=copylist(h);
    shourup(h1,0);
    xiaoliangp(h2,0);
    cunhuop(h3,1);
    for(p=h->next;p!=NULL;p=p->next)
    {
        tem[i]=quanzhong(p->bianhao,h1,h2,h3);
        i++;
    }
    for(i=0,p=h->next;tem[i+1]!=0;i++,p=p->next)
    {
        for(j=i+1,q=p->next;tem[j]!=0;j++,q=q->next)
        {
            if(tem[i]<tem[j])
            {
                k=tem[i];
                tem[i]=tem[j];
                tem[j]=k;
                change(&temp,p);
                change(p,q);
                change(q,&temp);
            }
        }
    }
    free_head1(h1);
    free(h1);
    free_head1(h2);
    free(h2);
    free_head1(h3);
    free(h3);
    return h;
}

int he(char*s1,char *s2)  //将商品文件和统计文件中的信息合并 ps:由于之前结算时统计文件中没有对存货进行操作，商品文件中没有对销量进行操作
{
    GOODS *h1,*h2,*p,*q;
    h1=creat_list();
    h2=creat_list();
    file_open(h1,s1);
    file_open(h2,s2);
    for(p=h1->next;p!=NULL;p=p->next)
    {
        for(q=h2->next;q!=NULL;q=q->next)
        {
            if(strcmp(p->name,q->name)==0)
            {
                strcpy(p->xiaoliang,q->xiaoliang);
                strcpy(q->cunhuo,p->cunhuo);
            }
        }
    }
    file_save(h1,s1);
    file_save(h2,s2);
    free_head1(h1);
    free(h1);
    free_head1(h2);
    free(h2);
    return 1;
}


int quanzhong(char *s,GOODS *h1,GOODS *h2,GOODS *h3)  //改函数返回商品的权重，从而确定商品订货的顺序
{
    int a1=0,a2=0,a3=0;
    GOODS *p;
    for(p=h1->next;p!=NULL;p=p->next)
    {
        a1++;
        if(strcmp(s,p->bianhao)==0)
            break;
    }
    for(p=h2->next;p!=NULL;p=p->next)
    {
        a2++;
        if(strcmp(s,p->bianhao)==0)
            break;
    }
    for(p=h3->next;p!=NULL;p=p->next)
    {
        a3++;
        if(strcmp(s,p->bianhao)==0)
            break;
    }
    return a1+a2+a3;
}
