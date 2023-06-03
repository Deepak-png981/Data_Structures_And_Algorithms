class Solution {
private:
    int dfs(int headid ,vector<int>& informTime , unordered_map<int , vector<int>>&adj ){
        int maxtime = 0;
        for(auto it : adj[headid]){
            maxtime = max(maxtime , dfs(it , informTime , adj));
        }
        return informTime[headid] + maxtime;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int , vector<int>>adj;
        for(int i = 0; i<n ; i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID ,informTime , adj );
    }
};