// Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

// Subscribe to see which companies asked this question

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    	if(s.empty())
    	{
    		return 0;
    	}

    	int result = 0;
    	int result_temp = 0;
    	int start = -1;
    	unordered_map<char, int> stored;
    	int j = 0;

        for (int i = 0; i < s.size(); i++)
        {
        	/* code */
        	if (stored.find(s[i]) != stored.end()&&stored[s[i]]>start)
        	{
        		start = stored[s[i]];
        		result_temp = i - start;
        		stored[s[i]] = i;

        	}else{
    			result_temp++;
    			stored[s[i]] = i;
        	}

    	    /* code */
    		if (result_temp > result)
    		{
    			/* code */
    			result = result_temp;
    		}

        }

        return result;
    }
};