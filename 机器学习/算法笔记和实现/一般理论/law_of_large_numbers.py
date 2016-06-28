#大数定理:通俗的讲，在试验不变的条件下，重复试验多次，随机事件的频率近似于它的概率
#切比雪夫大数定理
#伯努利大数定律//发生频率趋近概率
#辛钦大数定律//均值趋近去期望

import numpy
import matplotlib.pyplot as plt

if __name__ == '__main__':
	u = numpy.random.uniform(0.0,1.0,10000)
	plt.hist(u,80,facecolor='g',alpha=0.75)
	plt.grid(True)
	plt.show()
	print sum(u)/len(u)
