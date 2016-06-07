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
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        if (pHead1==NULL||pHead2==NULL)
        {
            return NULL;
        }
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        int size1 = 0,size2 = 0;
        while(p1)
        {
            size1++;
            p1 = p1->next;
        }
        while(p2)
        {
            size2++;
            p2 = p2->next;
        }

        int distance = size1 - size2;
        
        if (distance>0)
        {
            for (int i = 0; i < distance; ++i)
            {
                pHead1 = pHead1->next;
            }
        }else{
            for (int i = 0; i < distance; ++i)
            {
                pHead2 = pHead2->next;
            }
        }

        while(pHead2&&pHead1)
        {
            if (pHead1==pHead2)
            {
                return pHead1;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }

        return NULL;
    }
};