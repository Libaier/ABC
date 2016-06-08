#include <iostream>
using namespace std;
class MyClass20
{
public:
	//const size = 1;//error
	enum {size = 1};//correct
	int b[size];

	MyClass20() :a(1){}
	void fun()
	{
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
	const int a ;
};

void main()
{
	int x[2] = { 1,1 };
	int(&z)[2] = x;
	//x++;
	cout << z;
	const MyClass20 m;
	m.fun();
	getchar();
}