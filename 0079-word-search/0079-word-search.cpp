class Solution
{
    public:
        bool exist(vector<vector < char>> &board, string word)
        {
            int n = board.size();
            int m = board[0].size();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (board[i][j] == word[0] and wordExistHelper(board, i, j, word, 0))
                        return true;
            return false;
        }
    private:
        bool wordExistHelper(vector<vector < char>> &board, int i, int j, string word, int pos)
        {
           	//base case
            if (pos == word.length())
            {
                return true;
            }
            if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size())
                return false;
            if (word[pos] != board[i][j])
                return false;
            char temp = board[i][j];
            board[i][j] = '*';
            if (wordExistHelper(board, i + 1, j, word, pos + 1) or 
                wordExistHelper(board, i - 1, j, word, pos + 1) or 
                wordExistHelper(board, i, j + 1, word, pos + 1) or 
                wordExistHelper(board, i, j - 1, word, pos + 1))
                return true;
            board[i][j] = temp;	// backtrace
            return false;
        }
};