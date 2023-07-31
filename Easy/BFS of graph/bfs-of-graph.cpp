//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
   void solve(int i, vector<int>&ans, vector<int>adj[], int V, vector<int>&visited){
        visited[i]=1;
        queue<int>q;
        q.push(i);
        while(q.empty()==false){
            int curr = q.front();
            ans.push_back(curr);
            
            q.pop();
            for(auto it : adj[curr]){
                if(visited[it]==0){
                    q.push(it);
                    visited[it]=1;
                    
                }
            }
        }
        
        
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>visited(V, 0);
        solve(0, ans, adj, V, visited);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends