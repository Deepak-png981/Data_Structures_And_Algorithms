//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int splitArray(int a[] ,int n, int k) {
        // code here
        int mx=0,sum=0;
        for(int i=0;i<n;i++){mx=max(mx,a[i]);sum+=a[i];}
       int lo=mx,hi=sum;
       int mid,ans;//mid represent the maximum subarray sum
       while(lo<=hi){
           mid=lo+(hi-lo)/2;
           int cnt=1,cur=0;
           for(int i=0;i<n;i++){
               if((cur+a[i])>mid){
                   cur=a[i];
                   cnt++;
               }
               else cur+=a[i];
           }
           if(cnt<=k){
               ans=mid;
               hi=mid-1;
           }
           else lo=mid+1;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends