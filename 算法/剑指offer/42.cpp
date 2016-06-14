class Solution {
public:
    string LeftRotateString(string str, int n) {
        string result = str;
        if (str.empty())
        {
        	return result;
        }
        result += str;
        n = n%str.size();
        return result.sub_str(n,str.size());
    }
};