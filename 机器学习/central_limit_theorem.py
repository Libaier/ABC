# 中心极限定理就是一般在同分布的情况下,样本值的和在总体数量趋于无穷时的极限分布近似于正态分布.
# 可以用其他分布生成正态分布
import numpy
import matplotlib.pyplot as plt

if __name__ == '__main__':
	u = 0
	times = 100000
	for time in range(times):
		u += numpy.random.uniform(0.0,1.0,10000)
		# print u
	print len(u)
	u /= times
	print len(u)
	plt.hist(u,80,facecolor='g',alpha=0.75)
	plt.grid(True)
	plt.show()
