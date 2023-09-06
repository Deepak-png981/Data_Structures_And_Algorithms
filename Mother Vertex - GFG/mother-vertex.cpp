//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    void dfsHelper(int u , vector<int>adj[] , vector<bool>&visited){
        visited[u] = true;
        for(auto it : adj[u]){
            if(!visited[it]){
                dfsHelper(it , adj , visited);
            }
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool>visited(V , false);
	    int v = -1;
	    for(int i = 0; i<V; i++){
	        if(!visited[i]){
	            dfsHelper(i , adj , visited);
	            v = i;
	        }
	    }
	    fill(visited.begin() , visited.end() , false);
	    dfsHelper(v , adj , visited);
	    for(auto it : visited){
	        if(!it)
	            return -1;
	    }
	    return v;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends