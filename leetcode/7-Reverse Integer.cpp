class Solution {
public:
    int reverse(int x) {

        long result = 0;
        if(x>0){
            int temp_1 = x;
            int temp_2 = temp_1%10;
            while(temp_1>0)
            {
                result = result*10+temp_2;
                temp_1 = temp_1/10;
                temp_2 = temp_1%10;
            }
            
        }else{
            int temp_1 = -x;
            int temp_2 = temp_1%10;
            while(temp_1>0)
            {
                result = result*10+temp_2;
                temp_1 = temp_1/10;
                temp_2 = temp_1%10;
            }
            result = -result;
        }
        if(result>=numeric_limits<int>::max()||result<=numeric_limits<int>::min())
        {
            return 0;
        }
        return result;
    }
};