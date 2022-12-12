class Solution{
private:
    void tarjan(int curr, int parent, int time, vector<vector<int>>& AdjLis, vector<int>& low, vector<vector<int>> &ans){
        low[curr] = time++;
        for (auto x: AdjLis[curr]){
            if (x==parent)
                continue;
            if (low[x]==0) tarjan(x, curr, time, AdjLis, low, ans);
            low[curr] = min(low[curr], low[x]);
            if (low[x]==time)
                ans.push_back({curr,x});
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // 1. Constructing graph using Adjacency list
        vector<vector<int>> AdjLis(n);
        for (auto x: connections){
            AdjLis[x[0]].push_back(x[1]);
            AdjLis[x[1]].push_back(x[0]);
        }
        // 2. finding critical connections
        vector<vector<int>> ans;
        vector<int> low(n);
        tarjan(0, -1, 1, AdjLis, low, ans);
        return ans;
    }
};