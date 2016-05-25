class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        int n = result.size();
        
        if(n==0)
        {
            return result;
        }
        result[n-1] = result[n-1]+1;
        
        for(int i = n-1; i >= 0; i --)
        {
            if(result[i]>9)
            {
                if(i==0)
                {
                    result[i] = result[i]  - 10;
                    result.insert(result.begin(),1);
                    break;
                }else{
                    result[i-1] = result[i-1] + 1;
                    result[i] = result[i]  - 10;
                }
          
            }else{
                break;
            }
        }
        
        return result;
    }
};