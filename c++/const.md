##const

* 必须初始化
* 不可修改

##const指针

* char* const p 指向地址不可修改

* const char*  p/  char const*  p 所指内容不可修改

* 
		int i = 5;
		const int *cip = &i;
		i = 6;
		cout << *cip;//6
		const int ci = 5;
		int *p  = &ci;//error

* 在定义一个字符串"hello"的时候,也有两种方式
	* 1.如果你希望你可以去在后面的程序修改这个字符串的内容,就写成
		
		char s[ ]="hello";  //数组的形式
	数组的写法是将代码段里面的常量数组赋值到变量储存内存空间里.!!!
	* 2.如果不希望它被修改,就写成指针的形式
	char* s="hello"; //指针的形式
	后者其实是定义成了一个const char* s;
	就算你后续拿s去做别的用途,也不能通过它去修改值.切记!!!!

	正确的写法是:
	const char *s ="hello";  编译就会去检测,能够避免你去尝试修改代码段里面的内容.
* 在函数的后面加const，表示这个函数不修改任何成员变量，意味着this是const的。声明和定义中都要加const