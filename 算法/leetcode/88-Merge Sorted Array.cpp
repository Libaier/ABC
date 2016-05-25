class Solution {
public:
//456,000
// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     int i = 0, j = 0;
//     //i代表nums1插入后游标位置
//     //j代表nums2检测游标
//     vector<int>::iterator it;
//     //it = nums1.begin(); 放在这里会报错，it地址改变
//     while(j < n)
//     {
//         it = nums1.begin();
//         if(i > m + j - 1)
//         {
//             nums1.insert(it+i,nums2[j]);
//     		j++;
//     		//i++;
//         }
//         else if (nums2[j]<nums1[i])
//     	{
//     		/* code */
//     		nums1.insert(it+i,nums2[j]);
//     		j++;
//     		i++;
//     	}
//     	i++;
//     }
//     nums1.resize(m+n);
// }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n -1;
        while(i>=0&&j>=0)
        {
            nums1[k--]=nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
        }
        
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
    }
};