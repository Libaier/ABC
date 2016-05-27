//length为牛客系统规定字符串输出的最大长度，固定为一个常数
class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (NULL == str || 0 >= length) return;
        int p1 = 0, p2, num_of_blank = 0;
        while (str[p1])
        {
            if (str[p1] == ' ')
            {
                num_of_blank++;
            }
            p1++;
        }
        p2 = p1 + 2 * num_of_blank;
        while (p1 != p2)
        {
            if (' ' != str[p1])
            {
                str[p2--] = str[p1];
                p1--;
            }
            else{
                str[p2--] = '0', str[p2--] = '2', str[p2--] = '%';
                p1--;
            }
        }
        //getchar();
        return;
    }
};