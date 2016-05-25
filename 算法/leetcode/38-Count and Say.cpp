class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 0;i<n-1;i++)
        {
            int tag = 0;
            char temp = result[tag];
            int count = 0;
            stringstream result_temp;
            while(tag<result.size())
            {
                if(result[tag]==temp)
                {
                    count++;
                    if(tag==result.size()-1)
                    {
                        result_temp<<count<<temp;
                    }
                    tag++;
                }else{
                    result_temp<<count<<temp;
                    count = 0;
                    temp = result[tag];
                }
            }
            result = result_temp.str();
        }
        return result;
    }
};