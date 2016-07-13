# -*- coding: utf-8 -*-
from numpy import *
N = 10000

# [-1,1] x [-1,1] 
x = random.uniform(-1, 1, N)
y = random.uniform(-1, 1, N)
# print x**2 
# print count_nonzero(x**2 + y**2 <= 1)
# 
print 4.0*count_nonzero(x**2 + y**2 <= 1)/N