##引子
> 网络上对Kmeans直观解释的例子

>有四个牧师去郊区布道，一开始牧师们随意选了几个布道点，并且把这几个布道点的情况公告给了郊区所有的居民，于是每个居民到离自己家最近的布道点去听课。
听课之后，大家觉得距离太远了，于是每个牧师统计了一下自己的课上所有的居民的地址，搬到了所有地址的中心地带，并且在海报上更新了自己的布道点的位置。
牧师每一次移动不可能离所有人都更近，有的人发现A牧师移动以后自己还不如去B牧师处听课更近，于是每个居民又去了离自己最近的布道点……
就这样，牧师每个礼拜更新自己的位置，居民根据自己的情况选择布道点，最终稳定了下来。


##产生时间

虽然其思想能够追溯到1957年的Hugo Steinhaus ，术语“k-均值”于1967年才被James MacQueen 首次使用。标准算法则是在1957年被Stuart Lloyd作为一种脉冲码调制的技术所提出，但直到1982年才被贝尔实验室公开出版。在1965年，E.W.Forgy发表了本质上相同的方法，所以这一算法有时被称为Lloyd-Forgy方法。更高效的版本则被Hartigan and Wong提出（1975/1979）.

##适用场合

* 矢量的量化
	* 在计算机图形学中，色彩量化的任务，就是要把一张图像的色彩范围减少到一个固定的数目k上来。
* 聚类分析
	* 在聚类分析中，k-均值算法被用来将输入数据划分到k个部分(聚类)中。
* 特征学习
	* 在（半）监督学习或无监督学习中，k-均值聚类被用来进行特征学习（或字典学习）步骤。

##原理推导

K-means是为了求解如下公式，其中$$$S = {S_1,S_2,...,S_n}$$$表示n个聚类后的类别。

$$\mathop {\arg \min }\limits_S \sum\limits\_{i = 1}^k {\sum\limits\_{j \in {S\_i}}^{} {||{x\_j} - {\mu _{{S_i}}}|{|^2}} } $$

在一般欧式空间中，即使是两个簇，这个问题是NP难问题，即使在二维欧式空间，对一般的簇个数k，该问题也是NP难的。K-means使用贪心算法，通过迭代的方式克服计算中的巨大开销。

> Tips:如果一个问题可以找到一个能在多项式的时间里解决它的算法，那么这个问题就属于P问题。NP问题不是非P类问题。NP问题是指可以在多项式的时间里验证一个解的问题。NP问题的另一个定义是，可以在多项式的时间里猜出一个解的问题。NPC问题的定义非常简单。同时满足下面两个条件的问题就是NPC问题。首先，它得是一个NP问题；然后，所有的NP问题都可以约化到它。NP-Hard问题是这样一种问题，它满足NPC问题定义的第二条但不一定要满足第一条（就是说，NP-Hard问题要比NPC问题的范围广）。


##求解方法

1. 选取初始聚类中心
2. 通过计算距离进行聚类
3. 重新计算聚类中心
4. 重复2-3步直至聚类中心不发生改变或者达到迭代次数上限

##伪代码
```

输入:数据集D(m个样本),聚类簇数k

过程:

从D中随机选择k个向量做聚类中心 
repeat
初始化聚类结果S_i为空集
for j = 0...m do
	计算样本与均值向量的距离，将其划归为对应的类别
end for

for
	使用均值法重新计算聚类中心
end for

until 聚类中心均不发生改变或者达到指定迭代次数 

输出:聚类结果集

```
###复杂度

* 时间复杂度：O(tKmn)，其中，t为迭代次数，K为簇的数目，m为记录数，n为维数
* 空间复杂度：O((m+K)n)，其中，K为簇的数目，m为记录数，n为维数

##优缺点

* 优点
	* 速度快，复杂度与样本数线性相关，即使在大数据下依旧保持良好效果
* 缺点
	* 聚类数目k是一个输入参数。选择不恰当的k值可能会导致糟糕的聚类结果。这也是为什么要进行特征检查来决定数据集的聚类数目了。
	* 收敛到局部最优解，可能导致“反直观”的错误结果。
	* k-均值算法的一个重要的局限性即在于它的聚类模型。这一模型的基本思想在于：得到相互分离的球状(各项同性)聚类，在这些聚类中，均值点趋向收敛于聚类中心。 一般会希望得到的聚类大小大致相当，这样把每个观测都分配到离它最近的聚类中心（即均值点）就是比较正确的分配方案。但遇到椭球或不规则数据可能会发生问题。
	
This example is meant to illustrate situations where k-means will produce unintuitive and possibly unexpected clusters. In the first three plots, the input data does not conform to some implicit assumption that k-means makes and undesirable clusters are produced as a result. In the last plot, k-means returns intuitive clusters despite unevenly sized blobs.	
![kmeans1](http://scikit-learn.org/stable/_images/plot_kmeans_assumptions_001.png)

Comparing different clustering algorithms on toy datasets

![kmeans1](http://scikit-learn.org/stable/_images/plot_cluster_comparison_001.png)

##算法延伸

> 此部分大多源自资料5，部分没看明白

* K如何确定？
	* 使用层次聚类确定	
* 初始质心的选取
	* K-means++	
* 算法中的距离不一定是欧式距离，可以自由定义任意符合距离定义要求的"距离"
* 空聚类的处理(不是很懂)

##关键领悟

* K-Means can be seen as a special case of Gaussian mixture model with equal covariance per component.
* K-means is equivalent to the expectation-maximization algorithm with a small, all-equal, diagonal covariance matrix.
* 这样从K-means里我们可以看出它其实就是EM的体现，E步是确定隐含类别S变量类别，M步更新其他参数$$$\mu$$$中心来使J最小化。这里的隐含类别变量指定方法比较特殊，属于硬指定，从k个类别中硬选出一个给样例，而不是对每个类别赋予不同的概率。总体思想还是一个迭代优化过程，有目标函数，也有参数变量，只是多了个隐含变量，确定其他参数估计隐含变量，再确定隐含变量估计其他参数，直至目标函数最优。
* K-Means才用了坐标下降法求解，先固定中心，优化类别，再固定类别，优化中心
* The algorithm can also be understood through the concept of Voronoi diagrams. 


##大数据下的加速

* mahout中对K-means的具体[实现](http://mahout.apache.org/users/clustering/k-means-clustering.html)
* spark Mlib中对K-means的[实现](http://spark.apache.org/docs/latest/mllib-statistics.html)

![](http://i.imgur.com/8XDqvbg.jpg)
![](http://i.imgur.com/3yHda1Q.jpg)
![](http://i.imgur.com/nsc8NCh.jpg)

##相关算法

* 聚类算法分类
	* 划分方法	1.发现球形互斥的簇 2.基于距离 3.可用均值或中心点代表簇中心 4.对中小规模数据有效
	* 层次方法	1.聚类是一个层次分解 2.不能纠正错误的合并或划分 3.可以集成其他技术
	* 基于密度的方法	1.可以发现任意形状的簇 2.簇是对象空间中被低密度区域分隔的稠密区域 3.簇密度 4.可能过滤离群点
	* 基于网格的方法	1.使用一种多分辨率网格数据结构 2.快速处理

##参考资料

1. [wiki](https://zh.wikipedia.org/wiki/K-%E5%B9%B3%E5%9D%87%E7%AE%97%E6%B3%95)
2. [K-Means 算法](http://coolshell.cn/articles/7779.html/comment-page-1#comments)
3. [KMeans聚类算法思想与可视化](http://2hwp.com/2015/08/20/KMeans/)
4. [K-means clustering is not a free lunch](http://varianceexplained.org/r/kmeans-free-lunch/)
5. [基本Kmeans算法介绍及其实现(c++)](http://blog.csdn.net/qll125596718/article/details/8243404)
6. [清雨的 Data Science 笔记](https://zhuanlan.zhihu.com/p/20432322?refer=TsingJyuData)
7. [Zhao W, Ma H, He Q. Parallel k-means clustering based on mapreduce\[M\] Cloud Computing. Springer Berlin Heidelberg, 2009: 674-679.](http://www.cs.ucsb.edu/~veronika/MAE/parallelkmeansmapreduce_zhao.pdf)
