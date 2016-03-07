// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        // int result = 0;
        int max = -1;
        // for(int i=0;i<height.size();i++)
        // {
        //     if(height[i]>max)
        //     {
        //         max = height[i];
        //         int max_temp = 0;
        //         for(int j = height.size()-1;j>i;j--)
        //         {
        //             if(height[j]>max_temp)
        //             {
        //                 max_temp = height[j];
        //                 int result_temp = (j-i)*min(height[i],height[j]);
        //                 if(result_temp>result)
        //                 {
        //                     result = result_temp;
        //                 }
        //             }else{
        //                 continue;
        //             }
        //         }
        //     }else{
        //         continue;
        //     }
        // }
        int start = 0;
        int end = height.size()-1;
        while(start<end)
        {
            int area = min(height[start],height[end])*(end-start);
            if(area>max)
            {
                max = area;
            }
            if(height[start]>height[end])
            {
                end--;
            }else{
                start++;
            }
        }
        return max;
    }
};