//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
            int n = matrix.size();    // number of rows
    int m = matrix[0].size(); // number of columns
    int number_ones = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (matrix[row][col] == 1) {
                int count = 0;

                if (row + 1 < n && matrix[row + 1][col] == 0) {
                    count++;
                }
                if (row - 1 >= 0 && matrix[row - 1][col] == 0) {
                    count++;
                }
                if (col - 1 >= 0 && matrix[row][col - 1] == 0) {
                    count++;
                }
                if (col + 1 < m && matrix[row][col + 1] == 0) {
                    count++;
                }
                if (row - 1 >= 0 && col - 1 >= 0 && matrix[row - 1][col - 1] == 0) {
                    count++;
                }
                if (row - 1 >= 0 && col + 1 < m && matrix[row - 1][col + 1] == 0) {
                    count++;
                }
                if (row + 1 < n && col - 1 >= 0 && matrix[row + 1][col - 1] == 0) {
                    count++;
                }
                if (row + 1 < n && col + 1 < m && matrix[row + 1][col + 1] == 0) {
                    count++;
                }

                if (count > 0 && count % 2 == 0) {
                    number_ones++;
                }
            }
        }
    }
    return number_ones;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends