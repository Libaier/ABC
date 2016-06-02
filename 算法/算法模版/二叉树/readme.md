二叉树 cheatsheet
=======

##树的遍历

* [**递归方法**](./Binary Tree Traversal-Iterative.cpp)
	* 前序/中序/后序
		* 标准递归，使用两个函数，结果作为参数(引用)
	* 竖直层级
		* 标准先序递归，加入level参数 
	* zigzag层级
		* 与竖直层级相同，添加level奇偶检测，翻转
	* 水平层级
		* 加入水平层级参数hd,(每个水平层级都要从上到下排列会出现bug)
* [**迭代方法**](./Binary Tree Traversal-Recursive.cpp)
	* 前序/中序/后序
		* 方法一：使用栈visited记录访问过但还未输出的节点，使用visiting记录当前访问节点
			* 前序，中序均可使用此方法，后序使用根->右->左前序遍历翻转得到
		* 方法二:  For each node N, push N in stack -> push left tree of N in stack -> pop left tree of N -> push right tree of N in stack -> pop right tree of N -> pop N 
			* 前序，中序，后序均可使用此方法
	* 竖直层级
		* 使用队列实现 
	* zigzag层级
		* 与竖直层级相同，添加level奇偶检测，翻转
	* 水平层级
		* 在竖直层级基础上，加入水平层级参数hd，使用map实现


