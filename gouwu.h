#ifndef   ___GOUWU_H__
#define   ___GOUWU_H__

float jiesuan(GOODS *l,char *s2,char *s3,int *jife);
//������lΪͷ�����ָ��������Ʒ�ļ۸񣬽���Ʒ�Ĵ����Ϣ��ͳ����Ϣ���ص���Ʒ�ļ�
//����s3��ָ����û����Ƶ��û��ļ����ҳ������޸������

int cunhuozeng(GOODS *l,char *num);

float pricecount(GOODS *l);
//����l��ָ������ڵ����Ʒ�۸�

int cunhuo(GOODS *l,int i);
//��lָ�����Ʒ����Ʒ�ļ����ҵ�������������

int cunhuo1(GOODS *l,int i);
//��lָ�����Ʒ����Ʒԭ�ļ����ҵ�������������

int cunhuoz(GOODS *l,int n,char *num);
//��lָ�����Ʒ���ļ����ҵ������������� numΪ�µĴ����

int tongji(GOODS *l,char *s2);
//��lָ�����Ʒ��ͳ���ļ����ҵ�����û�����½�,����������

GOODS *jinhuo(char *s1,char *s2);
//����Ʒԭʼ�ļ�s1����Ʒ�ļ�s2���Ƚϣ��Ӷ�������Ҫ��������Ʒ,������headΪͷ����������

int jifenincrease(char *s3,int sum);
//����Ϊs3���û����û��ļ�s���ҵ������޸������ļ��еĻ��֣�����ͬʱ���ع˿��ڱ��ι��������û���

int xmpipei(char *s3);
//����Ϊs3���û����û��ļ����ҵ������ҵ��򷵻�1�����򷵻�0

#endif
