/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
// class Solution {
// public:
//     vector<int> printListFromTailToHead(struct ListNode* head) {
//         stack<int> result_stk;
//         vector<int> result;
//         while(head)
//         {
//             result_stk.push(head->val);
//             head = head->next;
//         }
//         while(!result_stk.empty())
//         {
//             result.push_back(result_stk.top());
//             result_stk.pop();
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> result;
        if (NULL==head)
        {
            return result;
        }

        vector<int> temp = printListFromTailToHead(head->next); 
        for (int i = 0; i < temp.size(); ++i)
        {
            result.push_back(temp[i]);
        }
        result.push_back(head->val);
        return result;
    }
};