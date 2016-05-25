#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <string>
using namespace std;


typedef struct sample
{
	double feature[101];
	char lable;
};

typedef struct result
{
	double score;
	char lable;
};

bool myfunction(result i, result j) { return (i.score<j.score); }

double calDistance(double feature1[101], double feature2[101],int L)
{
	double sum = 0.0;
	for (int i = 0; i < L; i++)
	{
		sum += pow(feature1[i] - feature2[i],2);
	}

	return sqrt(sum);
}

string getResult(vector<sample> train, double feature[101],int L,int k)
{
	vector<result> myResult;
	//double min = INT_MAX;
	for (int i = 0; i < train.size(); i++)
	{
		result temp;
		temp.score = calDistance(train[i].feature, feature, L);
		temp.lable = train[i].lable;
		myResult.push_back(temp);
	}
	sort(myResult.begin(), myResult.end(),myfunction);
	int count[4] = {0};
	int n = myResult.size();
	for (int i = 0; i < k; i++)
	{
		count[myResult[i].lable - 'A']++;
		cout << myResult[i + 1].score - myResult[i].score << endl;
		if ((i + 2 < n) && (abs(myResult[i + 1].score - myResult[i].score) < 0.00000001))
		{
			k++;
		}
	}
	int max = 0;
	char resultChar[4] = {'\0'};
	for (int i = 0; i < 4; i++)
	{
		if (count[i]>=max)
		{
			max = count[i];
		}
	}
	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		if (count[i] == max)
		{
			resultChar[j] = 'A' + i;
			j++;
		}
	}

	return resultChar;
}

int main()
{

	int k = 0,L = 0,M = 0,N = 0;
	while (~scanf("%d%d%d%d",&k,&L,&M,&N))
	{
		vector<sample> train;
		//train.resize(M);
		for (int  i = 0; i < M; i++)
		{
			sample data;
			for (int j = 0; j < L; j++)
			{
				scanf("%lf", &data.feature[j]);
			}
			scanf("%s", &data.lable);
			train.push_back(data);
		}

		for (int i = 0; i < N; i++)
		{
			double feature[101];
			for (int j = 0; j < L; j++)
			{
				scanf("%lf", &feature[j]);
			}
			cout << getResult(train, feature, L, k) << endl;
		}

	}
	return 0;
}

