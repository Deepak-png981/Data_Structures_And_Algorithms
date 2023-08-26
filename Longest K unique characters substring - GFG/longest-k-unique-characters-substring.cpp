//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
      int longestKSubstr(string s, int k) {
     int n=s.length();
            
            vector<int> cnt(26, 0);
            
            int i=0, j=0, diff=0;
            int ans = -1;
            
            while(j<n){
                if(cnt[s[j]-'a']==0){
                    
                    if(diff == k){
                        cnt[s[i]-'a']--;
                        if(cnt[s[i]-'a'] == 0){
                            diff--;
                        }
                        i++;
                    }else{
                        diff++;
                        cnt[s[j]-'a']++;
                        j++;
                    }
                }else{
                    cnt[s[j]-'a']++;
                    j++;
                }
                
                if(diff == k){
                    ans = max(ans, j-i);
                }
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends