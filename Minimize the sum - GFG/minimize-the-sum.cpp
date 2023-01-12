//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        multiset<int> ms(arr.begin(), arr.end());
        int sum1=0, sum2=0;
        while(ms.size()!=1){
            int val1=*ms.begin();
            auto it=ms.begin(); 
            it++;
            int val2=*it;
            ms.erase(ms.begin());
            ms.erase(ms.begin());
            sum1 += (val1+val2);
            sum2=(val1+val2);
            ms.insert(sum2);
        }
        return sum1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends