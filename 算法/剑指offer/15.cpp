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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if (pListHead==NULL)
    	{
    		return NULL;
    	}

    	ListNode* pListHeadtemp = pListHead;
    	int i = 0;
    	for (; i < k&&pListHeadtemp; ++i)
    	{
    		pListHeadtemp = pListHeadtemp->next;
    	}

    	if (i!=k)
    	{
    		return NULL;
    	}

    	while(pListHeadtemp)
    	{
    		pListHeadtemp = pListHeadtemp->next;
    		pListHead = pListHead->next;
    	}
    	return pListHead;
    }
};