// 121. Best Time to Buy and Sell Stock My Submissions QuestionEditorial Solution
// Total Accepted: 92679 Total Submissions: 258661 Difficulty: Medium
// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Subscribe to see which companies asked this question

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int result = 0;
    	int minDay = prices[0];

        for (int i = 1; i < count; ++i)
        {
        	/* code */
        	if(prices[i]-minDay>result)
        	{
        		result = prices[i]-minDay;
        	}
        	if (prices[i]<minDay)
        	{
        		/* code */
        		minDay = prices[i];
        	}
        }
        return result;
    }
};