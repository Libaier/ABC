/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstruct(vector<int> pre,vector<int> in,int ps,int pe,int is,int ie) {
    	if (ps>pe||is>ie)
		{
			return NULL;
		}
    	struct TreeNode* root = new TreeNode(pre[ps]);
    	if (ps==pe||is==ie)
    	{
    		root->right = NULL;
    		root->left = NULL;
    	}else{
    		int i = is;
    		for (; i <= ie; ++i)
    		{
    			if (in[i]==root->val)
    			{
    				break;
    			}
    		}
    		root->left = reConstruct(pre,in,ps+1,ps+i-is,is,i-1);

    		root->right = reConstruct(pre,in,ps+i-is+1,pe,i+1,ie);
    	}
    	return root;
    }

    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
    	if (pre.empty()||in.empty())
    	{
    		return NULL;
    	}
    	struct TreeNode* root;
    	root = reConstruct(pre,in,0,pre.size()-1,0,in.size()-1);
    	return root;
    }
};