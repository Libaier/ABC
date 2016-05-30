class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    	int push_size = pushV.size();
    	int pop_size = popV.size();
        if (push_size!=pop_size||push_size==0)
        {
        	return false;
        }
        stack<int> stk;
        int j = 0;
        for (int i = 0; i < push_size&&j < pop_size; ++i)
        {
        	if (!stk.empty()&&stk.top()==popV[j])
        	{
        		stk.pop();
        		j++;
        	}else{
				if (pushV[i]!=popV[j])
				{
					stk.push(pushV[i]);
				}else{
					j++;
				}
            }
        }

        while(!stk.empty())
        {
        	if (stk.top()!=popV[j])
        	{
        		return false;
        	}
        	stk.pop();
        	j++;
        }
        return true;
    }

	//错误！！！！
    // bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    // 	int push_size = pushV.size();
    // 	int pop_size = popV.size();
    //     if (push_size!=pop_size||push_size==0||pop_size==0)
    //     {
    //     	return false;
    //     }
    //     int i = 0;
    //     for (; i < push_size; ++i)
    //     {
    //     	if (pushV[i]==popV[0])
    //     	{
    //     		break;
    //     	}
    //     }
    //     if (i==push_size)
    //     {
    //     	return false;
    //     }
    //     int l = i-1;
    //     int r = i+1;
    //     int j = 1;
    //     while(j < pop_size)
    //     {
    //     	if (l>=0&&pushV[l]==popV[j])
    //     	{
    //     		j++;
    //     		l--;
    //     	}else if(r<push_size&&pushV[r]==popV[j]){
    //     		j++;
    //     		r++;
    //     	}else{
    //     		return false;
    //     	}
    //     }	
    //     return true;
    // }
};