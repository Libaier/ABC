class Solution {
public:
    string intToRoman(int num) {
        string result;
        string s[4][10] = {{"I","II","III","IV","V","VI","VII","VIII","IX"},{"X","XX","XXX","XL","L","LX"
    ,"LXX","LXXX","XC"},{"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},{"M","MM","MMM"}}; 
        int th = num/1000;
        if(th!=0)
        {
            result += s[3][th-1];
            num = num-th*1000;
        }
        
        int hun = num/100;
        if(hun!=0)
        {
            result += s[2][hun-1];
            num = num-hun*100;
        }
        
        int de = num/10;
        if(de!=0)
        {
            result += s[1][de-1];
            num = num-de*10;
        }
        
        if(num!=0)
        {
            result += s[0][num-1];
        }
        
        return result;
        
    }
};