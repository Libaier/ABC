/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(NULL==head||NULL==head->next)
        {
            return head;//假如列表为空或只有一个节点直接返回
        }
        ListNode *tail = head;//存储现在的list尾
        ListNode *tag = head->next;
        while(NULL!=tag)
        {
            if(tag->val!=tail->val)
            {
                tail->next->val = tag->val;
                tail = tail->next;
            }
            tag = tag->next;
        }
        
        tail->next = NULL;
        return head;
    }
};