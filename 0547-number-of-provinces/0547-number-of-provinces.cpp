class Solution {
private:
    void dfs(vector<vector<int>>& isConnected , vector<bool>&vis , int node){
        vis[node] = true;
        int n = isConnected.size();
        for(int padhosi = 0; padhosi<n; padhosi++){
            if(isConnected[node][padhosi] == 1 and !vis[padhosi]){
                dfs(isConnected , vis , padhosi);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces =0;
        vector<bool>vis( n, false );
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                provinces++;
                dfs(isConnected , vis , i);
            }
        }
        return provinces;
    }
};