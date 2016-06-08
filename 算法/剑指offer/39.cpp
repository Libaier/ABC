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

    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot==NULL)
        {
        	return 0;
		}
    	queue<TreeNode*> visited;
    	visited.push(pRoot);
    	int size = 1;
    	int level = 0;
    	while(!visited.empty())
    	{
    		int sizetemp = 0;
    		level++;
    		while(size!=0)
    		{
    			if (visited.front()->left!=NULL)
	    		{
	    			visited.push(visited.front()->left);
	    			sizetemp++;
	    		}

	    		if (visited.front()->right!=NULL)
	    		{
	    			visited.push(visited.front()->right);
	    			sizetemp++;
	    		}
	    		visited.pop();
	    		size--;
    		}
    		size = sizetemp;
    	}
    	return level;
    }

	// int getDepth(TreeNode* pRoot,int depth)
	// {
	// 	if (pRoot==NULL)
	// 	{
	// 		return depth;
	// 	}
	// 	int depthl = getDepth(pRoot->left,depth+1);
	// 	int depthr = getDepth(pRoot->right,depth+1);
	// 	return depthl>depthr?depthl:depthr;
	// }
 //    int TreeDepth(TreeNode* pRoot)
 //    {
 //    	return getDepth(pRoot,0);
 //    }

//wrong
	// int TreeDepth(TreeNode* pRoot)
 //    {
 //        if(pRoot==NULL)
 //        {
 //        	return 0;
	// 	}
 //    	stack<TreeNode*> visited;
 //    	int maxDepth = -1;
 //    	int depthTemp = 0;
 //    	TreeNode* visiting = pRoot;
 //    	while(visiting!=NULL||!visited.empty())
 //    	{	
 //    		if (visiting!=NULL)
 //    		{
 //    			depthTemp++;
 //    			if (depthTemp>maxDepth)
 //    			{
 //    				maxDepth = depthTemp;
 //    			}
 //    			visited.push(visiting);
 //    			visiting = visiting->left;
 //    		}else{
 //    			visiting = visited.top();
 //    			visited.pop();
 //    			depthTemp--;
 //    			visiting = visiting->right;
 //    		}
 //    	}
 //    	return maxDepth;
 //    }
};
class Solution {
public:
	// int getDepth(TreeNode* pRoot,int depth)
	// {
	// 	if (pRoot==NULL)
	// 	{
	// 		return depth;
	// 	}
	// 	int depthl = getDepth(pRoot->left,depth+1);
	// 	int depthr = getDepth(pRoot->right,depth+1);
	// 	return depthl>depthr?depthl:depthr;
	// }

 //    bool IsBalanced_Solution(TreeNode* pRoot) {
 //        if (pRoot==NULL)
	// 	{
	// 		return true;
	// 	}
 //    	int depthl = getDepth(pRoot->left,1);
 //    	int depthr = getDepth(pRoot->right,1);
 //    	if (abs(depthl-depthr)<=1)
 //    	{
 //    		return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
 //    	}else{
 //    		return false;
 //    	}
 //    }

	bool IsBalanced(TreeNode* pRoot,int &depth)
	{
		if (pRoot==NULL)
		{
			return true;
		}
		int left = 0,right = 0;
		if(IsBalanced(pRoot->left,left)&&
		IsBalanced(pRoot->right,right))
		{
			if (abs(left-right)<=1)
			{
				depth = max(left,right)+1;
				return true;
			}
		}
		return false;
	}

    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
    	return IsBalanced(pRoot,depth);
    }
};