//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int h[], int n) {
        // 5 5 10 10 2 1 7 8 9
        //op : 5
        vector<int>arr;
        for(int i = 0; i<n; i++){
            int index = lower_bound(arr.begin() , arr.end() , h[i]) - 
            arr.begin();
            if(index == arr.size())
                arr.push_back(h[i]);
            else
                arr[index] = h[i];
        }
        return n - arr.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends