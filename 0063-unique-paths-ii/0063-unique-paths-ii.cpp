class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>ans(n , vector<int>(m , 0));
        for(int i = 0; i<n; i++){
            if(arr[i][0] == 0)
                ans[i][0] = 1;
            else
                break;
        }
        for(int j = 0; j<m; j++){
            if(arr[0][j] == 0)
                ans[0][j] = 1;
            else
                break;
        }
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(arr[i][j] == 0)
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        return ans[n-1][m-1];
    }
};