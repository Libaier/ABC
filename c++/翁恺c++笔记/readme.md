[翁凯c++ ](http://study.163.com/course/courseMain.htm?courseId=271005)
=======
#1.0第一个c++程序

* cout<<，cin>>其实是左移右移

#2.1什么是面向对象

* 面向对象是从对象出发考虑问题
* 对象 = 属性+操作(函数)
* 面向过程的属性和(函数)是分离的，面向对象是在一起的
* 面向对象focus on things，not operations

#2.2面向对象基本原理

##对象发送消息

##对象VS类
* 实例，类

##OOP五项原则
* 一切东西都是对象
* 程序是一堆互相之间发送消息告诉对方what to do(不是how to do)的对象
* 每个对象都有自己的内存，内存里又是由其他对象组成
* 所有对象都有类型
* 一个特定类型的对象都能接受相同类型的消息。都能接受相同类型的消息可以划归为一个类型

##对象都有接口
* 作用：通信、保护。

##封装(Encapsulation)

#3.1自动售票机的例子

* 一个简单定义和实现类的例子
* ::域的解析符 

#3.2头文件

* g++过程
	* .ii	预处理
	* .s	汇编
	* .o	单独编译各个cpp为目标文件
	* .out	链接

* 声明VS定义

#3.3时钟的例子

* 抽象

#3.4成员变量
*	成员变量
*	函数参数
*	局部变量

#4.1成员变量的秘密

*	成员变量
*	函数参数(本地存储)
*	局部变量(本地存储)

*	类中各个函数其实藏了一个this指针
*	a.fun(); 对应于 fun(&a)

#4.2构造与析构
* 析构在括号关闭时调用，还有delete时

#4.3对象初始化
* 空间是在进入大括号时分配，构造函数是在调用时才运行的

#5.1new delete
* delete VS delete[]

	    int *a = new int[10];
    	a++;
    	delete[] a;//出错,查表删除，发现表中不存在a所指地址
#5.2访问限制
*	public
*	private 是对类的，不是对对象的，且只在编译时刻检查
	
	    class MyClass12
	    {
		    public:
				MyClass12()
		    	{
		    	}
		    	void fun(int i){
		    		a = i;
		    	}
		    	void fun1(MyClass12* i){
		    		cout << i->a<<endl;//可以访问
		    	}
		    	~MyClass12(){
		    		cout << a<<endl;
		    	}	
			private:
		    	int a;
	    };
* friends声明为friend，别人可以访问你的
* protected

*	class VS struct
	*	class 默认private
	*	struct默认public
	*	最好首选class，如果只是变量的组合用struct

#5.3 初始化列表
* 初始化列表早于构造函数内程序执行，如果在构造函数里则是先初始化在赋值
* 可以用来初始化成员变量


#6.1 对象组合(用对象制造出一个新的)

* 对象组合是一种软件重用的方法
	* fully
	* by reference

#6.2 继承inheritance(用类制造出来一个新的)
* 允许共享成员变量，成员函数，接口
* 当一个子类继承父类后，那么就获得了父类所有的东西。

#6.3子类父类关系
* 子类中与父类重载函数同名的函数，与父类的函数没有关系，因此会隐藏父类的所有重载函数，想要调用父类中的函数的方法是B.A::print(200)；
	* 只有c++有这种机制
	* [重载VS覆盖VS隐藏](http://www.cnblogs.com/qlee/archive/2011/07/04/2097055.html)

#6.4函数重载与默认参数
* 函数返回值类型不同不构成重载
* 函数default value 是编译时的动作，编译器替你补上缺少的参数。尽量不要使用default value

#6.5内联函数

* 函数调用过程
	* push 参数
	* push 返回值
	* 准备返回值
	* pop all

* 内联inline函数
	* 有类型检查(编译器做)
	* 必须在.h和.cpp中repeat(关键字inline 必须与函数定义体放在一起才能使函数成为内联，仅将inline 放在函数声明前面不起任何作用。)
	* 定义在类声明之中的成员函数将自动地成为内联函数

#6.6[const](../const.md)

#6.7不可修改的对象

* const函数构成overload

    void fun(){}
	void fun() const{}//this const
* 若一个类的对象定义为const，如：const A a；则在调用成员函数时必须使用const格式的成员函数，若没有const格式的成员函数，则报错，编译不通过。


* 成员变量const
	* 在初始化列表初始化

* 枚举可以做数组大小参数，const不可以

    	//const size = 1;//error
    	enum {size = 1};//correct
    	int b[size];

#6.8引用

* c++ VS JAVA	
	* c++
		* 三种对象存在的方式
			* 堆
			* 栈
			* 全局数据区
		* 三种对象的访问方式
			* 直接访问对象
			* 指针
			* 引用
	* java 只有堆和引用(但更像c++指针)访问方式


* 引用规则
	* 引用必须初始化
	* const int&z = x;//不用通过z修改x 

* 两种理解
	* 引用是变量的别名
	* 用const指针实现，因为*不好看才出现

* 引用和指针比较
	* 引用不可null，指针可null
	* 引用不可变，指针可变
	* 引用are dependent on an existing variable,they are an alias for an variable,pointers is independent of existing objects
* Tips
	* 没有引用的引用
	* `int &*p 错误，引用的指针，不能取到引用的地址 int *&p 正确,指针的引用`
	* 没有引用的数组，但有数组的引用

    		int x[2] = { 1,1 };
			int(&z)[2] = x;//正确
			int&z[2] = x;//错误
#6.9向上造型
* 子类A 父类B
	* B = A
	* B* = A*
	* B& = A&

* cast
	* c 类型转换 数据丢了 
	* c++ 造型 数据没丢，只是看法变了

#6.11引用再研究
* 当引用是成员变量用初始化列表初始化
* 函数返回值是引用可以做左值
* const reference做函数参数传递，比值传递快


#6.12拷贝构造