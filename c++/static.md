static 
隐藏，持久存储

##c static
* 函数内 static变量其实就是全局变量，只是只能在函数内访问
* static 全局变量，其他文件加上extern也没法访问
* static函数？？


##c++ static
* static 类内成员变量 不依赖于对象
* static 类内成员变量只能在定义时初始化，不可以在初始化列表初始化
* static 成员函数可以不创建对象就调用函数，且不可访问非static成员变量，且没有this