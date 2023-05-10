//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
         int count = 0;
        int leftMax = A[0];
        vector<int> rightMins(N);
        rightMins[N-1] = A[N-1];
        for (int i = N-2; i >= 0; i--) {
            rightMins[i] = min(rightMins[i+1], A[i]);
        }
        for (int i = 1; i < N; i++) {
            leftMax = max(leftMax, A[i-1]);
            if (leftMax + rightMins[i] >= K) {
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends