//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int sr , int sc , vector<vector<int>>&ans , int inColor ,
    int newColor, int delRow[] , int delCol[]){
        ans[sr][sc] = newColor;
        int n = ans.size();
        int m = ans[0].size();
        for(int i = 0 ; i<4; i++){
            //for finding the neighbour row and neighbours column
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            //checking if the index is valid or not
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
            ans[nrow][ncol] == inColor and ans[nrow][ncol] != newColor){
                dfs(nrow , ncol , ans , inColor , newColor , delRow , delCol);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, 
    int newColor) {
        // Code here 
        int inColor = image[sr][sc] ;
        vector<vector<int>>ans = image;
        int delRow[] = {-1 , 0 , +1 , 0};
        int delCol[] = {0 , +1 , 0 , -1};
        dfs(sr , sc , ans , inColor , newColor , delRow , delCol);
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