#include <iostream>
using namespace std;
class Shape
{
public:
	Shape();
	virtual ~Shape();
	double center;
	virtual void render();
};

class Circle:Shape
{
public:
	virtual void render()
	{
		cout<<"Circle"<<endl;
	}
private:
	int R;
};

class Square:Shape
{
public:
	virtual void render()
	{
		cout<<"Square"<<endl;
	}
private:
	int R;
};

void main(int argc, char const *argv[])
{
	Shape s = new Square();
	s.render();
	return 0;
}