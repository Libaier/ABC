/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
    	if (pHead == NULL||pHead->next == NULL)
    	{
    		return pHead;
    	}

    	ListNode* p1 = pHead;
    	ListNode* p2 = p1->next;
    	ListNode* p3 = p2->next;
    	p1->next = NULL;

    	while(p3!=NULL)
    	{
    		p2->next = p1;
    		p1 = p2;
    		p2 = p3;
    		p3 = p3->next;
    	}
    	p2->next = p1;
    	return p2;
    }
};