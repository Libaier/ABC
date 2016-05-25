// 198. House Robber My Submissions QuestionEditorial Solution
// Total Accepted: 63970 Total Submissions: 188013 Difficulty: Easy
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Credits:
// Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

// Subscribe to see which companies asked this question
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
    	vector<int> maxSum;
    	maxSum.push_back(0);
    	maxSum.push_back(nums[0]);

    	for(int i = 1;i<nums.size();i++)
    	{

	        if(nums[i]+maxSum[i-1]>maxSum[i])
	        {
	            maxSum.push_back(nums[i]+maxSum[i-1]);
	        }else{
	            maxSum.push_back(maxSum[i]);
	        }
    	}
    	return maxSum[nums.size()];
    }
};