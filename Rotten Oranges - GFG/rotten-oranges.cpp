//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int fresh=0;
        queue<pair<pair<int , int> , int> >q; // ({{row , col} , time})
        for(int i= 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }
        int timeCount = 0;
        int dx[] = {-1 , 0 , +1 , 0};
        int dy[] = {0 , +1 , 0 , -1};
        int freshCount = 0;
        while(!q.empty()){
            int frontRow = q.front().first.first;
            int frontCol = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            timeCount = max(timeCount , tm);
            for(int i = 0; i<4; i++){
                int nrow = frontRow + dx[i];
                int ncol = frontCol + dy[i];
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol <m and
                    vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
                {
                    freshCount++;
                    vis[nrow][ncol] = 2;
                    q.push({{nrow , ncol} , tm + 1});
                }
            }
        }
        if(freshCount != fresh)
            return -1;
        
        return timeCount;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends