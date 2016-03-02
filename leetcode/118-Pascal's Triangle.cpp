class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
        {
            return result;
        }
        vector<int> temp ;
        temp.push_back(1);
        result.push_back(temp);
        
        if(numRows == 1)
        {
            return result;
        }
        
        temp.clear();
        temp.push_back(1);
        temp.push_back(1);
        result.push_back(temp);
        
        if(numRows == 2)
        {
            return result;
        }
        
        for(int i = 2;i<numRows; i++)
        {
            temp.clear();
            temp.push_back(1);
            for(int j = 1;j<i;j++)
            {
                temp.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            temp.push_back(1);
            result.push_back(temp);
            
        }
    }
};