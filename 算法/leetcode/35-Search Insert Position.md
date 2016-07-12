###题目
// 35. Search Insert Position My Submissions QuestionEditorial Solution
// Total Accepted: 99897 Total Submissions: 269314 Difficulty: Medium
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

###解法

	class Solution {
	public:
	    int searchInsert(vector<int>& nums, int target) {
	    	if (nums.empty()) return 0;
	
	        int left = 0, right = nums.size()-1;
	        
	        while(left <= right)
	        {
	        	int middle = (left + right)/2;
	
	        	if (nums[middle] == target) {
	        		return middle;
	        	} else if (nums[middle] > target) {
	        		right = middle - 1;
	        	} else {
					left = middle + 1;
	        	}
	        }
	        return left;
	    }
	
	    int searchInsert1(vector<int>& nums, int target) {
	    	if (nums.empty()) return 0;
	
	        int left = 0, right = nums.size()-1;
	
	        while(left <= right)
	        {
	        	if (nums[left] >= target) return left;
	        	if (nums[right] < target) return right + 1;
	        	if (nums[right] == target) return right;
	
	        	int middle = (left + right)/2;
	
	        	if (nums[middle] == target) {
	        		return middle;
	        	} else if (nums[middle] > target) {
	        		right = middle - 1;
	        	} else {
					left = middle + 1;
	        	}
	        }
	        
	        return 0;
	    }
	};