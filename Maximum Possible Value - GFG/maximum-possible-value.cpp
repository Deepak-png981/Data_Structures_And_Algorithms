//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
         long long len , count , mn = INT_MAX , ans = 0 , sticks = 0;
        for(int i = 0; i< N; i++){
            len = A[i]; // length of the stick
            count = B[i];//frequency
            //to find whether count is odd or not
            if(count & 1 > 0) 
                count = count - 1; //making the freq even
            if(count >= 2){
                mn = min(mn , len); //store min --> jishko baad mein 
                //hataya ja skta hai
            }
            ans += (len * count);   //sum of perimeters
            sticks += count;
        }
        if(sticks%4 != 0){
            ans -= ( 2 * mn);
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
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends