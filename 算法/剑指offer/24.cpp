class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	int size = sequence.size();
    	if (size==0)
    	{
    		return false;
    	}
    	return isSquenceOfBST(sequence,0,size-1);
    }

    bool isSquenceOfBST(vector<int> sequence,int s,int e) {
    	if (s>=e)
    	{
    		return true;
    	}
    	int tag = -1;
    	for (int i = s; i < e; ++i)
    	{
    		if (sequence[i]>sequence[e])
    		{
    			tag = i;
    		}

    		if (tag!=-1&&sequence[i]<=sequence[e])
    		{
    			return false;
    		}
    	}

    	return isSquenceOfBST(sequence,s,tag-1)&&isSquenceOfBST(sequence,tag,e-1);
    }
};