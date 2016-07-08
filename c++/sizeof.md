###[sizeof](http://blog.csdn.net/lanxuezaipiao/article/details/41557307)
		
		class A {
		public:
		    virtual void funa();
		    virtual void funb();
		    void func();
		    static void fund();
		    static int si;
		private:
		    int i;
		    char c;
		};

问：sizeof(A) = ?

解答： 
关于类占用的内存空间，有以下几点需要注意： 
（1）如果类中含有虚函数，则编译器需要为类构建虚函数表，类中需要存储一个指针指向这个虚函数表的首地址，注意不管有几个虚函数，都只建立一张表，所有的虚函数地址都存在这张表里，类中只需要一个指针指向虚函数表首地址即可。 
（2）类中的静态成员是被类所有实例所共享的，它不计入sizeof计算的空间 
（3）类中的普通函数或静态普通函数都存储在栈中，不计入sizeof计算的空间 
（4）类成员采用字节对齐的方式分配空间

答案：12（32位系统）或16（64位系统）