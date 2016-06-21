class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int res = 0;
        for(int i = 0; i < grid.size(); ++ i)
            for(int j = 0; j < grid[0].size(); ++ j)
                if(grid[i][j] == '1')
                {
                    ++ res;
                    BFS(grid, i, j);
                }
        return res;
    }
private:
    void BFS(vector<vector<char>> &grid, int x, int y)
    {
        queue<pair<int,int>> que;
        que.push(make_pair(x,y));
        while(!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            grid[x][y] = '0';
            que.pop();

            if(x > 0 && grid[x - 1][y] == '1')
            {
                grid[x - 1][y] = '0';
                que.push(make_pair(x - 1,y));
            }    
            
            if(x < grid.size() - 1 && grid[x + 1][y] == '1')
            {
                grid[x + 1][y] = '0';
                que.push(make_pair(x + 1,y));
            }        
            if(y > 0 && grid[x][y - 1] == '1')
            {
                grid[x][y - 1] = '0';
                que.push(make_pair(x,y - 1));
            }        
            if(y < grid[0].size() - 1 && grid[x][y + 1] == '1')
            {
                grid[x][y+1] = '0';
                que.push(make_pair(x,y+1));
            }    
        } 
        
    }
};