//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 vector<int> v = {1,0,-1,0,1};
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if((!i or !j or i == n-1 or j == m-1) and mat[i][j] == 'O') q.push({i,j});
            
        while(!q.empty()){
            auto b = q.front();q.pop();
            mat[b.first][b.second] = '@';
            for(int i=0;i<4;i++){
                int x = b.first+v[i];
                int y = b.second+v[i+1];
                if(x<0 or y<0 or x == n or y == m or mat[x][y] == 'X' or mat[x][y] == '@') continue;
                q.push({x,y});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O') mat[i][j] = 'X';
                if(mat[i][j] == '@') mat[i][j] = 'O';
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