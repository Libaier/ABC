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
	throw ex2();//������ջ��
	cout << "here1" << endl;//��ִ�е�����
}

//void swap2<int>();
void main()
{

	try{
		fun();
	}
	catch (ex2 i){//...��ʾ���������쳣
		cout << "exception" << endl;
	}
	cout << "here2" << endl;


}