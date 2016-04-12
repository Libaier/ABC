// 160. Intersection of Two Linked Lists My Submissions QuestionEditorial Solution
// Total Accepted: 69783 Total Submissions: 230947 Difficulty: Easy
// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
// Credits:
// Special thanks to @stellari for adding this problem and creating all test cases.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa=headA,*pb=headB;
        int lengthA=0,lengthB=0;
        while(pa) {pa=pa->next;lengthA++;}
        while(pb) {pb=pb->next;lengthB++;}
        if(lengthA<=lengthB){
            int n=lengthB-lengthA;
            pa=headA;pb=headB;
            while(n) {pb=pb->next;n--;}
        }else{
            int n=lengthA-lengthB;
            pa=headA;pb=headB;
            while(n) {pa=pa->next;n--;}
        }
        while(pa!=pb){
            pa=pa->next;
            pb=pb->next;
        }
        return pa;
    }
};