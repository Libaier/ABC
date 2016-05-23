// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

// Subscribe to see which companies asked this question

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (0==n)
        {
        	/* code */
        	return result;
        }
        generateResult(1,0,n,"(",result);
        return result;
    }

    int generateResult(int l,int r,int n,string str,vector<string>& result)
    {
    	if(l+r==2*n)
    	{
    		result.push_back(str);
    		return 0;
    	}
    	if(l<n)
    	{
    		generateResult(l+1,r,n,str+'(',result);
    	}

    	if(r<l)
    	{
    		generateResult(l,r+1,n,str+')',result);
    	}
    }
};