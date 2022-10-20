//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int row , int col ,vector<vector<int>>&vis,vector<vector<char>>& grid ){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int ,int>>q;
        q.push({row , col});
        while(!q.empty()){
            pair<int, int>frontN = q.front();
            q.pop();
            int rowQ = frontN.first;
            int colQ = frontN.second;
            //now we need to traverse in the neighbours and mark it if its a land
            for(int nrow = -1 ; nrow <=1; nrow++){
                for(int ncol = -1; ncol <= 1; ncol++){
                    int newrow = rowQ + nrow;
                    int newcol = colQ + ncol;
                    if(newrow >= 0 and newrow < n and newcol >=0 and newcol<m 
                    and grid[newrow][newcol] == '1' and !vis[newrow][newcol]){
                        vis[newrow][newcol] = 1;
                        q.push({newrow , newcol});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(n , vector<int>(m,0));
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j <m; j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    count++;
                    bfs(i , j , vis , grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends