// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
        {
            return 0;
        }
        int start_haystack = 0;
        int start_needle = 0;
        while(start_haystack < haystack.size())
        {
            if(haystack[start_haystack]==needle[start_needle])
            {
                start_needle++;
                if(start_needle==needle.size())
                {
                    return start_haystack-start_needle+1;
                }
            }else{
                start_haystack = start_haystack-start_needle;
                start_needle = 0;
            }
            start_haystack++;
        }
        
        return -1;
    }
};