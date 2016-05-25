class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
        
        
    //     if(nums.size()<3)
    //     {
    //         return nums.size();
    //     }
    //     // [1,1,1,2,2,3]
    //     int length = 2;
    //     for(int i = 2;i<nums.size();i++)
    //     {
    //         if(nums[length-2]!=nums[i])
    //         {
    //             nums[length++] = nums[i];             
    //         }
    //     }
    //     return length;
    // }
    
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int count = 1;
        int index = 0;
        for(int i = 1;i< nums.size();i++)
        {
            if(nums[index]==nums[i])
            {
                count++; 
                if(count<3)
                {
                    nums[index+1]=nums[i];
                    index++;
                }
            }else{
                count = 1;
                nums[index+1]=nums[i];
                index++;
            }
        }
        return index+1;
    }
    
};