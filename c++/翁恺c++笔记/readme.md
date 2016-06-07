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

5.3 初始化列表
* 初始化列表早于构造函数内程序执行，如果在构造函数里则是先初始化在赋值
* 可以用来初始化成员变量


6.1 对象组合(用对象制造出一个新的)

* 对象组合是一种软件重用的方法
	* fully
	* by reference

6.2 继承inheritance(用类制造出来一个新的)
* 允许共享成员变量，成员函数，接口
* 当一个子类继承父类后，那么就获得了父类所有的东西。

6.3子类父类关系
* 子类中与父类重载函数同名的函数，与父类的函数没有关系，因此会隐藏父类的所有重载函数，想要调用父类中的函数的方法是B.A::print(200)；
	* 只有c++有这种机制
	* [重载VS覆盖VS隐藏](http://www.cnblogs.com/qlee/archive/2011/07/04/2097055.html)

6.4函数重载与默认参数
* 函数返回值类型不同不构成重载
* 函数default value 是编译时的动作，编译器替你补上缺少的参数。尽量不要使用default value

6.5内联函数
* 