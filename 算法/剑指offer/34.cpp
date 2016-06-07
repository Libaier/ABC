class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if (index<=0)
    	{
    		return 0;
    	}
    	int* ugly_num = new int[index];
    	ugly_num[0] = 1;
    	int next_ugly_num_cnt = 1;
    	int p2 =0, p3 = 0,p5 = 0;
    	int min_temp = 1;
    	while(next_ugly_num_cnt<index)
    	{
    		min_temp = min(min(ugly_num[p2]*2,ugly_num[p3]*3),ugly_num[p5]*5);
    		ugly_num[next_ugly_num_cnt] = min_temp;
    		while(ugly_num[p2]*2<=min_temp)
    		{
    			p2++;
    		}
    		while(ugly_num[p3]*3<=min_temp)
    		{
    			p3++;
    		}
    		while(ugly_num[p5]*5<=min_temp)
    		{
    			p5++;
    		}
    		next_ugly_num_cnt++;
    	}
    	delete(ugly_num);
    	return min_temp;
    }
};