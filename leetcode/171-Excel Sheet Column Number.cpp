// 171. Excel Sheet Column Number My Submissions QuestionEditorial Solution
// Total Accepted: 73699 Total Submissions: 178756 Difficulty: Easy
// Related to question Excel Sheet Column Title

// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int scale = 1;
        for(int i = s.size()-1;i>=0;i--)
        {
            result += scale*(s[i]-'A'+1);
            scale = scale*26;
        }
        return result;
    }
};