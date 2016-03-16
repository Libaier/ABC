//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//But the following is not :
//1
/// \
//2   2
//\   \
//3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.
//
//confused what "{1,#,2,3}" means ? > read more on how binary tree is serialized on OJ.
//OJ's Binary Tree Serialization:
//The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
//
//Here's an example:
//1
/// \
//2   3
///
//4
//\
//5
//The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
	bool isSymmetric_temp(TreeNode* rootL, TreeNode* rootR) {
		if ((rootL == NULL&&rootR == NULL))
		{
			return true;
		}
		if ((rootL == NULL||rootR == NULL))
		{
			return false;
		}
		return rootL->val == rootR->val&&isSymmetric_temp(rootL->left, rootR->right) && isSymmetric_temp(rootL->right, rootR->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
		{
			return true;
		}
		return isSymmetric_temp(root->left, root->right);
	}
};