//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
	int minDepth(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}

		queue<TreeNode*> temp;
		temp.push(root);
		int result = 1;
		while (!temp.empty())
		{
			int n = temp.size();
			for (int i = 0; i < n; i++)
			{
				if (temp.front()->left != NULL)
				{
					temp.push(temp.front()->left);
				}
				if (temp.front()->right != NULL){
					temp.push(temp.front()->right);
				}
				if (temp.front()->right == NULL&&temp.front()->left == NULL){
					return result;
				}
				temp.pop();
			}
			result++;
		}
	}
};s