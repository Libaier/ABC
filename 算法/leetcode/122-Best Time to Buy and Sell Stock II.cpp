// 122. Best Time to Buy and Sell Stock II My Submissions QuestionEditorial Solution
// Total Accepted: 82581 Total Submissions: 196621 Difficulty: Medium
// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Subscribe to see which companies asked this question

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
        	/* code */
        	return 0;
        }
        int result = 0;
        int  end = 1;
        while(end<prices.size())
        {
        	int profitToday =  prices[end] - prices[end-1];
        	if(profitToday>0)
        	{
        		result+=profitToday;
        	}
        	end++;
        }
        return result;
    }
};