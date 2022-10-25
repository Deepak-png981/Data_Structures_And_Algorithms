//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	   // TC : NxM
	   // SC : NxM
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> vis ( n , vector<int> (m , 0));
	    vector<vector<int>> dist( n , vector<int>(m , 0));
	    //queue jo co-ordinates store karegi or steps
	    queue< pair< pair<int , int> , int > > q;
	    //queue mein unko push ker rhe hai jinki current value 1 hai
	    for(int i = 0; i<n; i++){
	        for(int  j = 0; j<m; j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = 1;
	                q.push({{i , j} , 0});
	            }
	            else{
	                vis[i][j] = 0;
	            }
	        }
	    }
	    //delta rows and cols array to traverse to U , R, D, L
	    int delRow[] = { -1  , 0 , +1 , 0 };
	    int delCol[] = { 0 , +1 , 0 , -1 };
	   // queue mein travel ker rhe hai
	   while(!q.empty()){
	       int row = q.front().first.first;
	       int col = q.front().first.second;
	       int steps = q.front().second;
	       q.pop();
	       dist[row][col] = steps;
	       for(int i = 0; i<4; i++){
	           int nrow = row + delRow[i];
	           int ncol = col + delCol[i];
	           if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and
	            vis[nrow][ncol] == 0){
	                vis[nrow][ncol] = 1;
	                q.push({{nrow , ncol} , steps + 1});
	            }
	       }
	   }
	   return dist;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends