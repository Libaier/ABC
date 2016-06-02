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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode*> visited;
        TreeNode* visiting = root;
        while(visiting!=NULL||!visited.empty())
        {
            if (visiting!=NULL)
            {
                visited.push(visiting);
                result.push_back(visiting->val);
                visiting = visiting->left;
            }else{
                visiting = visited.top();
                visited.pop();
                visiting = visiting->right;
            }  
        }
        return result;
    }

    //inorder
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode*> visited;
        TreeNode* visiting = root;
        while(visiting!=NULL||!visited.empty())
        {
            if (visiting!=NULL)
            {
                visited.push(visiting);
                visiting = visiting->left;
            }else{
                visiting = visited.top();
                result.push_back(visiting->val);
                visited.pop();
                visiting = visiting->right;
            }  
        }
        return result;
    }

    //postorder
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode*> visited;
        TreeNode* visiting = root;
        while(visiting!=NULL||!visited.empty())
        {
            if (visiting!=NULL)
            {
                visited.push(visiting);
                result.push_back(visiting->val);
                visiting = visiting->right;
            }else{
                visiting = visited.top();
                visited.pop();
                visiting = visiting->left;
            }  
        }
        reverse(result.begin(),result.end());
        return result;
    }

    // There is an universal idea for preorder traversal inorder traversal and postorder traversal. For each node N, we process it as follows:
    //push N in stack -> push left tree of N in stack -> pop left tree of N -> push right tree of N in stack -> pop right tree of N -> pop N 
    //For preorder traversal, we visit a node when pushing it in stack. For inorder traversal, we visit a node when pushing its right child in stack. for postorder traversal, we visit a node when popping it. lastpop represents the node which is popped the last time. For the top node in stack, it has three choices, pushing its left child in stack, or pushing its right child in stack, or being popped. If lastpop != top->left, meaning that its left tree has not been pushed in stack, then we push its left child. If last_pop == top->left, we push its right child. Otherwise, we pop the top node.


    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode*> visited;
        visited.push(root);
        result.push_back(visited.top()->val);

        TreeNode* last_visited = root;
        TreeNode* visiting = root;

        while (!visited.empty())
        {
            visiting = visited.top();
            if (visiting->left != NULL && visiting->left != last_visited && visiting->right != last_visited) // push_left
            {
                visited.push(visiting->left);
                result.push_back(visited.top()->val); // visit visiting->left
            }
            else if (visiting->right != NULL && visiting->right != last_visited && (visiting->left == NULL || visiting->left == last_visited)) // push_right
            {
                visited.push(visiting->right);
                result.push_back(visited.top()->val); // visit visiting->right
            }
            else // pop
            {
                visited.pop();
                last_visited = visiting;
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode*> visited;
        visited.push(root);

        TreeNode* last_visited = root;
        TreeNode* visiting = root;

        while (!visited.empty())
        {
            visiting = visited.top();
            if (visiting->left != NULL && visiting->left != last_visited && visiting->right != last_visited) // push_left
            {
                visited.push(visiting->left);
            }
            else if (visiting->right != NULL && visiting->right != last_visited && (visiting->left == NULL || visiting->left == last_visited)) // push_right
            {
                visited.push(visiting->right);
                result.push_back(visiting->val); 
            }
            else // pop
            {
                visited.pop();
                last_visited = visiting;
                if (visiting->right == NULL)
                {
                    result.push_back(visiting->val); 
                }
            }
        }
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode*> visited;
        visited.push(root);

        TreeNode* last_visited = root;
        TreeNode* visiting = root;

        while (!visited.empty())
        {
            visiting = visited.top();
            if (visiting->left != NULL && visiting->left != last_visited && visiting->right != last_visited) // push_left
            {
                visited.push(visiting->left);
            }
            else if (visiting->right != NULL && visiting->right != last_visited && (visiting->left == NULL || visiting->left == last_visited)) // push_right
            {
                visited.push(visiting->right);
            }
            else // pop
            {
                visited.pop();
                last_visited = visiting;
                result.push_back(visiting->val); 
            }
        }
        return result;
    }

    //preorder
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode*> visited;
        visited.push(root);
        TreeNode* visiting = root;
        while(!visited.empty())
        {
            visiting = visited.top();
            result.push_back(visiting->val);
            visited.pop();
            if(visiting->right!=NULL) visited.push(visiting->right);
            if(visiting->left!=NULL) visited.push(visiting->left);
        }
        return result;
    }

    //postorder
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode*> visited;
        visited.push(root);
        TreeNode* visiting = root;
        while(!visited.empty())
        {
            visiting = visited.top();
            result.push_back(visiting->val);
            visited.pop();
            if(visiting->left!=NULL) visited.push(visiting->left);
            if(visiting->right!=NULL) visited.push(visiting->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }


    //levelOrder leetcode
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==NULL) return result;

        queue<TreeNode*> que;
        que.push(root);

        int level = 0;
        while(!que.empty())
        {
            int  size = que.size();
            result.push_back(vector<int>());
            while(size!=0)
            {
                result[level].push_back(que.front()->val);                
                if (que.front()->left!=NULL)
                {
                    que.push(que.front()->left);
                }
                if (que.front()->right!=NULL)
                {
                    que.push(que.front()->right);
                }
                que.pop();
                size--;
            }
            level++;
        }
        return result;  
    }

    //zigzagLevelOrderTraversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==NULL) return result;

        queue<TreeNode*> que;
        que.push(root);

        int level = 0;
        while(!que.empty())
        {
            int  size = que.size();
            result.push_back(vector<int>());
            while(size!=0)
            {
                result[level].push_back(que.front()->val);                
                if (que.front()->left!=NULL)
                {
                    que.push(que.front()->left);
                }
                if (que.front()->right!=NULL)
                {
                    que.push(que.front()->right);
                }
                que.pop();
                size--;
            }
            if (level&0x1==1&&!result[level].empty())
            {
                reverse(result[level].begin(),result[level].end());
            }
            level++;
        }
        return result; 
    }

    //verticalOrder leetcode
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==NULL) return result;

        map<int,vector<int>> result_map;
        queue<pair<int, TreeNode*>> que;
        que.push(make_pair(0,root));

        while(!que.empty())
        {
            int  size = que.size();
            while(size!=0)
            {
                int hd = que.front().first;
                TreeNode* node = que.front().second;
                result_map[hd].push_back(node->val);                
                if (node->left!=NULL)
                {
                    que.push(make_pair(hd-1,node->left));
                }
                if (node->right!=NULL)
                {
                    que.push(make_pair(hd+1,node->right));
                }
                que.pop();
                size--;
            }
        }

        map< int,vector<int> > :: iterator it;
        for (it=result_map.begin(); it!=result_map.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;  
    }
};