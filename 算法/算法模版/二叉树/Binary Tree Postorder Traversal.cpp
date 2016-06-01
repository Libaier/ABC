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
	//preorder
    void preorder(TreeNode* root,vector<int> &result) {
        if (root==NULL) return;
        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root,result);
        return result;
    }


    //inorder
    void inorder(TreeNode* root,vector<int> &result) {
        if (root==NULL) return;
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root,result);
        return result;   
    }


    //postorder
    void postorder(TreeNode* root,vector<int> &result) {
        if (root==NULL) return;
        postorder(root->left,result);
        postorder(root->right,result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root,result);
        return result;   
    }

    //levelOrder
    void levelOrder(TreeNode* root,vector<vector<int>> &result,int depth) {
        if (root==NULL) return;
        if (result.size()==depth)
        {
        	result.push_back(vector<int>());
        }
        result[depth].push_back(root->val);
        levelOrder(root->left,result,depth+1);
        levelOrder(root->right,result,depth+1);
    }

    vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root,result,0);
        return result;  
    }

    // //levelOrder leetcode
    // void levelOrderTraversal(TreeNode* root,vector<vector<int>> &result,int depth) {
    //     if (root==NULL) return;
    //     if (result.size()==depth)
    //     {
    //     	result.push_back(vector<int>());
    //     }
    //     result[depth].push_back(root->val);
    //     levelOrderTraversal(root->left,result,depth+1);
    //     levelOrderTraversal(root->right,result,depth+1);
    // }

    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> result;
    //     levelOrderTraversal(root,result,0);
    //     return result;  
    // }


    //verticalOrder
    
    void verticalOrder(TreeNode* root,vector<vector<int>> &result,int depth) {
        if (root==NULL) return;
        if (result.size()==depth)
        {
        	result.push_back(vector<int>());
        }
        result[depth].push_back(root->val);
        levelOrder(root->left,result,depth+1);
        levelOrder(root->right,result,depth+1);
    }

    vector<vector<int>> verticalOrderTraversal(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root,result,0);
        return result;  
    }

};