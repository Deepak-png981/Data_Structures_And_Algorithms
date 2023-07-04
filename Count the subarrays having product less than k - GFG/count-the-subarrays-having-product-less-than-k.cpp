//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
     int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count=0;
        for(int i=0;i<n;i++){
       long long  temp=1LL;
        int j=i;
        while(j<n){
            temp*=a[j];
            if(temp<k)count++;
            j++;
            if(temp>=k)break;
        }
        
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends