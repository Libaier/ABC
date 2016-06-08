class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<=1)
        {
            return;
        }
		int result = 0;
		for (int i = 0; i < data.size(); ++i)
		{
			result = result^data[i];
		}
		int tag  = 0;
		while(result)
		{
			if (((result>>tag)&0x1)==1)
			{
				break;
			}
			tag++;
		}

		*num1 = 0;
		*num2 = 0;

		for (int i = 0; i < data.size(); ++i)
		{
			if (((data[i]>>tag)&0x1)==1)
			{
				*num1 = *num1^data[i];
			}else{
				*num2 = *num2^data[i];
			}
		}
    }
};