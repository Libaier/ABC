//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
	int maxDepth(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int n = maxDepth(root->left);
		int m = maxDepth(root->right);
		return (n > m ? n : m) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
		{
			return true;
		}

		int n = maxDepth(root->left);
		int m = maxDepth(root->right);
		if (abs(n - m) > 1)
		{
			return false;
		}
		else{
			return isBalanced(root->left) && isBalanced(root->right);
		}
	}
};