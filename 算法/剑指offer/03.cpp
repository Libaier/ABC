class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int N = array.size();
        if(0 == N) return false;
        int M = array[0].size();
        if(0 == M) return false;

        int i = 0,j = M-1;
        while(i<N&&j>=0)
        {
        	if (target == array[i][j])
        	{
        		return true;
        	}
        	
        	if (target > array[i][j])
        	{
        		i++;
        	}else{
        		j--;
        	}
        }
		return false;
    }
};