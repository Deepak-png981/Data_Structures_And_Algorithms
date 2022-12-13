//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void dfs(int i , int j , 
    vector<vector<int>>& vis, int n , int m , vector<vector<char>>& grid){
        vis[i][j] = 1;
        queue<pair<int , int>> q;
        q.push({i , j});
        while(!q.empty()){
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();
            //ye do forloop lagane pdht hai aatho directions mein jane ke liye
            for(int i = -1 ; i<= 1 ; i++){
                for(int j = -1; j<=1; j++){
                    int newx = frontRow + i;
                    int newy = frontCol + j;
                    if(newx >= 0 and newx < n and newy >= 0 and newy < m
                    and vis[newx][newy] == 0 and grid[newx][newy] == '1'){
                        vis[newx][newy] = 1;
                        q.push({newx , newy});
                    }
                }
            }
        }
        
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>vis (n , vector<int>(m , 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 0 and grid[i][j] == '1') {
                    count++;
                    dfs(i , j, vis , n , m,grid);
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