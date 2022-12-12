//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfs(int node , vector<int>&vis ,vector<int> adj[] ){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , vis, adj);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adjm, int V) {
        vector<int>adj[V];
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(adjm[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(V , 0);
        int count = 0;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                count++;
                dfs(i , vis , adj);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends