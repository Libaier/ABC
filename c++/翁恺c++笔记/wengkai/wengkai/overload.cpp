#include <iostream>
#include <complex>
using namespace std;

class Base
{
public:
	virtual void a(int x) { cout << "Base::a(int)" << endl; }
	// overload the Base::a(int) function
	virtual void a(double x) { cout << "Base::a(double)" << endl; }
	virtual void b(int x) { cout << "Base::b(int)" << endl; }
	void c(int x) { cout << "Base::c(int)" << endl; }
};

class Derived : public Base
{
public:
	// redefine the Base::a() function
	void a(complex<double> x) { cout << "Derived::a(complex)" << endl; }
	// override the Base::b(int) function
	void b(int x) { cout << "Derived::b(int)" << endl; }
	// redefine the Base::c() function
	void c(int x) { cout << "Derived::c(int)" << endl; }
};

int main()
{
	Base b;
	Derived d;
	Base* pb = new Derived;
	// ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¨C //
	b.a(1.0); // Base::a(double)
	d.a(1.0); // Derived::a(complex)
	pb->a(1.0); // Base::a(double), This is redefine the Base::a() function
	// pb->a(complex<double>(1.0, 2.0)); // clear the annotation and have a try
	// ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¨C //
	b.b(10); // Base::b(int)
	d.b(10); // Derived::b(int)
	pb->b(10); // Derived::b(int), This is the virtual function
	// ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¨C //
	delete pb;

	return 0;
}