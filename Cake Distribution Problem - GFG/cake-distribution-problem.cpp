//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
      bool help(int mid,vector<int>&v,int k){
        int sum=0;
        for(int i=0;i<v.size();i++){
            if(sum+v[i]<mid){
                sum+=v[i];
            }
            else{
                sum=0;
                k--;
            }
        }
        return k<0;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here.
          int lo=0;int hi=1e9;
          while(hi-lo>1){
              int mid=(hi+lo)/2;
              if(help(mid,sweetness,K)) lo=mid;
              else hi=mid-1;
          }
          if(help(hi,sweetness,K)) return hi;
          if(help(lo,sweetness,K)) return lo;
          return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends