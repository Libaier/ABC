// 172. Factorial Trailing Zeroes My Submissions QuestionEditorial Solution
// Total Accepted: 55924 Total Submissions: 172015 Difficulty: Easy
// Given an integer n, return the number of trailing zeroes in n!.

// Note: Your solution should be in logarithmic time complexity.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question

int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}