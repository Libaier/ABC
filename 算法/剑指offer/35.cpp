class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
        {
            return -1;
        }
        unordered_map<int,int> m;
        for (int i = 0; i < str.size(); ++i)
        {
            m[str[i]]++;
        }
        int k = 0;
        for ( ; k < str.size(); ++k)
        {
            if (m[str[k]]==1)
            {
                return k;
            }
        }
        if (k==str.size())
        {
            return -1;
        }
    }
};