// 326. Power of Three My Submissions QuestionEditorial Solution
// Total Accepted: 33639 Total Submissions: 93323 Difficulty: Easy
// Given an integer, write a function to determine if it is a power of three.

// Follow up:
// Could you do it without using any loop / recursion?

// Credits:
// Special thanks to @dietpepsi for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);  
    }
};