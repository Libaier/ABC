// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//     For example, given array S = {-1 2 1 -4}, and target = 1.

//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min = INT_MAX;
        int result = nums[0]+nums[1]+nums[2];
        // for(int i = 0;nums[i]<=target;i++)
        for(int i = 0;i<nums.size()-2;i++)
        {
            int begin = i+1;
            int end = nums.size()-1;
            while(begin<end)
            {
                int sum = nums[i]+nums[begin]+nums[end];
                if(sum == target)
                {
                    return target;
                }else if(sum > target)
                {
                    if(sum-target<min)
                    {
                        min = sum-target;
                        result = sum;
                    }
                    end--;
                }else{
                    if(target-sum<min)
                    {
                        min = target-sum;
                        result = sum;
                    }
                    begin++;
                }
            }
        }
        return result;

    }
};