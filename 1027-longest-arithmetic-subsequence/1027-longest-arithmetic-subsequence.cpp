class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
       int i,n=arr.size(),j,ans=0;
        vector<vector<int>> dp(1001,vector<int>(n,1));
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int diff=500+arr[i]-arr[j];
                dp[diff][j]=dp[diff][i]+1;
                ans=max(ans,dp[diff][j]);
                
            }
        }
        return ans;     
    }
};