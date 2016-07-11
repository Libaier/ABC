#include <stdio.h>
class MyClass11
{
public:
	MyClass11()
	{
	}
	virtual void fun(int i){
		a = i;
	}
	~MyClass11(){
		printf("%d\n", a);
	}
	int a;
	
};
void main11()
{
	sizeof(MyClass11);
	MyClass11 *m = new MyClass11[10];
	for (size_t i = 0; i < 10; i++)
	{
		m[i].fun(i);
	}

	//m--;
	//m--;
	delete[] m;
	getchar();
}