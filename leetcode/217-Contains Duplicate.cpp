// 217. Contains Duplicate My Submissions QuestionEditorial Solution
// Total Accepted: 82088 Total Submissions: 200400 Difficulty: Easy
// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

// Subscribe to see which companies asked this question

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i = 0;i<nums.size();i++)
        {
            if(!(s.insert(nums[i]).second))
            {
                return true;
            }
        }
        return false;
    }
};