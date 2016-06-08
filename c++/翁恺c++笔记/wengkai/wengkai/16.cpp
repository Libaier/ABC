#include <iostream>
using namespace std;
class MyClass16
{
public:
	MyClass16(int a) 
	{
	}
	void fun(int i,int j=0){
		a = i;
	}
	void fun(MyClass16* i){
		cout << i->a << endl;
	}
	~MyClass16(){
		cout << a << endl;
	}
private:
	int a;
};

class MyClass16a :public MyClass16
{
public:
	MyClass16a() :MyClass16(1)
	{

	}
	void fun()
	{
		//fun(1);
	}
};


void main16()
{
	//const int ci = 5;
	//int *p = &ci;//error
	MyClass16a m;
	m.fun();
	m.MyClass16::fun(1);
	getchar();

}