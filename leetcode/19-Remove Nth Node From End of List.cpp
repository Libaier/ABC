// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* result = (ListNode*)malloc(sizeof(ListNode*));
//         result->next = head;
//         ListNode* temp1 =  head;
//         ListNode* temp2 = (ListNode*)malloc(sizeof(ListNode*));
//         temp2->next = head;
        
//         for(int i=0;i<n;i++)
//         {
//             temp1 = temp1->next;
//         }

//         while(temp1!=NULL){
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }
        
//         ListNode* temp3 = temp2->next;
//         temp2->next = temp2->next->next;
//         free(temp3);
//         free(temp2);
//         return result->next;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* spark = new ListNode(0);
        spark->next = head;
        ListNode* ahead = head;
        int i;
        for(i=0; i<n; i++)
            ahead = ahead->next;
        ListNode* behind = spark;

        while(ahead)
        {
            ahead = ahead->next;
            behind = behind->next;
        }

        ListNode* tmp = behind->next;
        behind->next = behind->next->next;
        delete tmp;
        ListNode* result = spark->next;
        delete spark;
        return spark->next;
    }
};