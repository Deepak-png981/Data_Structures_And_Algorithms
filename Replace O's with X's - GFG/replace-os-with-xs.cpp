//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
void dfs(int row , int col , vector<vector<int>>&vis , vector<vector<char>>mat,
            int delrow[] , int delcol[]){
    int n = mat.size();
    int m = mat[0].size();
    vis[row][col] = 1;
    for(int i = 0 ; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] 
            and mat[nrow][ncol] == 'O')
        {
            dfs(nrow , ncol , vis , mat , delrow , delcol);
        }
        
    }
}
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        /* approach ye hai ki jo bhi 'O' first ya last row mein aaye
           ya first ya last column mein aaye ushper dfs laga do takie
           hum sare 'O's ko waise hi visite ker ske or ek visited name
           ke vector mein un corner per ane wale sabhi 'O's ki locations 
           ko store kr lenge taake jab final mein hum mat matrix ko trace
           kare to un 'o's ko kuch na kare bakiyo ko change ker de.......
           wuuuuuuuuuuuuuuuuu huuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
         */
        vector<vector<int>> vis( n , vector<int> (m , 0));
        int delrow[] = {-1 , 0 , +1, 0};
        int delcol[] = {0 , +1 , 0 , -1};
         //for first row and last row
         for(int j = 0; j<m; j++){
             //first row
             if(mat[0][j] == 'O' and vis[0][j] == 0){
                dfs(0 , j , vis , mat , delrow , delcol);
             }
             //last row
             if(mat[n-1][j] == 'O' and vis[n-1][j] == 0)
                dfs(n-1 , j , vis , mat , delrow , delcol);
         }
         //for first and last column
        for(int i = 0; i<n; i++){
             //for first col
             if(vis[i][0] == 0 and mat[i][0] == 'O')
                dfs(i , 0 , vis , mat , delrow , delcol);
             if(vis[i][m-1] == 0 and mat[i][m-1] == 'O')
                dfs(i , m-1 , vis ,mat, delrow , delcol);
        }
        //ab replace ker rhe hai bache hue O's ko X se jo boundary se 
        //connected nhi hai
        for(int i = 0; i<n; i++){
            for(int j = 0 ; j<m ; j++){
                if(vis[i][j] == 0 and mat[i][j] == 'O')
                    mat[i][j] = 'X';
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