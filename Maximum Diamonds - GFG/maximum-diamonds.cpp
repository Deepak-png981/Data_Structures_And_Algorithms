//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    // code here
        // N = 5, K = 3
        // A[] = {2, 1, 7, 4, 2}
        // 7 4 2 2 1
        //k1 -> 7
        //7 4 2 2 1 -> 3 4 2 2 1
        //4 3 2 2 1
        //k2-> 4
        //4 3 2 2 1 -> 2 3 2 2 1
        //3 2 2 2 1
        //k3->3
        
  public:
    long long maxDiamonds(int arr[], int n, int k) {
        priority_queue<int>pq(arr , arr + n);
        long long ans = 0;
        while(k--){
            int top = pq.top();
            pq.pop();
            ans += top;
            pq.push(top/2);
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
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends