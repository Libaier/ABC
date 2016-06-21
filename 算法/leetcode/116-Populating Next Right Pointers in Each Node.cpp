// 116. Populating Next Right Pointers in Each Node My Submissions QuestionEditorial Solution
// Total Accepted: 91344 Total Submissions: 249558 Difficulty: Medium
// Given a binary tree

//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Note:

// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
// For example,
// Given the following perfect binary tree,
//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    //递归
    // void connect(TreeLinkNode *root) {
    //     if (NULL == root)
    //     {
    //       return;
    //     }
        
    //     if (root->left)
    //     {
    //       root->left->next = root->right;
    //       if (root->next)
    //       {
    //         root->right->next = root->next->left;
    //       }else{
    //         root->right->next = NULL;  
    //       }
    //     }
    //     connect(root->left);
    //     connect(root->right);
    // }

    //迭代
    void connect(TreeLinkNode *root) {
        if (NULL == root)
        {
          return;
        }
        
        TreeLinkNode *p = root;
        TreeLinkNode *q = NULL;
        while (p->left)
        {
          q = p;
          while (q)
          {
            q->left->next = q->right;
            if (q->next)
            {
              q->right->next = q->next->left;
            }
            q = q->next;
          }
          p = p->left;
        }
    }
};