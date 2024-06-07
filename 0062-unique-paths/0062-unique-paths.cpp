class Solution {
private:
    int recur(int i , int j , int n , int m, vector<vector<int>>&dp){
        //if the robot is at the bottom right
        if( i == (n-1) and j == (m-1))
            return 1;
        if( i>=n or j>=m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        else 
            return dp[i][j] = recur(i + 1 , j , n , m,dp) + recur(i , j+1 , n , m,dp);
        
    }
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n , vector<int>(m,-1));
        int count = recur(0 , 0 ,n, m,dp);
        return count;
    }
};