// Determine whether an integer is a palindrome. Do this without extra space.

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x<0)
        {
        	return false;
        }

    	int begin = 0;
    	int end = 0;
    	int x_temp = x;
    	int d = 1;
    	int d1 = 1;
    	while(x_temp/10!=0)
    	{
    		x_temp = x_temp/10;
    		d=d*10;
    	}
        while(d>d1)
        {
        	if(x/d%10!=x/d1%10)
        	{
        		return false;
        	}
        	d=d/10;
        	d1=d1*10;
        }
        return true;
    }
};