// Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

class Solution {
public:
    string longestPalindrome(string s) {
        int max_size = 0;
        int max_size_temp = 0;
    
        string rs = s;
        reverse(rs.begin(),rs.end());
        
        if(rs==s)
        {
            return rs;
        }
        
        string result;
        string result_temp;
        
        int n = s.size()-1;
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0;j<=i;j++)
            {
                if(s[j]==rs[n-i+j])
                {
                    result_temp.append(1,s[j]);
                    max_size_temp++;
                    
                    if(max_size_temp>max_size)
                    {
                        max_size = max_size_temp;
                        result = result_temp;
                    }
                }else{
                    max_size_temp = 0;
                    result_temp.clear();
                }
            }
            max_size_temp = 0;
            result_temp.clear();
        }

        for(int i = max_size;i<=n;i++)
        {
            for(int j = 0;j<=i;j++)
            {
                if(rs[j]==s[n-i+j])
                {
                    result_temp.append(1,rs[j]);
                    max_size_temp++;
                    
                    if(max_size_temp>max_size)
                    {
                        max_size = max_size_temp;
                        result = result_temp;
                    }
                }else{
                    max_size_temp = 0;
                    result_temp.clear();
                }
            }
            max_size_temp = 0;
            result_temp.clear();
        }

        return result;
    }
};


