// 322. Coin Change My Submissions QuestionEditorial Solution
// Total Accepted: 16960 Total Submissions: 68731 Difficulty: Medium
// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)

// Example 2:
// coins = [2], amount = 3
// return -1.

// Note:
// You may assume that you have an infinite number of each kind of coin.

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question
//2 5 10 1
//27
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if (0==amount)
    	{
    		return 0;
    	}
        sort(coins.begin(),coins.end());
        if(coins.empty()||coins[0]>amount)
        {
        	return -1;
        }
        //用于存储结果表
        int result[amount+1];
        for (int i = 1; i <= amount; ++i)
        {
        	/* code */
        	result[i] = -1;
        }
        result[0] = 0;
        //从1开始构建结果表
        for(int i = 1;i <= amount; i++)
        {
        	//用于存储最小值(最优解)
        	int result_temp = INT_MAX;
        	//分别遍历最后一步加入coins[j]的解
        	//注意判断j<coins.size()
        	for (int j = 0; j<coins.size()&&coins[j] <= i; j++)
        	{
        		/* code */
        		if(result[i-coins[j]]!=-1&&result[i-coins[j]]<result_temp)
        		{
        			result_temp = result[i-coins[j]];
        			result[i] = result_temp+1;
        		}
        	}
        }

        return result[amount];
    }
};

