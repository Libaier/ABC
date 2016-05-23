// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result  = new ListNode(0);
        result->next = NULL;
        
        ListNode* tag = result;
        
        while(l1||l2)
        {
            if((l2!=NULL&&l1!=NULL&&l2->val<l1->val)||l1==NULL)
            {
                ListNode* temp = new ListNode(l2->val);
                tag->next = temp;
                temp->next = NULL;
                l2 = l2->next;
                tag = tag->next;
            }else{
                ListNode* temp = new ListNode(l1->val);
                tag->next = temp;
                temp->next = NULL;
                l1 = l1->next;
                tag = tag->next;
            }
        }
        
        
        ListNode* result_temp = result->next;
        delete result;
        return result_temp;
    }
};