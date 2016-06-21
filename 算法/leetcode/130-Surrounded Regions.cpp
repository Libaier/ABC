// 130. Surrounded Regions My Submissions QuestionEditorial Solution
// Total Accepted: 55532 Total Submissions: 339091 Difficulty: Medium
// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

// 130. Surrounded Regions My Submissions QuestionEditorial Solution
// Total Accepted: 55532 Total Submissions: 339091 Difficulty: Medium
// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

class Solution {
public:
	void solve(vector<vector<char>>& board) {

		int M = board.size();
		if (2 >= M) return;
		int N = board[0].size();
		if (2 >= N) return;
		//up
		for (int i = 0; i < N; ++i)
		{
			if ('O' == board[0][i])
			{
				dfs(board, 0, i);
			}
		}

		//right
		for (int i = 1; i < M; ++i)
		{
			if ('O' == board[i][N - 1])
			{
				dfs(board, i, N - 1);
			}
		}

		//down
		for (int i = N - 2; i >= 0; i--)
		{
			if ('O' == board[M - 1][i])
			{
				dfs(board, M - 1, i);
			}
		}

		//left
		for (int i = M - 2; i > 0; i--)
		{
			if ('O' == board[i][0])
			{

				dfs(board, i, 0);
			}
		}

		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}

				if (board[i][j] == '1')
				{
					board[i][j] = 'O';
				}
			}
		}
	}

	void dfs(vector<vector<char>>& board, int x, int y)
	{
		board[x][y] = '1';
		if (x>1 && board[x - 1][y] == 'O')//>1防止栈溢出
		{
			dfs(board, x - 1, y);
		}

		if (y>1 && board[x][y - 1] == 'O')
		{
			dfs(board, x, y - 1);
		}

		if (x<board.size() - 1 && board[x + 1][y] == 'O')
		{
			dfs(board, x + 1, y);
		}

		if (y<board[0].size() - 1 && board[x][y + 1] == 'O')
		{
			dfs(board, x, y + 1);
		}
	}
};
