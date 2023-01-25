//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
         string ans="";

      int res=0;

      int n=s.length();

      ans.push_back(s[0]);

      for(int i=1;i<n;i++){

          if(s.substr(i,ans.length())==ans){

              int k=ans.length();

              res=max(res,k);

          }

          ans.push_back(s[i]);

      }

      if(res>0)

      return n-res+1;

      else

 

      return n-res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends