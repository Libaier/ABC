// 206. Reverse Linked List My Submissions QuestionEditorial Solution
// Total Accepted: 99659 Total Submissions: 254572 Difficulty: Easy
// Reverse a singly linked list.

// click to show more hints.

// Subscribe to see which companies asked this question

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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL||head->next==NULL)
        {
        	/* code */
        	return head;
        }
		ListNode* temp1 = head;
		ListNode* temp2 = temp1->next;
		ListNode* temp3 = temp2->next;
		temp1->next = NULL;
		temp2->next = temp1;
		while(temp3!=NULL)
		{
			temp1 = temp2;
			temp2 = temp3;
			temp3 = temp3->next;
			temp2->next = temp1;
		}
		return temp2;
    }
};