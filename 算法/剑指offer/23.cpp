/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> result;
        if (root==NULL)
        {
        	return result;
        }
		queue<TreeNode *> que;
        que.push(root);
        while(!que.empty())
        {
        	if (que.front()->left!=NULL)
        	{
        		que.push(que.front()->left);
        	}

        	if (que.front()->right!=NULL)
        	{
        		que.push(que.front()->right);
        	}

        	result.push_back(que.front()->val);
        	que.pop();
        }

        return result;
    }
};