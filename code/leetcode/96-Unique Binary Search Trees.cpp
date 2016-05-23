// 96. Unique Binary Search Trees My Submissions QuestionEditorial Solution
// Total Accepted: 79323 Total Submissions: 213216 Difficulty: Medium
// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
        	/* code */
        	for (int j = 1; j <= i; ++j)
        	{
        		/* code */
        		//f(n) = f(k-1)f(n-k) k=1~n
        		//f(n) = f(0)*f(n-1)+...+
        		dp[i] += dp[j-1]*dp[i-j];
        	}
        }

        dp[0] = 0;
        return dp[n];
    }
};