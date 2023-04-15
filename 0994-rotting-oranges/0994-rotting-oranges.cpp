class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int row = grid.size();
        int col = grid[0].size();
        queue <pair<pair<int, int>, int>> q;
        int cntFresh = 0;
        int visited[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }
        int time = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        int cnt = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col &&
                    visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                        q.push({{nrow, ncol}, t + 1});
                        visited[nrow][ncol] = 2;
                        cnt++;
                    }
            }
        }
        if (cntFresh != cnt)
            return -1;
        return time;    
        
    }
};