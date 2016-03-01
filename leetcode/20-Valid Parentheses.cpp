// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the
// input string is valid.
// The brackets must close in the correct order, "()" and "()[]" are all valid but "(]" and "([)]" are
// not.

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); ++i)
        {
        	/* code */
        	if(s[i] == '('||s[i] == '{'||s[i] == '[')
        	{
        		stk.push(s[i]);
        	}
        	else if(stk.empty())
        	{
        	    return false;
        	}
        	else
        	{
        		switch (s[i])
        		{
        			case ')':
        				if(stk.top()=='(')
        				{
        					stk.pop();
        				}
        				else
        				{
        					return false;
        				}
        			break;
        			case '}':
        				if(stk.top()=='{')
        				{
        					stk.pop();
        				}
        				else
        				{
        					return false;
        				}
        			break;
        			case ']':
        				if(stk.top()=='[')
        				{
        					stk.pop();
        				}
        				else
        				{
        					return false;
        				}
        			break;
        			default:
        			break;
        		}
        			
        	}
        	
        }
        if(stk.size()==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};