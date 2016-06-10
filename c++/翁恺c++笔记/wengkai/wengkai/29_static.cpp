#include <iostream>
using namespace std;
class MyClass29
{
public:
	//const size = 1;//error
	enum { size = 1 };//correct
	int b[size];
	MyClass29(const MyClass29 &a) {
		cout << "fun copy" << endl;
	}

	MyClass29() {}
	void fun()
	{
		cout << "fun" << endl;
	}
	void fun() const
	{
		cout << "fun const" << endl;
	}
	~MyClass29(){
	}
private:
	static int a;
};

int MyClass29::a = 20;

void main29()
{
	MyClass29 m1;
	MyClass29 m2 ;
	getchar();
}