//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
       vector<int> dist(N, 1e8);
dist[0] = 0;
for (int i = 0; i < N - 1; i++) {
for (auto it : edges) {
int u = it[0];
int v = it[1];
int wt = it[2];
if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
dist[v] = dist[u] + wt;
}
}
}
// Nth relaxation to check negative cycle
for(int i=0;i<N;i++){
   if(dist[i]==1e8){
       dist[i]=-1;
   }
}
 
return dist;
 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends