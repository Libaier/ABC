class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.empty())
    	{
    		return 0;
    	}
    	int count = 1;
    	int result  = 0;
    	int tag = 1;
    	while(tag<numbers.size())
    	{
    		if (numbers[tag]==numbers[result])
    		{
    			count++;
    		}else{
    			count--;
    		}
    		tag++;
    		if (count==0)
    		{
    			result = tag;
    		}
    	}
    	count = 0;
    	for (int i = 0;i<numbers.size();i++)
    	{
    		if (numbers[result]==numbers[i])
    		{
    			count++;
    		}
    	}
    	if (count<=numbers.size()/2)
    	{
    		return 0;
    	}
    	return numbers[result];
    }
};