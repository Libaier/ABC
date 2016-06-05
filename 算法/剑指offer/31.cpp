class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	if(array.empty())
        {
            return -1;
        }

        int result = array[0];
        int current_result = array[0];
        int tag = 1;
        while(tag<array.size())
        {
        	if (current_result > 0)
        	{
        		current_result += array[tag];
        	}else{
        		current_result = array[tag];
        	}
        	if (current_result>result)
        	{
        		result = current_result;
        	}
        }
        return result;
    }
};