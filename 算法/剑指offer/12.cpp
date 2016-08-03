class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
        {
            return ;
        }
        vector<int> odd,even;
 
        for (int i = 0; i < array.size(); ++i)
        {
            if (array[i]&0x1==1)
            {
                odd.push_back(array[i]);
            }else{
                even.push_back(array[i]);
            }
        }
        int i = 0;
        for (; i < odd.size(); ++i)
        {
            array[i] = odd[i];
        }
 
        for (int j = 0; j < even.size(); ++j,++i)
        {
            array[i] = even[j];
        }
    }
};