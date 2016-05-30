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

    	int circle = ((M>N?N:M)+1)/2;
    	for (int i = 0; i < circle; ++i)
    	{
    		for (int j = i; j < N-i; ++j)
    		{
    			result.push_back(matrix[i][j]);
    		}

    		for (int j = i+1; j < M-1-i; ++j)
    		{
    			result.push_back(matrix[j][N-1-i]);
    		}

    		if (M-1-i!=i)
    		{
	    		for (int j = N-1-i; j >= i ; --j)
	    		{
	    			result.push_back(matrix[M-1-i][j]);
	    		}
    		}
    		if (N-1-i!=i)
    		{
    			for (int j = M-1-i-1; j > i ; --j)
	    		{
	    			result.push_back(matrix[j][i]);
	    		}
    		}

    	}
    	return result;
    }
};