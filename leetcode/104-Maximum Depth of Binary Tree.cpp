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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int leftmax =  maxDepth(root->left)+1;
        int rightmax = maxDepth(root->right)+1;
        return leftmax>rightmax?leftmax:rightmax;
    }
};