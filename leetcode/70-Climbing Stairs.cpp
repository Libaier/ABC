class Solution {
public:
	//int climbStairs(int n) {
	//	if (n <= 0)
	//	{
	//		return 0;
	//	}

	//	int m = n / 2;//����2�ĸ���
	//	int sum = 1;//ȫ��1
	//	for (int i = 1; i <= m; i++)
	//	{
	//		int temp = (n - i);
	//		long long sumtemp = temp;//���м���
	//		int j = 2;
	//		while (j <= i)
	//		{
	//			temp--;
	//			sumtemp = sumtemp*temp / j;
	//			j++;
	//		}
	//		sum = sum + sumtemp;
	//	}
	//	return sum;
	//}

	int climbStairs(int n) {
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		if (n == 2)
		{
			return 2;
		}
		int n1 = 1;
		int n2 = 2;
		for (int i = 3; i <= n; i++)
		{
			int temp = n2;
			n2 = n1 + n2;
			n1 = temp;
		}
		return n2;
	}
};

//701408733
//2147483648��2147483647 
//446607130
//1134903170
//12
//111
//21