class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> intHash;  
        vector<int> result;
        int n = nums.size();
        
        for(int i = 0;i<n;i++)
        {
            
            intHash[nums[i]] = i;
        }
        
        for(int i = 0;i<n;i++)
        {
            std::unordered_map<int,int>::const_iterator got = intHash.find(target-nums[i]);
            if(intHash.end()!=got)
            {
                if(i==got->second)
                {
                    continue;
                }
                result.push_back(i);
                result.push_back(got->second);
                return result;
            }
        }
        
        // int n = nums.size();
        // vector<int> result;
        // for(int i = 0;i < n;i ++)
        // {
        //     for(int j = i+1;j<n;j++)
        //     {
        //         if(nums[i]+nums[j]==target)
        //         {
        //             result.push_back(i);
        //             result.push_back(j);
        //             return result;
        //         }
        //     }
        // }
    }
};