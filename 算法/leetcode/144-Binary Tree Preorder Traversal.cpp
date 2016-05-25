class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)
        {
        	/* code */
        	vector<int> null_result;
        	return null_result;
        }
        vector<int> result;
        vector<int>::iterator it;
        result.insert(it, root->val);
        vector<int> left = preorderTraversal(root->left);
        result.insert(result.end(),left.begin(),left.end());
        vector<int> right = preorderTraversal(root->right);
        result.insert(result.end(),right.begin(),right.end());
        return result;
    }
};