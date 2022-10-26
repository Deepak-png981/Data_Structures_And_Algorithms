//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> vis ( n , vector<int>(m , 0));
       queue<pair<int, int>>q;
       for(int i = 0; i<n ; i++){
           for(int j = 0; j<m; j++){
               //first row, first col , last row , last col
               if(i == 0 or j == 0 or i == n-1 or j == m-1){
                   if(grid[i][j] == 1){
                       vis[i][j] = 1;
                       q.push({i , j});
                   }
               }
           }
       }
       int delrow[] = {-1 , 0 , +1 , 0};
       int delcol[] = {0 , +1 , 0 , -1};
       //queue
       while(!q.empty()){
           int row = q.front().first;
           int col = q.front().second;
           q.pop();
           for(int i = 0; i<4; i++){
               int nrow = row + delrow[i];
               int ncol = col + delcol[i];
               if(nrow >= 0 and nrow < n and ncol >= 0 and 
                ncol < m and grid[nrow][ncol] == 1 and !vis[nrow][ncol]){
                    q.push({nrow , ncol});
                    vis[nrow][ncol] = 1;
                }
           }
       }
       //counting
       int count = 0;
       for(int i = 0; i<n ; i++){
           for(int j = 0; j<m; j++){
               if(vis[i][j] == 0 and grid[i][j] == 1)
                    count++;
           }
       }
       return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends