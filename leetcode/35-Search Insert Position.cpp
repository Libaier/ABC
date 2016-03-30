// 35. Search Insert Position My Submissions QuestionEditorial Solution
// Total Accepted: 99897 Total Submissions: 269314 Difficulty: Medium
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(1)
        {
            if(nums[(i+j)/2]==target)
            {
                return (i+j)/2;
            }
            
            if(nums[i]>target)
            {
                if(0==i)
                {
                    return 0;
                }
                return i;
            }
            
            if(nums[j]<target)
            {
                return j+1;
            }

            
            if(nums[(i+j)/2]>target)
            {
                j = (i+j)/2-1;

            }else{
                i = (i+j)/2+1;
            }
            

        }
    }
};