//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int mod=1e9+7;
        int prev1=1,prev2=1,res=1;
        if(n<=2)return 1;
        for(int i=3;i<=n;i++){
            res=(prev1+prev2)%mod;
            prev2=prev1;
            prev1=res;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends