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
private:
    int f(vector<int>&cost , int n , vector<int>&dp){
        if(n == 0 or n == 1)
            return cost[n];
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = cost[n]  + min(f(cost , n - 1,dp) , f(cost , n - 2,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1 , -1);
        int ans = min(f(cost , n - 1 , dp) , f(cost , n - 2 , dp));
        return ans;
    }
};