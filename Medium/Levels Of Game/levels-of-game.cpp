//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

int dp[801][801];
class Solution {
public:
    int k = 0;
    int axLevel(int h, int m) {
        if (h <= 0 || m <= 0) return 0;
        if (dp[h][m]!=-1) return dp[h][m];
        if (k % 2 == 0) {
            ++k;
            return dp[h][m] = 1 + axLevel(h + 3, m + 2);
        }
        if (k % 2 == 1) {
            if (h > 20 && m > 10) {
                ++k;
                int x = axLevel(h - 20, m + 5);
                int y = axLevel(h - 5, m - 10);
                return dp[h][m] = 1 + max(x, y);
            }

            if (h > 20 && m <= 10) {
                ++k;
                int x = axLevel(h - 20, m + 5);
                return dp[h][m] = 1 + x;
            }

            if ((h > 5 && h < 20 && m > 10) || (h == 20 && m > 10))  {
                ++k;
                int y = axLevel(h - 5, m - 10);
                return dp[h][m] = 1 + y;
            }
            
            if ((h == 20 && m <= 10) || (h > 5 && h < 20 && m <= 10) || (h <= 5)) {
                --k;  // Undo the increment for the current level
                return dp[h][m] = 0;
            }
        }
    }
    int maxLevel(int h, int m){
        memset(dp,-1, sizeof(dp));
        int ans = axLevel(h,m);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends