// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.
class Solution {
public:
	const vector<string> keyboard{ " ", "", "abc", "def", // '0','1','2',...
		"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> strCombinations(string digits, vector<string> str) {

		vector<string> result;
		for (int i = 0; i < keyboard[digits[0] - '0'].size(); i++)
		{
			for (int j = 0; j < str.size(); j++)
			{
				string s(1, keyboard[digits[0] - '0'][i]);
				s = s + str[j];
				result.push_back(s);
			}
		}
		return result;
	}

	vector<string> letterCombinations(string digits) {

		if (digits.empty())
		{
			vector<string> result;
			return result;
		}

		if (1 == digits.size()){
			vector<string> temp;
			temp.push_back("");
			return strCombinations(digits, temp);
		}

		return strCombinations(digits.substr(0, 1), letterCombinations(digits.substr(1)));
	}
};