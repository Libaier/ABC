class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
        {
            return 0;
        }
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j < n)
        {
            if(val != nums[j])
            {

                nums[i]=nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};