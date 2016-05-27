class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
        {
            return 0;
        }

        int l = 0,r = rotateArray.size()-1;
        if (l == r)
        {
            return rotateArray[0];
        }
        

        while(l<r)
        {
            int m = (l+r)/2;
            if (rotateArray[r]>rotateArray[m])
            {
                r = m;
            }else if (rotateArray[r]<rotateArray[m])
            {
                l = m+1;
            }else{//rotateArray[r]==rotateArray[m]
                if(rotateArray[l]==rotateArray[m])
                {
                    l++;
                    r--;
                }else{
                    r = m;
                }
            }
        }
        
        return rotateArray[r];
    }
};