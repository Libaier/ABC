/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
		{
			return NULL;
		}
		RandomListNode* pHeadTemp = pHead;
		while (pHeadTemp)
		{
			RandomListNode* pNodeClone = new RandomListNode(pHeadTemp->label);
			RandomListNode* pNodeTemp = pHeadTemp->next;
			pHeadTemp->next = pNodeClone;
			pNodeClone->next = pNodeTemp;
			pHeadTemp = pNodeTemp;
		}

		pHeadTemp = pHead;

		while (pHeadTemp)
		{

			if (pHeadTemp->random)
			{
				pHeadTemp->next->random = pHeadTemp->random->next;
			}

			pHeadTemp = pHeadTemp->next->next;
		}


		pHeadTemp = pHead;
		RandomListNode* result = pHead->next;
		RandomListNode* resultTemp = pHead->next;


		while (pHeadTemp)
		{
			pHeadTemp->next = resultTemp->next;
			if (resultTemp->next == NULL)
			{
				break;
			}
			else
			{
				resultTemp->next = resultTemp->next->next;
			}
			pHeadTemp = pHeadTemp->next;
			resultTemp = pHeadTemp->next;
		}

		return result;

		  //拆分
        // RandomListNode *pCloneHead = pHead->next;
        // RandomListNode *tmp;
        // RandomListNode *currNode = pHead;
        // while(currNode->next){
        //     tmp = currNode->next;
        //     currNode->next =tmp->next;
        //     currNode = tmp;
        // }
        // return pCloneHead;
	}

};