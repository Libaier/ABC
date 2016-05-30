class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	vector<int> result;
    	int M = matrix.size();
    	if (M == 0)
    	{
    		return result;
    	}
    	int N = matrix[0].size();
    	for (int i = 0; i < M/2; ++i)
    	{
    		for (int j = i; j < N-i; ++j)
    		{
    			result.push_back(matrix[i][j]);
    		}
    		for (int j = 0; j < M-1-i; ++j)
    		{
    			result.push_back(matrix[N-1-i][j]);
    		}

    		for (int j = N-i; j >i ; --j)
    		{
    			result.push_back(matrix[i][j]);
    		}
    		for (int j = M-1-i; j >i ; --j)
    		{
    			result.push_back(matrix[i][j]);
    		}
    	}
    }
};