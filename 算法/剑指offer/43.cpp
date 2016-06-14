class Solution {
public:
    // string ReverseSentence(string str) {
    //     string res = "", tmp = "";
    //     for(unsigned int i = 0; i < str.size(); ++i){
    //         if(str[i] == ' ') res = " " + tmp + res, tmp = "";
    //         else tmp += str[i];
    //     }
    //     if(tmp.size()) res = tmp + res;
    //     return res;
    // }
	string Reverse(string str_)
	{
        string str = str_;
		for (int i = 0; i < str.size()/2; ++i)
		{
			char temp = str[str.size()-1-i];
			str[str.size()-1-i] = str[i];
			str[i] = temp;
		}
		return str;
	} 
    string ReverseSentence(string str) {
    	if (str.find(" ")==string::npos)
    	{
    		return str;
    	}
    	string result = str;
    	string result_final = "";
    	result = Reverse(result);
    	int s = -1;
    	int e = 0;
    	while(1)
    	{
    		e = result.find(" ",s+1);
    		if (e==-1)
    		{
    			result_final+=Reverse(result.substr(s+1));
    			break;
    		}
    		result_final+=Reverse(result.substr(s+1,e-s-1));
    		result_final+=" ";
    		s = e;
    	}
    	return result_final;
	}
}; 