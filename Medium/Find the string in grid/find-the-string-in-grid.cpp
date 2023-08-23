//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int dx[8] = {-1,-1,0,-1,1,0,1,1};
    int dy[8] = {-1,0,-1,1,-1,1,0,1};
    bool move(int i, int j, int k, int d,string&word,vector<vector<char>>&grid)
    {
        if(k == word.size()) return 1;
        if(i<0 || i==grid.size() || j<0 || j == grid[0].size() || grid[i][j]!=word[k]) return 0;
        
        int x = i+dx[d];
        int y = j+dy[d];
        return move(x,y,k+1,d,word,grid);         
    }
vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
    // Code here an
    vector<vector<int>> ans;
    int n = grid.size(),m=grid[0].size();
 
    for(int i=0;i<n;i++)
        for(int j = 0;j<m;j++)
            for(int d = 0;d<8;d++)
                if(move(i,j,0,d,word,grid))
                {
                    ans.push_back({i,j});
                    break;
                }
    
    return ans;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends