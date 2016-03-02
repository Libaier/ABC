class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> result;
        result.push_back(0);
        
        if(0==n)
        {
            return result;
        }
        
        int tag = 0;

        for(int i = 0;i < n;i++)
        {
            for(int j = pow(2,i)-1;j>=0;j--)
            {
                int temp = pow(2,i)+result[j];
                result.push_back(temp);
            }
        }
    }
};