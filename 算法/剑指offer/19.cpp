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
    void Mirror(TreeNode *pRoot) {
		if (pRoot==NULL)
        {
        	return;
        }
        TreeNode *l = pRoot->left;
        TreeNode *r = pRoot->right;
        pRoot->left = r;
        pRoot->right = l; 
        Mirror(r);
        Mirror(l);
    }
};