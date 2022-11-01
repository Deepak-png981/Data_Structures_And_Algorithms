class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans(m);
        for(int i = 0; i<m; i++)
            ans[i] = i;
        vector<int>vis(m , 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[j] != -1){
                    int ind = ans[j];
                    if(grid[i][ind] == 1){
                        if(ind == m-1 or grid[i][ind+1] == -1){
                            vis[j] = -1;
                            ans[j] = -1;
                        }else{
                            ans[j] = ind+1;
                        }                        
                    }else{
                        if(ind == 0 or grid[i][ind - 1] == 1){
                            ans[j] = -1;
                            vis[j] = -1;
                        }else{
                            ans[j] = ind - 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};