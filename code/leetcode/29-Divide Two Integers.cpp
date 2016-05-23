// 29. Divide Two Integers My Submissions QuestionEditorial Solution
// Total Accepted: 63073 Total Submissions: 404916 Difficulty: Medium
// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.

// Subscribe to see which companies asked this question

// 这道题属于数值处理的题目，对于整数处理的问题，在Reverse Integer中我有提到过，比较重要的注意点在于符号和处理越界的问题。对于这道题目，因为不能用乘除法和取余运算，我们只能使用位运算和加减法。比较直接的方法是用被除数一直减去除数，直到为0。这种方法的迭代次数是结果的大小，即比如结果为n，算法复杂度是O(n)。
// 那么有没有办法优化呢？ 这个我们就得使用位运算。我们知道任何一个整数可以表示成以2的幂为底的一组基的线性组合，即num=a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n。基于以上这个公式以及左移一位相当于乘以2，我们先让除数左移直到大于被除数之前得到一个最大的基。然后接下来我们每次尝试减去这个基，如果可以则结果增加加2^k,然后基继续右移迭代，直到基为0为止。因为这个方法的迭代次数是按2的幂直到超过结果，所以时间复杂度为O(logn)。代码如下：
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(0==divisor)
        {
        	return INT_MAX;
        }
        long long result  = 0;
        bool tag = true;
        long long diend_l;
        long long di_l;
        if (dividend<0)
        {
            if(dividend == INT_MIN)
            {
                diend_l = INT_MAX;
                diend_l ++;
            }else{
                diend_l = -dividend;
            }
        
        	tag = !tag;
        }else{
            diend_l = dividend;
        }

        if (divisor<0)
        {
        	if(divisor == INT_MIN)
            {
                di_l = INT_MAX;
                di_l ++;
            }else{
                di_l = -divisor;
            }
        	tag = !tag;
        }else{
            di_l = divisor;
        }
        //
        while(di_l<=diend_l)
        {
        	long long result_temp = 1;
        	long long di_l_temp = di_l<<1;
	        while(di_l_temp<=diend_l)
	        {
	        	result_temp = result_temp<<1;
	        	di_l_temp = di_l_temp<<1;
	        }
	        diend_l = diend_l - (di_l_temp>>1);
	        result = result+result_temp;
        }
        if (tag)
        {
        	/* code */
        	if(result>=INT_MAX)
        	{
        	    return INT_MAX;
        	}
        	return result;
        }else{
        	return -result;
        }

    }
};
