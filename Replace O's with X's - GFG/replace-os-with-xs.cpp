//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(int row , int col , vector<vector<int>>&vis , vector<vector<char>> mat){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        int dx[] = { -1 , 0 , +1 , 0};
        int dy[] = { 0 , +1 , 0 , -1};
        for(int i = 0; i<4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and 
                vis[nrow][ncol] == 0 and mat[nrow][ncol] == 'O')
                dfs(nrow , ncol , vis , mat);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n , vector<int>(m , 0));
        //first row and last row
        for(int i = 0; i < m; i++){
            if(vis[0][i] == 0 and mat[0][i] == 'O'){
                dfs(0 , i , vis , mat);
            }
            if(vis[n-1][i] == 0 and mat[n-1][i] == 'O')
                dfs( n-1 , i , vis , mat);
        }
        //for first and last col
        for(int i = 0; i<n; i++){
            if(vis[i][0] == 0 and mat[i][0] == 'O')
                dfs(i , 0 , vis , mat);
            if(vis[i][m-1] == 0 and mat[i][m-1] == 'O')
                dfs(i , m-1 , vis , mat);
        }
        //sabhi ko X kerdo except unke jinka visited already 1 hai
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends