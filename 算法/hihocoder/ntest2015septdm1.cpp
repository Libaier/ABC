//http://hihocoder.com/contest/ntest2015septdm/problem/1
//无法提交，简单的用例通过了，未考虑实体中含有{}的情况
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
using namespace std;

int main()
{

	string str;
	while (cin >> str)
	{
		string entity;
		cin >> entity;
		int size = entity.size();
		int tag = 0;
		int result[100] = { 0 };
		int hasResult = 0;
		while (tag <= str.size())
		{
			int r = str.find(entity, tag);
			if (-1==r)
			{
				break;
			}
			tag = r+size;
			int resultTemp = 1;
			for (int i = 0; i < tag; i++)
			{
				if (str[i] == '{')
				{
					resultTemp++;
				}
				if (str[i] == '}')
				{
					resultTemp--;
				}
			}
			result[resultTemp] = 1;
			hasResult = 1;
		}
		if (!hasResult)
		{
			printf("%-1\n");
		}
		else
		{
			for (int i = 1; i < 100; i++)
			{
				if (!hasResult&&result[i])
				{
					printf(",%d", i);
				}
				if (hasResult&&result[i])
				{
					printf("%d", i);
					hasResult = 0;
				}

			}
			printf("\n");
		}

	}
	return 0;
}
