class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> result_l,result_r,result;
    	int l = 1,r = 1;
    	for (int i = 0; i < A.size(); ++i)
    	{
    		result_l.push_back(l);
    		l = l*A[i];
    	}
    	for (int i = 0; i < A.size(); ++i)
    	{
    		result_r.push_back(r);
    		r = r*A[A.size()-1-i];
    	}
    	for (int i = 0; i < A.size(); ++i)
    	{
    		result.push_back(result_l[i]*result_r[A.size()-1-i]);
    	}
    	return result;
    }
};