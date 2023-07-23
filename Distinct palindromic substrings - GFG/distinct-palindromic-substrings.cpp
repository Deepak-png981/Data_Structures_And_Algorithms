//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int pali(string &s,int i,int j,vector<vector<int> >&dp)
     {
         if(i>j)return 1;
         if(dp[i][j]!=-1)return dp[i][j];
         dp[i][j]=s[i]==s[j] && pali(s,i+1,j-1,dp);
         return dp[i][j];
         
     }
    int palindromeSubStrs(string s) {
        int n=s.length();
        vector<vector<int> >dp(n,vector<int>(n,-1));
        unordered_set<string>st;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(pali(s,i,j,dp))
                
                {
                    st.insert(s.substr(i,j-i+1));
                }
            }
        }
        return st.size();
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends