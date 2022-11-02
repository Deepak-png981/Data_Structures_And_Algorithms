class Solution
{
    public:
        void gameOfLife(vector<vector < int>> &board)
        {
            int n = board.size();
            int m = board[0].size();
            vector<vector <int>> copyboard (n , vector<int>(m, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    copyboard[i][j] = board[i][j];
                }
            }
            int delRow[] = { 1,
                1,
                0,
                -1,
                -1,
                -1,
                0,
                1
            };
            int delCol[] = { 0,
                1,
                1,
                1,
                0,
                -1,
                -1,
                -1
            };
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int livecount = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        int newR = i + delRow[k];
                        int newC = j + delCol[k];
                        if (newR >= 0 and newR < n and newC >= 0 and newC < m and                               copyboard[newR][newC] == 1)
                            livecount++;
                    }
                    if (copyboard[i][j] == 0 and livecount == 3)
                        board[i][j] = 1;
                    if (board[i][j] == 1 and(livecount < 2 or livecount > 3))
                        board[i][j] = 0;
                }
            }
        }
};