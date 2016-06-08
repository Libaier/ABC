class Solution {
public:
    vector<int> singleNumber(vector<int>& data) {
        vector<int> result_v = {0,0};
        if(data.size()<=1)
        {
            return result_v;
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

		

		for (int i = 0; i < data.size(); ++i)
		{
			if (((data[i]>>tag)&0x1)==1)
			{
				result_v[0] = result_v[0]^data[i];
			}else{
				result_v[1] = result_v[1]^data[i];
			}
		}
		return result_v;
    }
};