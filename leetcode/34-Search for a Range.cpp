// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int middle = high/2;
        std::vector<int> result(2);
        result[0] = -1;
        result[1] = -1;
        
        while(low != high)
        {
        	if(nums[low] <= target && nums[middle] >= target)
        	{
        		high = middle;
        		middle = (high+low)/2;
        		continue;
        	}
        	else if(nums[high] >= target && nums[middle] < target)
        	{
        		low = middle+1;
        		middle = (high+low)/2;
        		continue;
        	}
        	else
        	{
        		return result;
        	}
        }
        
        if(nums[middle]!=target)
        {
            return result;
        }

        result[0] = middle;
		result[1] = middle;
		
		while(middle!=(nums.size()-1)&&nums[middle+1]==target)
		{
		    middle++;
		}
		result[1] = middle;
		
// 		low = 0;
//         high = nums.size()-1;
//         middle = high/2;

//         while(low != high)
//         {
//         	if(nums[high] >= target && nums[middle] <= target)
//         	{
//         		low = middle;
//         		middle = (high-low)/2;
//         		continue;
//         	}
//         	else if(nums[low] <= target && nums[middle] >= target)
//         	{
//         		high = middle;
//         		middle = (high-low)/2;
//         		continue;
//         	}
//         }
//         result[1] = middle;

        
        return result;
    }
};

