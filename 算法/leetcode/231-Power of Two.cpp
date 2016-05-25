// 231. Power of Two My Submissions QuestionEditorial Solution
// Total Accepted: 66547 Total Submissions: 183974 Difficulty: Easy
// Given an integer, write a function to determine if it is a power of two.

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	int temp = n;
    	while(temp!=1)
    	{
    		if(!(0==temp%2))
    		{
    			return false;
    		}
    		temp = temp/2;
    	}
    	return true;
    }
};

  // if(n<=0) return false;
  //       return !(n&(n-1));