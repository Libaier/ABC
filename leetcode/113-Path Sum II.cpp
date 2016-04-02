// 113. Path Sum II My Submissions QuestionEditorial Solution
// Total Accepted: 76972 Total Submissions: 274228 Difficulty: Medium
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> result;
    	if (root==NULL)
    	{
    		/* code */
    		return result;
    	}
        stack<TreeNode*> treeNodeTemp;
        treeNodeTemp.push(root);
        int sumTemp = 0;
        while(!treeNodeTemp.empty())
        {
        	if(treeNodeTemp.top()->left==NULL&&treeNodeTemp.top()->right==NULL)
        	{
        		if(sum==sumTemp)
        		{
        			stack<TreeNode*> treeNodeTempTemp = treeNodeTemp;
        			vector<int> resultTemp;
        			while(!treeNodeTempTemp.empty())
        			{
						resultTemp.push_back(treeNodeTempTemp.top());
						treeNodeTempTemp.pop();
        			}
        		}
        		treeNodeTemp.top().val = INT_MAX;
        		treeNodeTemp.pop();
        	}
        	if(treeNodeTemp.top()->left!=NULL&&treeNodeTemp.top()->left->val!=INT_MAX)
        	{
        		treeNodeTemp.push(treeNodeTemp.top()->left);
        	}else if(treeNodeTemp.top()->right!=NULL&&treeNodeTemp.top()->right->val!=INT_MAX){
        		treeNodeTemp.push(treeNodeTemp.top()->right);
        	}
        }
        return result;
    }
};