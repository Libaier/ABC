class Solution {
public:
    static bool compare(string st1,string st2){
        string s1 = st1+st2;
        string s2 = st2+st1;
        return s1<s2;
    }
    string PrintMinNumber(vector<int> numbers) {
    	string result;
        if (numbers.empty())
        {
        	return result;
        }
        vector<string> numbers_str;
        for (int i = 0; i < numbers.size(); ++i)
        {
        	stringstream ss;
		 	ss<<numbers[i]; 
		 	string s1 = ss.str();
        	numbers_str.push_back(s1);
        }
        sort(numbers_str.begin(),numbers_str.end(),compare);
        for (int i = 0; i < numbers_str.size(); ++i)
        {
        	result+=numbers_str[i];
        }
        return result;
    }
};