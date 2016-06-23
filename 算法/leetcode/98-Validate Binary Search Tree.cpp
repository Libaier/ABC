// 98. Validate Binary Search Tree My Submissions QuestionEditorial Solution
// Total Accepted: 97942 Total Submissions: 463147 Difficulty: Medium
// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:
//     2
//    / \
//   1   3
// Binary tree [2,1,3], return true.
// Example 2:
//     1
//    / \
//   2   3
// Binary tree [1,2,3], return false.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//   bool helper(TreeNode* root,int &lastVal)
//   {
//     if (root==NULL)
//     {
//       return true;
//     } 
//     if (lastVal)
//     {
//       /* code */
//     }

//     if (root->right)
//     {
//       lastVal = root->right->val;
//     }else{
//       lastVal = root->val;
//     }
//     return isValidBST(root->left,lastVal)&&isValidBST(root->right,lastVal);  	
//   }
//   bool isValidBST(TreeNode* root) {
//     if (root==NULL)
//     {
//       return true;
//     }
//     int val = INT_MIN;
//     helper(root,val);
//   }
// };

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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};