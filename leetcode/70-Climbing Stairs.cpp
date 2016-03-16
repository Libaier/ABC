class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0)
		{
			return 0;
		}

		int m = n / 2;//最多的2的个数
		int sum = 1;//全是1
		for (int i = 1; i <= m; i++)
		{
			int temp = (n - i);
			long long sumtemp = temp;//共有几步
			int j = 2;
			while (j <= i)
			{
				temp--;
				sumtemp = sumtemp*temp / j;
				j++;
			}
			sum = sum + sumtemp;
		}
		return sum;
	}
};

//701408733
//2147483648～2147483647 
//446607130
//1134903170