#include <iostream>
using namespace std;

template <class T>
void swap1(T &t1, T &t2)
{
	T temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}

template <class T>
void swap2(void)
{

}

template < class T >
class MyClass34
{
public:
	MyClass34(){

	}
	~MyClass34(){

	}

	T getT(){

	}
private:

};


//void swap2<int>();
void main34()
{
	int a = 1,b=2;
	MyClass34<int> m1;
	MyClass34<int> m2;
	//m1 < m2;
	
	swap1(a,b);
	cout << a << " " << b << endl;
	getchar();

}