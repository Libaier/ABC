#include <iostream>
using namespace std;
class MyClass27
{
public:
	//const size = 1;//error
	enum { size = 1 };//correct
	int b[size];
	MyClass27(const MyClass27 &a) {
		cout << "fun copy" << endl;
	}

	MyClass27() {}
	void fun()
	{
		cout << "fun" << endl;
	}
	void fun() const
	{
		cout << "fun const" << endl;
	}
	~MyClass27(){
	}

};

MyClass27 copy()
{
	//MyClass27 m;
	//return m;
	return MyClass27();
}

void main27()
{
	MyClass27 m1;
	MyClass27 m2 = copy();
	getchar();
}