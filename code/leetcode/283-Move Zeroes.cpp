class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            if(nums[i]!=0)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        
        for(int i = j;i<n;i++)
        {
            nums[i] = 0;
        }
    }
};