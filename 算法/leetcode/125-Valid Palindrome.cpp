// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring
// cases.
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
// Note: Have you consider that the string might be empty? This is a good question to ask during an
// interview.
// For the purpose of this problem, we define empty string as valid palindrome.
class Solution {
//OPŒ Ã‚
public:
    bool isPalindrome(string s) {
    	if (s.empty())
    	{
    		/* code */
    		return true;
    	}
    	for (int i = 0; i < s.size(); ++i)
    	{
    		/* code */
    		// if (!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')))
    		if(!isalnum(s[i]))
    		{
    			/* code */
    			s.erase(s.begin()+i);
    			//"......a"
    			i--;
    		}else if(s[i]>='A'&&s[i]<='Z'){
    		    s[i] = s[i]+'a'-'A';
    		}
    	}
    	int size = s.size();
    	
        for (int i = 0; i < size/2; ++i)
        {
        	/* code */
        // 	if (s[i]!=s[size-i-1]&&s[i]!=(s[size-i-1])+'A-a')&&s[i]!=(s[size-i-1])+'a-A'))
            if (s[i]!=s[size-i-1])
        	{
        		/* code */
        		return false;
        	}
        }
        return true;
    }
};