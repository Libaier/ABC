// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

// Subscribe to see which companies asked this question

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.empty())
        {
        	/* code */
        	return 0;
        }
        
        int size = nums.size();
        int result = 1;
        int temp = nums[0];
        
        for (int i = 1; i < size; ++i)
        {
        	/* code */
        	if(nums[i] != temp)
        	{
        	    nums[result] = nums[i]; 
        		result++;
        		temp = nums[i];
        	}

        }
        
        return result;
    }
};