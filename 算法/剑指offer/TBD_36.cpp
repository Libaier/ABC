class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.size()<2)
        {
            return 0;
        }
        int length=data.size();
        int count=0;
        for(int i=length-1;i>0;i--){
            if(data[i]<data[i-1]){
                count++;
            }
        }
        //等差数列求和？？
        return (count*count+count)/2;
    }
};