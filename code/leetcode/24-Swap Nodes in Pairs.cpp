// 24. Swap Nodes in Pairs My Submissions QuestionEditorial Solution
// Total Accepted: 88534 Total Submissions: 253522 Difficulty: Easy
// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* result = head;
        if(head==NULL)
        {
            return result;
        }
        ListNode* node0 = head;
        ListNode* node1 = node0->next;
        if(node1==NULL)
        {
            return result;
        }
        ListNode* node2 = node1->next;
        node1->next = node0;
        node0->next = node2;
        result = node1;
        while(node2!=NULL&&node2->next!=NULL)
        {
            ListNode* nodepre = node0;
            node0 = node2;
            node1 = node0->next;
            node2 = node1->next;
            node1->next = node0;
            node0->next = node2;
            nodepre->next = node1;
        }
        return result;
    }
};