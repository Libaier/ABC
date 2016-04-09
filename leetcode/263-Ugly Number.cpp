// 263. Ugly Number My Submissions QuestionEditorial Solution
// Total Accepted: 51241 Total Submissions: 140610 Difficulty: Easy
// Write a program to check whether a given number is an ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

// Note that 1 is typically treated as an ugly number.

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question

class Solution {
public:
    bool isUgly(int num) {
        if(num<1)
        {
        	return false;
        }
        int temp = num;
        while(temp!=1)
        {
        	if(temp%5==0)
        	{
        		temp = temp/5;
        	}else if(temp%2==0)
        	{
        		temp = temp/2;
        	}else if(temp%3==0)
        	{
        		temp = temp/3;
        	}else{
        		return false;
        	}
        } 
        return true;
    }
};