class Solution {
public:
    // Solution1
    // vector<string> Permutation(string str) {
    //  vector<string> result;
    //     if (str.empty())
    //     {
    //      return result;
    //     }
    //     sort(str.begin(),str.end());
         
    //      do
    //     {
    //      result.push_back(str);
    //     } while(next_permutation(str.begin(),str.end()));
    //     return result;
    // }
 
    vector<string> Permutation(string str) {
        vector<string> result;
        if (str.empty())
        {
            return result;
        }
        set<string> result_set;
        getPermutation(str,0,result_set);
        for (std::set<string>::iterator i = result_set.begin(); i != result_set.end(); ++i)
        {
            result.push_back(*i);
        }
        return result;
    }
 
    void getPermutation(string &str,int begin,set<string> &result) {
        if (begin==str.size())
        {
            result.insert(str);
        }
 
        for (int i = begin; i < str.size(); ++i)
        {
            swap(str[begin],str[i]);
            getPermutation(str,begin+1,result);
            swap(str[i],str[begin]);
        }
    }
};