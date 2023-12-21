//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int>a(N , 1); //distributed one to each child
        int ans = 0; //for the sum
        //forward 
        for(int i = 0; i<N; i++){
            if(ratings[i] > ratings[i-1]){
                a[i] = a[i-1] + 1;
            }
        }
        //backward  
        for(int i = N-2; i>=0; i--){
            if(ratings[i] > ratings[i+1] and a[i] <= a[i+1]){
                a[i] = a[i+1] + 1;
            }
        }
        //sum
        for(int i = 0; i<N; i++){
            ans += a[i];
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

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends