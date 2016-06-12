// 题目2 : 区域周长
// 时间限制:10000ms
// 单点时限:1000ms
// 内存限制:256MB
// 描述
// 给定一个包含 N × M 个单位正方形的矩阵，矩阵中每个正方形上都写有一个数字。

// 对于两个单位正方形 a 和 b ，如果 a 和 b 有一条共同的边，并且它们的数字相等，那么 a 和 b 是相连的。

// 相连还具有传递性，如果 a 和 b 相连，b 和 c 相连，那么 a 和 c 也相连。

// 给定一个单位正方形 s，s 和与 s 相连的所有单位正方形会组成一个区域 R 。小Hi想知道 R 的周长是多少？

// 输入
// 第一行包含4个整数 N , M ，x 和 y ， N 和 M 是矩阵的大小， x 和 y 是给定的单位正方形 s 的坐标。(1 ≤ N , M ≤ 100, 0 ≤ x < N , 0 ≤ y < M )

// 以下是一个 N × M 的矩阵 A，Aij 表示相应的正方形上的数字。(0 ≤ Aij ≤ 100)

// 输出
// 输出一个整数表示 R 的周长。

// 样例输入
// 6 5 2 1
// 0 0 1 2 2
// 3 1 1 3 7
// 4 3 1 3 7
// 4 3 0 3 2
// 4 3 3 0 1
// 4 5 5 5 5
// 样例输出
// 10
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
class CNode
{
public:
	int x, y, val;
	CNode(int x_, int y_, int val_){
		x = x_;
		y = y_;
		val = val_;
	}
};

vector<CNode> getUnvistedNeighbours(CNode cur_CNode, const vector<vector<CNode>> &data, const set<pair<int,int>> &visited)
{
	int x = cur_CNode.x;
	int y = cur_CNode.y;
	int val = cur_CNode.val;

	vector<CNode> result;

	if (x - 1 >= 0 && data[x - 1][y].val == val&&visited.find(make_pair(x-1, y)) == visited.end())
	{
		result.push_back(data[x - 1][y]);
	}
	if (y - 1 >= 0 && data[x][y - 1].val == val&&visited.find(make_pair(x, y-1)) == visited.end())
	{
		result.push_back(data[x][y - 1]);
	}
	if ((x + 1) < data.size() && data[x + 1][y].val == val&&visited.find(make_pair(x+1, y)) == visited.end())
	{
		result.push_back(data[x + 1][y]);
	}
	if ((y + 1) < data[0].size() && data[x][y + 1].val == val&&visited.find(make_pair(x, y+1)) == visited.end())
	{
		result.push_back(data[x][y + 1]);
	}
	return result;
}

int getPerimeter(const set<pair<int, int>> &visited)
{
	int result = 0;
	for (std::set<pair<int, int>>::iterator it = visited.begin(); it != visited.end(); ++it)
	{
		int x = it->first;
		int y = it->second;
		if (visited.find(make_pair(x, y + 1)) == visited.end())
		{
			result++;
		}
		if (visited.find(make_pair(x, y - 1)) == visited.end())
		{
			result++;
		}
		if (visited.find(make_pair(x+1, y)) == visited.end())
		{
			result++;
		}
		if (visited.find(make_pair(x-1, y)) == visited.end())
		{
			result++;
		}
	}
	return result;
}

int main32()
{
	int N = 0, M = 0, x = 0, y = 0;
	cin >> N >> M >> x >> y;
	vector<vector<CNode>> data;
	for (int i = 0; i < N; i++)
	{
		data.push_back(vector<CNode>());
		for (int j = 0; j < M; j++)
		{
			int k = 0;
			cin >> k;
			data[i].push_back(CNode(i,j,k));
		}
	}
	queue<CNode> visiting;
	set<pair<int,int>> visited;
	visiting.push(data[x][y]);
	//set<CNode>::iterator it = visited.begin();
	while (!visiting.empty())
	{
		visited.insert(make_pair(visiting.front().x, visiting.front().y));

		vector<CNode> temp = getUnvistedNeighbours(visiting.front(),data,visited);
		//cout << visiting.front().x << "," << visiting.front().y << endl;
		visiting.pop();
		for (int i = 0; i < temp.size(); i++)
		{
			visiting.push(temp[i]);
		}
	}

	cout << getPerimeter(visited) << endl;

	return 0;
}