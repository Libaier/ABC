// 168. Excel Sheet Column Title My Submissions QuestionEditorial Solution
// Total Accepted: 56767 Total Submissions: 265377 Difficulty: Easy
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 

class Solution {
public:
    string convertToTitle(int n) {

    	string result = "";
    	while(n>26)
    	{
    		result+=n%26+'A';
    		n = 26*(n/26);
    	}
    	if(n!=0)
    	{
    		result+=n+'A';
    	}
    	reverse(result.begin(), result.end());
    	return result;
        
    }
};