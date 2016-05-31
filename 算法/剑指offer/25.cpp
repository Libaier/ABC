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
    

//非递归版本
//思路：
// 1.按先序遍历把当前节点cur的左孩子依次入栈同时保存当前节点，每次更新当前路径的和sum；
// 2.判断当前节点是否是叶子节点以及sum是否等于expectNumber，如果是，把当前路径放入结果中。
// 3.遇到叶子节点cur更新为NULL，此时看栈顶元素，如果栈顶元素的把栈顶元素保存在last变量中，同时弹出栈顶元素，当期路径中栈顶元素弹出，sum减掉栈顶元素，这一步骤不更改cur的值；
// 4.如果步骤3中的栈顶元素的右孩子存在且右孩子之前没有遍历过，当前节点cur更新为栈顶的右孩子，此时改变cur=NULL的情况。
    // vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

    //     vector<vector<int> > result;
    //     if (root==NULL)
    //     {
    //         return result;
    //     }

    //     vector<int> vecNum;
    //     vector<TreeNode*> vecNode;
    //     int currentSum = 0;
    //     vecNode.push_back(new TreeNode(-1));

    //     TreeNode* cur = root;
    //     TreeNode* last = NULL;
    //     while(!vecNode.empty())
    //     {
    //         if (cur==NULL)
    //         {
    //             if (vecNode.back()->right!=NULL&&vecNode.back()->right!=last)
    //             {
    //                 cur = vecNode.back()->right;
    //             }else{
    //                 currentSum -= vecNum.back();
    //                 last = vecNode.back();      
    //                 vecNum.pop_back();
    //                 vecNode.pop_back();
    //             }
    //         }else{
    //             vecNode.push_back(cur);
    //             vecNum.push_back(cur->val);
    //             currentSum += cur->val;
    //             if (cur->left==NULL&&cur->right==NULL&&currentSum==expectNumber&&vecNode.size()!=1)
    //             {
    //                 result.push_back(vecNum);
    //             }
    //             cur = cur->left;
    //         }
    //     }

    //     return result;
    // }

    void FindPathResult(TreeNode* root,int expectNumber,vector<vector<int> > &result,vector<int> &resultTemp,int &sum)
    {
        if (root==NULL)
        {
            return;
        }
        if (root!=NULL)
        {
            sum+=root->val;
            resultTemp.push_back(root->val);
        }

        if (root->left==NULL&&root->right==NULL)
        {          
            if (sum==expectNumber)
            {
                result.push_back(resultTemp);
            }
            resultTemp.pop_back();
            sum-=root->val;
            return;
        }
        FindPathResult(root->left,expectNumber,result,resultTemp,sum);
        FindPathResult(root->right,expectNumber,result,resultTemp,sum);
        resultTemp.pop_back();
        sum-=root->val;
    }

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

        vector<vector<int> > result;
        vector<int> resultTemp;
        int sum = 0;
        if (root==NULL)
        {
            return result;
        }
        FindPathResult(root,expectNumber,result,resultTemp,sum);
        return result;
    }
};