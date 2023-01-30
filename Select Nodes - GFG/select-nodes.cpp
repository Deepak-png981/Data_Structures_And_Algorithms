//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int count=0;
     bool dfs(vector<vector<int>>&adj,int par,vector<int>&vis){
         vis[par]=1;
         bool flag=false;
         for(auto x:adj[par]){
             if(!vis[x] and !dfs(adj,x,vis))flag=true;
         }
         count+=flag;
         return flag;
     }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
      
        vector<vector<int>>adj(N+1);
        vector<int>vis(N+1,0);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
         dfs(adj,1,vis);
        return count;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends