//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int size){
      long long int ans = 0 , pos = 0 , neg = 0;
      while(1){
          while(arr[pos]<= 0 and pos < size){
              pos++;
          }
          while(arr[neg] >= 0 and neg<size){
              neg++;
          }
          if(pos == size or neg == size)
            break;
          int x = min(arr[pos] , -arr[neg]);
          arr[pos] -= x;
          arr[neg] += x;
          ans += x * abs(pos - neg);
      }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends