// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        int count = 0;
        while(n>=0)
        {
            if(s[n]!=' ')
            {
                count++;
            }else if(count!=0){
                return count;
            }
            n--;
        }
        return count;
    }
};