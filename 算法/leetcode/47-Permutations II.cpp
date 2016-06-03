class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if(num.empty())
        {
            return result;
        }
        sort(num.begin(), num.end());
        // set<vector<int>> result_set;
        // getPermutation(num,0,result_set);
        // for (std::set<vector<int>>::iterator i = result_set.begin(); i != result_set.end(); ++i)
        // {
        //  result.push_back(*i);
        // }
        permuteRecursive(num, 0, result);
        return result;
    }

    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> num, int begin, vector<vector<int> > &result)    {
        if (begin == num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            if(i!=begin&&num[begin]==num[i]) continue;
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            // swap(num[begin], num[i]);
        }
    }
    

    // void getPermutation(vector<int> num,int begin,set<vector<int>> &result) {
    //  if (begin==num.size())
    //  {
    //      result.insert(num);
    //  }

    //  for (int i = begin; i < num.size(); ++i)
    //  {
    //      swap(num[begin],num[i]);
    //      getPermutation(num,begin+1,result);
    // //       swap(num[i],num[begin]);
    //  }
    // }
};