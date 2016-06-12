#include <iostream>
using namespace std;
class ex1
{
public:
	ex1(){
	}
	~ex1(){}

private:

};

class ex2
{
public:
	ex2(){
	}
	~ex2(){}
private:

};


void fun()throw(ex1)
{
	throw ex2();//分配在栈上
	cout << "here1" << endl;//不执行到这里
}

//void swap2<int>();
void main()
{

	try{
		fun();
	}
	catch (ex2 i){//...表示接受所有异常
		cout << "exception" << endl;
	}
	cout << "here2" << endl;


}