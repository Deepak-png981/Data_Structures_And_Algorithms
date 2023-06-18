class Solution {
 int mod = 1e9 + 7;
    int DX[4] = {-1, 1, 0, 0};
    int DY[4] = {0, 0, -1, 1};
    
    int func(vector<vector<int>>& grid, vector<vector<int>>& dp, int x, int y, int m, int n) {
        long long seju = 1;
        
        // Check if the result for the current position is already calculated
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
        // Iterate over the neighboring cells
        for (int i = 0; i < 4; i++) {
            int cx = x + DX[i];
            int cy = y + DY[i];
            
            // Check if the neighboring cell is within the grid boundaries and has a greater value
            if (cx >= 0 && cx < m && cy >= 0 && cy < n && grid[x][y] < grid[cx][cy]) {
                seju += func(grid, dp, cx, cy, m, n);
            }
        }
        
        // Store the calculated result in the dp array for future reference
        return dp[x][y] = seju % mod;
    }
    public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Create a dp array to store the intermediate results
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        long long seju = 0;
        
        // Iterate over all cells in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Calculate the number of paths starting from each cell
                seju += func(grid, dp, i, j, m, n);
            }
        }
        
        // Return the total number of paths modulo 10^9 + 7
        return seju % mod;
    }
};