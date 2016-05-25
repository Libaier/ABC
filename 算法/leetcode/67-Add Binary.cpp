// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int size = (m>n?m:n)+1;
        string result(size,'0');
        int temp = 0;
        for(int i = 0;i < size; i++)
        {
            int a_temp = 0;
            if(i <= m-1)
            {
                a_temp = a[m-i-1]-'0';
            }
            int b_temp = 0;
            if(i <= n-1)
            {
                b_temp = b[n-i-1]-'0';
            }
            int result_temp = a_temp+b_temp+temp;
            if(result_temp>=2)
            {
                result[size-1-i] = '0'+result_temp-2;
                temp = 1;
            }else{
                result[size-1-i] = '0'+result_temp;
                temp = 0;
            }
        }
        if(result[0] == '0')
        {
            result = result.substr (1);
        }
        return result;
        
    }
};