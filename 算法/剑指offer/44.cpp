class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
    	if (numbers.size()!=5)
    	{
    		return false;
    	}
        sort(numbers.begin(),numbers.end());
        int count0 = 0;
        for (int i = 0; i < 4; ++i)
        {
        	if (0==numbers[i])
        	{
        		count0++;
        		if (count0==4)
        		{
        			return true;
        		}
        	}else if (numbers[i] == numbers[i+1])
        	{
        		return false;
        	}else{
        		count0 -= (numbers[i+1]-numbers[i]);
        		count0 ++;
        		if (count0<0)
        		{
        			return false;
        		}
        	}
        }
        return true;
    }
};