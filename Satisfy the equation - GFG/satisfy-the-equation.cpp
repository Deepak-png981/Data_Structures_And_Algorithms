//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int arr[], int N) {
       
       for(int i = 0; i<N; i++){
           for(int j = i+1; j<N; j++){
               for(int k = 0; k < N; k++){
                   for(int l = k+1; l<N;l++){
                        if(k == j or k == i or l == i or l == j)
                            continue;
                        if(arr[i] + arr[j] == arr[k] + arr[l]){
                             vector<int>ans;
                             ans.push_back(i);
                             ans.push_back(j);
                             ans.push_back(k);
                             ans.push_back(l);
                             return ans;
                        }
                   }
               }
           }
       }
        vector<int>ans;
       ans.push_back(-1);
                             ans.push_back(-1);
                             ans.push_back(-1);
                             ans.push_back(-1);
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
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends