
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;

    permuteRecursive(num, 0, result);
    return result;
}

// permute num[begin..end]
// invariant: num[0..begin-1] have been fixed/permuted
void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
    if (begin == num.size()) {
        // one permutation instance
        result.push_back(num);
        return;
    }

    for (int i = begin; i < num.size(); i++) {
        swap(num[begin], num[i]);
        permuteRecursive(num, begin + 1, result);
        // reset
        swap(num[begin], num[i]);
    }
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > result;
    if(num.empty())
    {
        return result;
    }
    sort(num.begin(), num.end());
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