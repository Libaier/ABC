//Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//3
/// \
//9  20
/// \
//15   7
//return its bottom - up level order traversal as :
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {

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
		reverse(result.begin(), result.end());
		return result;
	}
};