class Solution {
// private:
//     int f(vector<int>&cost , int n){
//         if(n == 0 or n == 1)
//             return cost[n];
//         int ans = cost[n] + min(f(cost , n-1) , f(cost , n -2));
//         return ans;
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         int ans = min(f(cost , n - 1) , f(cost , n - 2));
//         return ans;
//     }
// private:
//     int f(vector<int>&cost , int n , vector<int>&dp){
//         if(n == 0 or n == 1)
//             return cost[n];
//         if(dp[n] != -1)
//             return dp[n];
//         return dp[n] = cost[n]  + min(f(cost , n - 1,dp) , f(cost , n - 2,dp));
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int>dp(n + 1 , -1);
//         int ans = min(f(cost , n - 1 , dp) , f(cost , n - 2 , dp));
//         return ans;
//     }
   
private:
    int solve(vector<int>&cost , int n){
        vector<int>dp(n+1 , -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        dp[n] = min(dp[n-1] , dp[n-2]);
        return dp[n];
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1 , -1);
        int ans = solve(cost , n);
        return ans;
    }
};