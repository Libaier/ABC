// 95. Unique Binary Search Trees II My Submissions QuestionEditorial Solution
// Total Accepted: 52742 Total Submissions: 182236 Difficulty: Medium
// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<TreeNode*> generateResult(int start,int end)
	{
		vector<TreeNode*> result_all;
		if (start>end)
		{
			/* code */
			result_all.push_back(nullptr);
			return result_all;
		}
		
		for (int i = start; i <= end; ++i)
		{
			/* code */
			
			//result->val = i;
			vector<TreeNode*> leftTree = generateResult(start,i-1);
			vector<TreeNode*> rightTree = generateResult(i+1,end);
			for (int m = 0; m < leftTree.size(); ++m)
			{
				for (int n = 0; n < rightTree.size(); ++n)
				{
				    TreeNode* result = new TreeNode(i);
					/* code */
					result->left = leftTree[m];
				// 	if(leftTree[m]!=NULL)
				// 	{
				// 	    result->left->val = start+m;
				// 	}
					result->right = rightTree[n];
				// 	if(rightTree[n]!=NULL)
				// 	{
				// 	    result->right->val = i+1+n;
				// 	}
					result_all.push_back(result);
				}
			}
			
		}

		return result_all;
	}
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n==0) return result;
    	return generateResult(1,n);
    }
};