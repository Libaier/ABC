#include <iostream>
using namespace std;
class MyClass20
{
public:
	int a = 2;//error
	//enum {size = 1};//correct
	int b[10];
	int c;
	//MyClass20(MyClass20 a) :a(1){}

	MyClass20() :a(4) {
		//int *a = new int[size];
		//int c[a];
		a = 1;

	}
	void fun()
	{
		const int size1 = 1;
		//enum {size = 1};//correct
		int b1[size1];
		cout << "fun" << endl;
	}
	void fun() const
	{
		cout << "fun const" << endl;
	}
	~MyClass20(){
		cout << a << endl;
	}
private:
	
	//const int a ;
};

void main()
{

	int x[2] = { 1,1 };
	int(&z)[2] = x;
	//x++;
	cout << z;
	MyClass20 m;
	m.fun();
	getchar();
}