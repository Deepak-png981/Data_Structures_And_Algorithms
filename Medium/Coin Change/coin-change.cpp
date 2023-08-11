//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
       long long int dp[1001][1001];
    long long int count(int coins[], int n, int sum) {
        for(int i=0;i<n;++i){
             for(int amount=0;amount<=sum;++amount){
                  if(amount==0){
                     dp[i][amount]=1;
                  }else{
      long long int take = (coins[i]>amount)?0: dp[i][amount-coins[i]]; 
      long long int nottake=(i>0)? dp[i-1][amount]:0;
         dp[i][amount]=take+nottake;
               }
           }

        }
         return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends