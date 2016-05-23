// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         if(nums.size()<3)
//         {
//             return result;
//         }
//         sort(nums.begin(), nums.end());
//         int begin = 0;
//         int end = nums.size()-1;
        
//         while((nums[begin] <= 0 || nums[end] >= 0)&&(end-begin)>1)
//         {
//             int sum = nums[begin]+nums[end];
//             if(sum>0)
//             {
//                 int i = 0;
//                 for(i = begin+1;nums[i]<0;i++)
//                 {
//                     if(0==sum+nums[i])
//                     {
//                         vector<int> result_temp(3);
//                         result_temp[0] = nums[begin];
//                         result_temp[1] = nums[i];
//                         result_temp[2] = nums[end];
//                         if(result.size()==0||!(result[result.size()-1]==result_temp))
//                         {
//                              result.push_back(result_temp);
//                         }
//                     }
//                 }
//                 if(sum+nums[i]<0)
//                 {
//                     end--;
//                 }else{
//                     begin++;
//                 }
//             }else{
//                 int i = 0;
//                 for(i = end-1;nums[i]>=0;i--)
//                 {
//                     if(0==sum+nums[i])
//                     {
//                         vector<int> result_temp(3);
//                         result_temp[0] = nums[begin];
//                         result_temp[1] = nums[i];
//                         result_temp[2] = nums[end];
//                         if(result.size()==0||!(result[result.size()-1]==result_temp))
//                         {
//                              result.push_back(result_temp);
//                         }
//                     }
//                 }
//                 if(sum+nums[i]>0)
//                 {
//                     end--;
//                 }else{
//                     begin++;
//                 }
//             }
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
       
       
        int comp_temp = nums[0];
        for(int i = 0;nums[i]<=0;i++)
        {
            if(i==0||nums[i]!=comp_temp)
            {
                comp_temp = nums[i];
                int begin = i+1;
                int end = nums.size()-1;
                while(begin<end&&end>=0&&(nums[i]+nums[begin])<=0)
                {
                    int sum = nums[i]+nums[begin]+nums[end];
                    if(0==sum)
                    {
                        vector<int> result_temp(3);
                        result_temp[0] = nums[i];
                        result_temp[1] = nums[begin];
                        result_temp[2] = nums[end];
                        if(result.size()==0||!(result[result.size()-1]==result_temp))
                        {
                             result.push_back(result_temp);
                        }
                        end--;
                    }else if(sum>0){
                        end--;
                    }else{
                        begin++;
                    }
                }
            }
        }
                
        return result;

        
        // while((nums[begin] <= 0 || nums[end] >= 0)&&(end-begin)>1)
        // {
        //     int sum = nums[begin]+nums[end];
        //     if(sum>0)
        //     {
        //         int i = 0;
        //         for(i = begin+1;nums[i]<0;i++)
        //         {
        //             if(0==sum+nums[i])
        //             {
        //                 vector<int> result_temp(3);
        //                 result_temp[0] = nums[begin];
        //                 result_temp[1] = nums[i];
        //                 result_temp[2] = nums[end];
        //                 if(result.size()==0||!(result[result.size()-1]==result_temp))
        //                 {
        //                      result.push_back(result_temp);
        //                 }
        //             }
        //         }
        //         if(sum+nums[i]<0)
        //         {
        //             end--;
        //         }else{
        //             begin++;
        //         }
        //     }else{
        //         int i = 0;
        //         for(i = end-1;nums[i]>=0;i--)
        //         {
        //             if(0==sum+nums[i])
        //             {
        //                 vector<int> result_temp(3);
        //                 result_temp[0] = nums[begin];
        //                 result_temp[1] = nums[i];
        //                 result_temp[2] = nums[end];
        //                 if(result.size()==0||!(result[result.size()-1]==result_temp))
        //                 {
        //                      result.push_back(result_temp);
        //                 }
        //             }
        //         }
        //         if(sum+nums[i]>0)
        //         {
        //             end--;
        //         }else{
        //             begin++;
        //         }
        //     }
        // }

    }
};