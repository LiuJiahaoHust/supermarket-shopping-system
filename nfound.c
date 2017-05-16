#include"head.h"
#include"welcome.h"
#include"nfound.h"
#include"tuxing.h"

void nfound(int *flag)
{
	put_pic(0,0,"404.bmp",1); 
	getch();
	*flag=2;
	return;
}
