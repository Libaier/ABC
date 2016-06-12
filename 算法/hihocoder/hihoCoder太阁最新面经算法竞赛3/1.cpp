#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	int mod = 1000000007;
	//int mod = 7;
	cin >> n;
	//for (size_t i = 1; i <= 100; i++)
	//{
	//	n = i;
	long long result = 0;
	long long two = 1;
	for (int i = 1; i < n; ++i)
	{
		//result = result%mod;
		result = result + two;
		result = result%mod;
		two = two * 2;
		two = two%mod;
	}
	//cout << result << endl;
	//}

	return 0;
}