#include <iostream>
using namespace std;
class MyClass12
{
public:
	MyClass12(int a = 2) :b(a)
	{
	}
	void fun(int i){
		a = i;
	}
	void fun1(MyClass12* i){
		cout << i->a<<endl;
	}
	~MyClass12(){
		cout << a<<endl;
	}
private:
	int a;
	const int b = 0;
};

void main12()
{
	MyClass12 *m = new MyClass12[10];
	for (size_t i = 0; i < 10; i++)
	{
		m[i].fun(i);
	}
	MyClass12 b;
	b.fun(100);
	m[0].fun1(&b);
	
	delete[] m;
	getchar();
}