//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
   int longestPalinSubseq(string s) {
        //code here
        string t = s;
        int n = s.size();
        int l = 0;
        int h = n-1;
        while(l<=h) swap(s[l++],s[h--]);
        vector<int>last(n+1,0);
        vector<int>present(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1])
                present[j] = 1+last[j-1];
                else
                present[j] = max(last[j],present[j-1]);
            }
            last = present;
        }
        return present[n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends