class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int count[9];
        
        //检测行
        for(int i = 0;i<9;i++)
        {
            for(int n = 0;n<9;n++)
            {
                count[n] = 0;
            }
            for(int j = 0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    count[board[i][j]-'1']++;
                    if(count[board[i][j]-'1']>1)
                    {
                        return false;
                    }
                }
            }
        }
        
        //检测列
        for(int i = 0;i<9;i++)
        {
            for(int n = 0;n<9;n++)
            {
                count[n] = 0;
            }
            for(int j = 0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    count[board[j][i]-'1']++;
                    if(count[board[j][i]-'1']>1)
                    {
                        return false;
                    }
                }
            }
        }
        
        //检测九宫格
        for(int x = 0;x<3;x++)
        {
            for(int y = 0;y<3;y++)
            {
                for(int n = 0;n<9;n++)
                {
                    count[n] = 0;
                }
                for(int i = 0;i<3;i++)
                {
                    for(int j = 0;j<3;j++)
                    {
                        if(board[3*x+i][3*y+j]!='.')
                        {
                            count[board[3*x+i][3*y+j]-'1']++;
                            if(count[board[3*x+i][3*y+j]-'1']>1)
                            {
                                return false;
                            }
                        }
                    }

                }
            }
        }
        
        return true;
    }
};