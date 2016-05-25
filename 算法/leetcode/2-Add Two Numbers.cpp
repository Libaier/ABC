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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = (ListNode*)malloc(sizeof(ListNode));
        int plus = 0;
        ListNode* tag = result;
        
        ListNode* tag1 = NULL;
        
        while(l1!=NULL||l2!=NULL)
        {
            int v1 = 0;
            int v2 = 0;
            if(l1!=NULL)
            {
                v1 = l1->val;
                l1 = l1->next;
            }
            
            if(l2!=NULL)
            {
                v2 = l2->val;
                l2 = l2->next; 
            }
            
            if(v1+v2+plus>9)
            {
                tag->val = v1+v2+plus-10;
                plus = 1;
                
            }else{
                
                tag->val = v1+v2+plus;
                plus = 0;
            }
            ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
            tag->next = temp;
            tag1=tag;
            tag = temp;
        }
        if(plus == 1)
        {
            tag->val = plus;
            tag->next = NULL;
        }else{
            tag1->next = NULL;
            free(tag);
        }
  
        return result;
    }
};