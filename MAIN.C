#include"head.h"
#include"tuxing.h"
#include"mouse.h"
#include"hanzi.h"

#include"welcome.h"
#include"thanks.h"
#include"mainsc.h"
#include"gethelp.h"
#include"exhibit.h" 
#include"cutprice.h"
#include"advice.h"
#include"shop.h" 
#include"shopper.h" 
#include"nfound.h"
#include"func.h"
#include"gotime.h"
#include"change.h"
#include"buy.h"
#include"stati.h"
#include"setting.h"
#include"userinf.h"
#include"lottery.h"
#include"signup.h"
//short far *buffer;//11111 
//Ϊ��֤ˢͼ�ٶȣ���������һ���ڴ� �粻׼ʹ��ȫ�ֱ�������main��welcome��thanks��1ע�͵���welcome�е�2���ע�ͼ��� ��������� 
void main()
{
	int flag=0; 
	int whobuy=0;
	//buffer=(short far*)malloc(801*2);//�����ڴ� 11111
	setsvga();
	initmouse();
	while(1)
	{
		switch(flag)
		{
			case 0:
				welcome(&flag);//��ӭ����  ����� 
				break;
			case 1:
			  	thanks();//�˳����� 
			   	break;
			case 2:
				mainscreen(&flag);//ѡ��������  ����� 
				break;
			case 3:
				gethelp(&flag);//��������  ����� 
				break;
			case 4:
				exhibition(&flag);//������ѯչʾ����  ����� 
				break;
			case 5:
				cutprice(&flag);//�ؼ� 															����
				break;
			case 6:
				advice(&flag); //��������   ����� 
				break; 
			case 7:
				shop(&flag,&whobuy); // �̻�ѡ����� ����� 
				break; 
			case 8:
				shopper(&flag); //�˿�ѡ�����  ����� 
				break; 
			case 9:
				nfound(&flag); // 404 not found �����
				break; 
			case 10:
				func(&flag); //��ʾ�����ܽ���  �����
				break; 
			case 11:
				gotime(&flag); //��ʾʱ����� �����  
				break; 
			case 12:
				changegoods(&flag); //�˿Ͳ鿴��Ʒ���� �����
				break;
			case 13:
				buy(&flag,&whobuy); //������� ����� 
				break;
			case 14:
				statistics_count(&flag); //��Ʒͳ�ƽ��� 	����� 
				break;
			case 15:
				setting(&flag); //���ý��� liu 										����
				break;
			case 16:
				userinf(&flag); //�鿴�û���Ϣ���� 	����� 
				break;
			case 17:
				lottery(&flag); //�齱���� liu 										����
				break;		
			case 18:
				signup(&flag);//�˿�ע��ҳ��	����� 
				break;	
		}
	}				
}