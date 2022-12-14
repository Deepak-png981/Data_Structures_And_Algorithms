//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int row , int col , int delRow[] , int delCol[] , vector<vector<int>>&ans,
            vector<vector<int>>&image , int initColor , int newColor){
                ans[row][col] = newColor;
                int n = ans.size();
                int m = ans[0].size();
                for(int i = 0; i<4; i++){
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];
                    if(newRow >= 0 and newRow < n and newCol >= 0 and newCol <m and
                        image[newRow][newCol] == initColor and ans[newRow][newCol] != newColor)
                        dfs(newRow , newCol , delRow , delCol , ans , image , initColor , newColor);
                }
            }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, 
                int newColor) {
        // Code here 
        int initColor = image[sr][sc];
        int delRow[] = {-1 , 0 , +1 , 0};
        int delCol[] = { 0 , +1 , 0 , -1};
        vector<vector<int>>ans = image;
        dfs(sr , sc , delRow , delCol , ans , image , initColor , newColor);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends