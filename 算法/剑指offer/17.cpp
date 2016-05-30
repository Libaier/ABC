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
    // ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    // {
    //     ListNode* result = new ListNode(0);
    //     ListNode* phead = result;
    //     while(pHead1!=NULL&&pHead2!=NULL)
    //     {
    //         if (pHead1->val<pHead2->val)
    //         {
    //         	phead->next = pHead1;
    //         	phead = phead->next;
    //         	pHead1 = pHead1->next;
    //         }else{
    //         	phead->next = pHead2;
    //         	phead = phead->next;
    //         	pHead2 = pHead2->next;            	
    //         }
    //     }

    //     if (pHead1!=NULL)
    //     {
    //     	phead->next = pHead1;
    //     }else if(pHead2!=NULL){
    //     	phead->next = pHead2;
    //     }
    //     ListNode* finalResult = result->next;
    //     delete(result);
    //     return finalResult;
    // }

    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
    	if (pHead1==NULL)
        {
        	return pHead2;
        }else if(pHead2==NULL){
        	return pHead1;
        }
        ListNode* result = NULL;

        if (pHead1->val<pHead2->val)
        {
        	result = pHead1;
        	result->next = Merge(pHead1->next,pHead2);
        }else{
        	result = pHead2;
        	result->next = Merge(pHead1,pHead2->next);          	
        }
        return result;
    }
};

void add(int a,int b)
{
	a = a+b;
}

void main()
{
	int a = 1,b=2;
	add(a,b);
	printf("%d\n",a);
}