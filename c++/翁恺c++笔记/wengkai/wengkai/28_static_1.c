#include "28_static_1.h"
static int ivar01 = 36;
int * iptr01 = &ivar01;

static void hwfun(void);
funcPtr pfun01 = &hwfun;

void hwfun(void)
{
	printf("hello world\n");
}