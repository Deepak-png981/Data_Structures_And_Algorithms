//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int n, int k) {
        // code here
        vector<int>r(k , 0);
        for(int i = 0; i<n ; i++){
            r[arr[i]%k]++;
        }
        int ans = 0;
        for(int i = 0; i<=k/2; i++){
            if(i == 0 or i == k-i){
                if(r[i] != 0)
                    ans++;
            }else{
                ans += max(r[i] , r[k-i]);
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
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends