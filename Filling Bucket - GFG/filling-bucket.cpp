//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  //bahar isliye declare ker rha hoon kyuki stack ke andr itni bdhi memory le
//   nhi payega
  int mod = 1e8;
  public:
    int fillingBucket(int N) {
    
        int a = 1 , b = 2 , c = 0;
        if(N == 1)  return 1;
        if(N==2)    return 2;
        for(int i = 3; i<=N;i++){
            c = (a+b)%mod;
            a = b%mod;
            b = c%mod;
        }
        return c%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends