class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        unordered_set<char>rows[n];
        unordered_set<char>cols[n];
        unordered_set<char>boxes[n];
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                int value = board[row][col];
                if(value == '.')
                    continue;
                int boardIndex = (row/3) * 3 + (col/3);
                if(rows[row].count(value) or cols[col].count(value) or boxes[boardIndex].count(value))
                    return false;
                rows[row].insert(value);
                cols[col].insert(value);
                boxes[boardIndex].insert(value);
            }
        }
        return true;
    }
};