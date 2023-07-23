//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        // Code here
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i = 0; i<Queries.size(); i++){
            int x1 = Queries[i][0],y1 = Queries[i][1],x2 = Queries[i][2],y2 = Queries[i][3];
            ans[x1][y1]++;
            if(x2+1<n && y2+1<n){
                ans[x2+1][y2+1]++;
            }
            if(y2+1<n){
                ans[x1][y2+1]--;
            }
            if(x2+1<n){
                ans[x2+1][y1]--;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 1; j<n; j++){
                ans[j][i]+=ans[j-1][i];
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 1; j<n; j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends