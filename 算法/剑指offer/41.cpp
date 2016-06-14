// class Solution {
// public:
//     vector<int> FindNumbersWithSum(vector<int> array,int sum) {
//     	int s = 0,e = array.size()-1;
//     	vector<int> result;

//         while(s<e)
//         {
//         	int cur_sum = array[s]+array[e];
//         	if (cur_sum==sum)
//         	{
//                 result.push_back(array[s]);
//                 result.push_back(array[e]);
//         		break;

//         	}else if (cur_sum>sum)
//         	{
//         		e--;
//         	}else if (cur_sum<sum)
//         	{
//         		s++;
//         	}
//         }
//         // result.push_back(result_s);
//         // result.push_back(result_e);

//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int s = 1,e = 2;
        int sum_temp = s+e;
        vector<vector<int> > result;
        int n = 0;
        while(s<sum/2+1)
        {
        	if (sum_temp==sum)
        	{
        		result.push_back(vector<int>());
        		for (int i = s; i <= e; ++i)
        		{
        			result[n].push_back(i);
        		}
        		n++;
                sum_temp-=s;
        		s++;
        	}else if(sum_temp<sum){
        		e++;
        		sum_temp+=e;
        	}else{
                sum_temp-=s;
        		s++;
        	}
        }
        return result;
    }
};