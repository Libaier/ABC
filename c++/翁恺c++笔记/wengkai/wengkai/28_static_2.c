#include "28_static_1.h"

void main28()
{
	//在某个代码内
	*iptr01 = 72;
	//28_static_1.c 中的ivar01  变为72;
	pfun01();
	//hwfun();//不可调用
	getchar();
}
