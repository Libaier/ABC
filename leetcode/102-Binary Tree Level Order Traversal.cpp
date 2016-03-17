//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//3
/// \
//9  20
/// \
//15   7
//return its level order traversal as :
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]
//confused what "{1,#,2,3}" means ? > read more on how binary tree is serialized on OJ.

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
	vector<vector<int>> levelOrder(TreeNode* root) {
		
		vector<vector<int>> result;
		if (root == NULL)
		{
			return result;
		}
		queue<TreeNode*> myqueue;
		myqueue.push(root);
		while (!myqueue.empty())
		{
			vector<int > result_temp;
			int n = myqueue.size();
			for (int i = 0; i < n; i++)
			{
				if (myqueue.front()->left != NULL)
				{
					myqueue.push(myqueue.front()->left);
				}
				if (myqueue.front()->right != NULL)
				{
					myqueue.push(myqueue.front()->right);
				}
				result_temp.push_back(myqueue.front()->val);
				myqueue.pop();
			}
			result.push_back(result_temp);
		}
		return result;
	}
};