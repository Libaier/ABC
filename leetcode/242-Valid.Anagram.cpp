class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }else{
            for(int i = 0;i < s.size();i++)
            {
                int tag = t.find_first_of(s[i]);
                if(tag == -1)
                {
                    return false;
                }else{
                    t[tag] = '0';
                }
            }
        }
        return true;
    }
};