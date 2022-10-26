//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void bfs(int r,int c,vector<vector<int>>& matrix, vector<vector<int>>&vis,vector<pair<int,int>>&ans){
    vis[r][c]=1;
     int m=matrix.size();
    int n=matrix[0].size();
    queue<pair<int,int>>q;
    q.push({r,c});
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        ans.push_back({r-row,c-col});
        q.pop();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newrow=row+drow[i];
            int newcol=col+dcol[i];
            if(newrow>=0 and newcol>=0 and newrow<m and newcol<n and matrix[newrow][newcol]==1 and !vis[newrow][newcol]){
                q.push({newrow,newcol});
                vis[newrow][newcol]=1;
            }
        }
    }
}
  public:
    int countDistinctIslands(vector<vector<int>>& matrix) {
        // code here
        int m=matrix.size();
    int n=matrix[0].size();
    set<vector<pair<int,int>>>st;
    vector<vector<int>>vis(m,vector<int>(n,0));
    vector<pair<int,int>>ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] and matrix[i][j]==1){
                bfs(i,j,matrix,vis,ans);
                st.insert(ans);
                ans.clear();
            }
        }
    }
    return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends