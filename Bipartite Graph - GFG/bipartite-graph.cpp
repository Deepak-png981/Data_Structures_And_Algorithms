//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool checkComponent(int start , int v, vector<int>adj[] , vector<int>&color){
        queue<int>q;
	    q.push(start);
	    
	    color[start] = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        
	        for(auto it : adj[node]){
	            //if the adjacent node is not yet coloured I am going 
	            //to give it a color
	            if(color[it] == -1)
	            {
	                color[it] = 1 - color[node];
	                q.push(it);
	            }
	            //if the color of adjacent node and the node
	            //is same then it is not a bipartite graph
	            else if(color[it] == color[node]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int v, vector<int>adj[]){
	    vector<int>color(v , 0);
	    for(int i = 0; i<v; i++)
	        color[i] = -1;
	    for(int i = 0; i<v; i++){
	        if(color[i] == -1){
	            if(checkComponent(i , v , adj , color) == false)
	            return false;
	        }
	    }
	    return true; 
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends