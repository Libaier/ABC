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


    //levelOrder leetcode
    void levelOrderTraversal(TreeNode* root,vector<vector<int>> &result,int depth) {
        if (root==NULL) return;
        if (result.size()==depth)
        {
        	result.push_back(vector<int>());
        }
        result[depth].push_back(root->val);
        levelOrderTraversal(root->left,result,depth+1);
        levelOrderTraversal(root->right,result,depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderTraversal(root,result,0);
        return result;  
    }


	//zigzagLevelOrderTraversal
    void zigzagLevelOrderTraversal(TreeNode* root,vector<vector<int>> &result,int depth) {
        if (root==NULL) return;
        if (result.size()==depth)
        {
        	result.push_back(vector<int>());
        }
        result[depth].push_back(root->val);
        zigzagLevelOrderTraversal(root->left,result,depth+1);
        zigzagLevelOrderTraversal(root->right,result,depth+1);

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        zigzagLevelOrderTraversal(root,result,0);
        
        for(int depth=0;depth<result.size();depth++)
        {
            if (depth&0x1==1&&!result[depth].empty())
            {
            	reverse(result[depth].begin(),result[depth].end());
            }
        }
        return result;  
    }



    //verticalOrder leetcode wrong
    void verticalOrderTraversal(TreeNode* root,map<int,vector<int>> &result,int hdepth) {
        if (root==NULL) return;
        result[hdepth].push_back(root->val);
        verticalOrderTraversal(root->left,result,hdepth-1);
        verticalOrderTraversal(root->right,result,hdepth+1);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<int>> result;
       	vector<vector<int>> result_v;
        verticalOrderTraversal(root,result,0);
        map< int,vector<int> > :: iterator it;
	    for (it=result.begin(); it!=result.end(); it++)
	    {
	        vector<int> resultTemp;
	        for (int i=0; i<it->second.size(); ++i)
                resultTemp.push_back(it->second[i]);
	        result_v.push_back(resultTemp);
	    }
        return result_v;  
    }

};