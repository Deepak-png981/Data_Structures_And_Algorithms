//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        int mx = INT_MIN;
        for(auto it : arr){
            mx = max(it , mx);
        }
        unordered_map<int , int>mp;
        vector<bool>factor(mx+1 , false);
        for(int i = 0; i<N; i++){
            if(mp.count(arr[i])){
                mp[arr[i]]++;
                continue;
            }
            for(int j = 2*arr[i]; j<=mx; j += arr[i])
                factor[j] = true;
            mp[arr[i]]++;
        }
        int ans = 0;
        for(auto it : arr){
            if(factor[it] == true  or mp[it] > 1)
                ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends