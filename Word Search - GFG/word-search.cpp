//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int dx[4] = {0 , -1 , 0 , 1};
    int dy[4] = {1 , 0 , -1 , 0};
    vector<vector<bool>>vis;
    bool dfs(int x , int y , int index , int n , int m , string word , vector<vector<char>>&board){
       if(index == word.length()){
           return true;
       }
       vis[x][y] = 1;
       for(int i = 0; i<4; i++){
           int nx = x + dx[i];
           int ny = y + dy[i];
           if(nx >= 0 and nx < n and ny>=0 and ny <m and board[nx][ny] == word[index] and !vis[nx][ny]){
               bool temp = dfs(nx , ny , index + 1 , n , m , word , board);
               if(temp)
                    return temp;
           }
       }
       vis[x][y] = 0;
       return false;
    }
     
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vis.resize( n , vector<bool>(m , 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(board[i][j] == word[0]){
                    bool ans = dfs(i , j , 1 , n , m , word , board );
                    if(ans == true)
                        return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends