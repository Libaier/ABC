//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.


class Solution {
public:
	inline int map(const char c) {
		switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
		}
	}
	int romanToInt(string s) {
		int result = 0;
		int max = 0;
		for (int i = s.size()-1; i >=0; i--)
		{
			if (map(s[i]) >= max)
			{
				result = result + map(s[i]);
				max = map(s[i]);
			}
			else{
				result = result - map(s[i]);
			}
		}
		return result;
	}
};