//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
using ll = long long;
class Solution {
     ll getMaxLCM(ll N) {
        ll ans = N*(N-1);
        ll rem = 2;
        N-=2;
        while(N>1 && rem > 0) {
            if(__gcd(ans,(ll)N) == 1) ans *= N, --rem;
            --N;
        }
        return ans;
    }
  public:
    long long maxGcd(int N) {
       return max(getMaxLCM(N), getMaxLCM(N-1)) ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends