//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 1e9+7;
    long long solve(int n , int sum,vector<int> &dp)
    {
        if(sum > n)
        return 0;
        if(sum == n)
        return 1;
        
        if(dp[sum]!=0)
        return dp[sum];
        
        return dp[sum] = (solve(n,sum+1,dp) + solve(n,sum+2,dp) + solve(n,sum+3,dp))%mod;
        
    }
    long long countWays(int n)
    {
        vector<int> dp(n,0);
        return solve(n,0,dp)%mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends