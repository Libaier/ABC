// 题目1 : 非法二进制数
// 时间限制:10000ms
// 单点时限:1000ms
// 内存限制:256MB
// 描述
// 如果一个二进制数包含连续的两个1，我们就称这个二进制数是非法的。

// 小Hi想知道在所有 n 位二进制数（一共有2n个）中，非法二进制数有多少个。

// 例如对于 n = 3,有 011, 110, 111 三个非法二进制数。

// 由于结果可能很大，你只需要输出模109+7的余数。

// 输入
// 一个整数 n (1 ≤ n ≤ 100)。

// 输出
// n 位非法二进制数的数目模109+7的余数。

// 样例输入
// 3
// 样例输出
// 3
#include <iostream>
using namespace std;
int main31()
{
	int n = 0;
	int mod = 1e9 + 7;
	//int mod = 107;
	//while (cin >> n){
	/*for (size_t i = 1; i <= 100; i++)
	{
	n = i;*/
	cin >> n;

	long long result[101] = {0};
	result[1] = 0;
	result[2] = 1;
	long long two = 2;
	for (int i = 3; i <= n; ++i)
	{
		result[i] = result[i - 1];
		result[i] += result[i - 2];
		result[i] %= mod;
		result[i] += two;
		result[i] %= mod;
		two *= 2;
		two %= mod;
	}
	cout << result[n] << endl;
	//}

	//}
	return 0;
}