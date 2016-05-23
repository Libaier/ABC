class Solution {
public:
    int addDigits(int num) {
        int num_temp = num;//用于储存最终结果
        while(num_temp>=10)
        {
            int yushu_sum = num_temp%10;//用于存储每一位的余数 0
            int num_temp_onepass = num_temp/10;//1
            
            while(num_temp_onepass>=1)
            {
                int yushu_temp = num_temp_onepass%10;
                yushu_sum+=yushu_temp;
                num_temp_onepass = num_temp_onepass/10;
            }
            num_temp = yushu_sum;
        }
        
        return num_temp;
    }
};