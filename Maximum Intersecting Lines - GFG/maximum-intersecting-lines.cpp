//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int , int>mp;
        for(int i = 0; i<lines.size(); i++){
            int start = lines[i][0];
            int end = lines[i][1];
            mp[start]++;
            mp[end+1]--;
        }
        int mini = 1;
        int prefix = 0;
        for(auto it : mp){
            prefix += it.second;
            mini = max(mini , prefix);
        }
        return mini;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends