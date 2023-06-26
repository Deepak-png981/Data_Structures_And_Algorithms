//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
         // code here
        if(n<r) return 0;
        if((n-r)<r) r= n-r;  
        int MOD = 1000000007;
        
        int dp[r+1]; //1 available in every col 
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;  //starting from 1
        for(int i=1; i<=n; i++){
            for(int j= min(r,i); j>0; j--){
                dp[j] = (dp[j] + dp[j-1])%MOD;
            }
        }
        return dp[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends