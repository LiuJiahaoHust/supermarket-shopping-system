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
//为保证刷图速度，独立申请一块内存 如不准使用全局变量，将main，welcome，thanks中1注释掉，welcome中的2解除注释即可 （会变慢） 
void main()
{
	int flag=0; 
	int whobuy=0;
	//buffer=(short far*)malloc(801*2);//申请内存 11111
	setsvga();
	initmouse();
	while(1)
	{
		switch(flag)
		{
			case 0:
				welcome(&flag);//欢迎界面  已完成 
				break;
			case 1:
			  	thanks();//退出界面 
			   	break;
			case 2:
				mainscreen(&flag);//选择主界面  已完成 
				break;
			case 3:
				gethelp(&flag);//帮助界面  已完成 
				break;
			case 4:
				exhibition(&flag);//匿名查询展示界面  已完成 
				break;
			case 5:
				cutprice(&flag);//特价 															不做
				break;
			case 6:
				advice(&flag); //建议框界面   已完成 
				break; 
			case 7:
				shop(&flag,&whobuy); // 商户选择界面 已完成 
				break; 
			case 8:
				shopper(&flag); //顾客选择界面  已完成 
				break; 
			case 9:
				nfound(&flag); // 404 not found 已完成
				break; 
			case 10:
				func(&flag); //显示程序功能界面  最后做
				break; 
			case 11:
				gotime(&flag); //显示时间界面 已完成  
				break; 
			case 12:
				changegoods(&flag); //顾客查看商品界面 已完成
				break;
			case 13:
				buy(&flag,&whobuy); //购物界面 已完成 
				break;
			case 14:
				statistics_count(&flag); //商品统计界面 	已完成 
				break;
			case 15:
				setting(&flag); //设置界面 liu 										不做
				break;
			case 16:
				userinf(&flag); //查看用户信息界面 	已完成 
				break;
			case 17:
				lottery(&flag); //抽奖界面 liu 										不做
				break;		
			case 18:
				signup(&flag);//顾客注册页面	已完成 
				break;	
		}
	}				
}
