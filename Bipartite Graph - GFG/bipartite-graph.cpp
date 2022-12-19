//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dfs(int start , int V , vector<int>adj[] , int color[] ){
        color[start] = 0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it : adj[front]){
                //nodes ka color same nhi hai to aleternate colors lagate ja rhe hai bro
                if(color[it] == -1){
                    color[it] = !color[front];
                    q.push(it);
                }
                else if(color[it] == color[front]){
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i = 0; i<V; i++){
	        color[i] = -1;
	    }
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1){
	            if(dfs(i , V, adj , color) == false)
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