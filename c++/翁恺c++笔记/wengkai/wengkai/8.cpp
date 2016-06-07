#include <stdio.h>
class MyClass8
{
public:
	MyClass8()
	{
		//a = 1;
	}
	void fun(){
		printf("&(MyClass8.a):%p\n",&a);
		printf("&(MyClass8.a):%p\n", this);
	}
	~MyClass8(){

	}
	int a;
};

void main8()
{

	MyClass8 m;

	printf("&m:%p\n", &m);
	printf("&m.a:%p\n", &(m.a));
	m.fun();

	getchar();
}