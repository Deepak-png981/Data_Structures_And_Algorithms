//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int , int>mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]]++;
        }
        int mn = INT_MAX , ans;
        for(auto it : mp){
            if(mn > it.second){
                mn = it.second;
                ans = it.first;
            }else if(mn == it.second and it.first > ans){
                ans = it.first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends