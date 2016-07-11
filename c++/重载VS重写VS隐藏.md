完全抄录于[C++ 重载(overload)、重写(overrride)、重定义(redefine)总结](http://www.wutianqi.com/?p=3171)，这篇是感觉所有博客里讲的最清楚的。

###重载（overload）

指函数名相同，但是它的参数表列个数或顺序，类型不同。但是不能靠返回类型来判断。

* 相同的范围（在同一个作用域中） ；
* 函数名字相同；
* 参数不同；
* virtual 关键字可有可无。
* 返回值可以不同；

###重写（也称为覆盖 override）

是指派生类重新定义基类的虚函数，特征是：

* 不在同一个作用域（分别位于派生类与基类） ；
* 函数名字相同；
* 参数相同；
* 基类函数必须有 virtual 关键字，不能有 static 。
* 返回值相同（或是协变），否则报错；<—-协变这个概念我也是第一次才知道…
* 重写函数的访问修饰符可以不同。尽管 virtual 是 private 的，派生类中重写改写为 public,protected 也是可以的


### 重定义（也成隐藏,hidden）

* 不在同一个作用域（分别位于派生类与基类） ；
* 函数名字相同；
* 返回值可以不同；
* 参数不同。此时，不论有无 virtual 关键字，基类的函数将被隐藏（注意别与重载以及覆盖混淆） 。
* 参数相同，但是基类函数没有 virtual关键字。此时，基类的函数被隐藏（注意别与覆盖混淆） 


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
		// ———————————– //
		b.a(1.0); // Base::a(double)
		d.a(1.0); // Derived::a(complex)
		pb->a(1.0); // Base::a(double), This is redefine the Base::a() function
		// pb->a(complex<double>(1.0, 2.0)); // clear the annotation and have a try
		// ———————————– //
		b.b(10); // Base::b(int)
		d.b(10); // Derived::b(int)
		pb->b(10); // Derived::b(int), This is the virtual function
		// ———————————– //
		delete pb;
		
		return 0;
		}

通过这里可以看出：

1.Base类中的第二个函数a是对第一个的重载

2.Derived类中的函数b是对Base类中函数b的重写，即使用了虚函数特性。

3.Derived类中的函数a是对Base泪中函数a的隐藏，即重定义了。

4.pb指针是一个指向Base类型的指针，但是它实际指向了一个Derived的空间，这里对pd调用函数的处理(多态性)取决于是否重写(虚函数特性)了函数，若没有，则依然调用基类。

5.只有在通过基类指针或基类引用 间接指向派生类类型时多态性才会起作用。

6.因为Base类的函数c没有定义为virtual虚函数，所以Derived类的函数c是对Base::c()的重定义。