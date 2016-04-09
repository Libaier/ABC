// 202. Happy Number My Submissions QuestionEditorial Solution
// Total Accepted: 63445 Total Submissions: 174815 Difficulty: Easy
// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Example: 19 is a happy number

// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Credits:
// Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question

class Solution {
public:
	int getSum(int temp)
	{
		int sum = 0;
        while(temp!=0)
        {
            sum += (temp%10)*(temp%10);
            temp = temp/10;
        }
        return sum;
	}
    bool isHappy(int n) {
        int slow = n,fast = n;
        while(!(slow==1||fast==1))
        {
        	slow = getSum(slow);
        	fast = getSum(fast);
        	fast = getSum(fast);
        	if(slow==fast&&slow!=1)
        	{
        		return false;
        	}
        }

        return true;

    }

};