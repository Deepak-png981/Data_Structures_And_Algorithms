class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        vector<bool> vis(n,false);
        vector<int> adj[n]; // Adjacency list
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if(src == des){
            return true;
        }
        queue<int>q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
             if(front == des)
                    return true;
            for(auto it : adj[front]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }                   
            }
        }
        return false;
        
    }
};