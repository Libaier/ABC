class Solution {
public:
//456,000
// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     int i = 0, j = 0;
//     //i����nums1������α�λ��
//     //j����nums2����α�
//     vector<int>::iterator it;
//     //it = nums1.begin(); ��������ᱨ��it��ַ�ı�
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