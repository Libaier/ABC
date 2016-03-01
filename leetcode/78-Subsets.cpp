// Given a set of distinct integers, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	sort(nums.begin(), nums.end()); 
    	vector<vector<int>> result;
    	int n = nums.size();
		vector<int> temp;

    	for (int i = 0; i < (1<<n); i++)
    	{
    		for (int j = 0; j <n ; j++)
    		{
    			/* code */
    			if (i&(1<<j))
    			{
    				/* code */
    				temp.push_back(nums[j]);
    			}
    		}
    		result.push_back(temp);
    		temp.clear();
    	}
    	return result;

    }
};