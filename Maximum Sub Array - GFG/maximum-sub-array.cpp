//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int arr[], int n) {
	       pair<int,int> ans{-1,-2};

     int i=0,j=0,curr=0,res=0;

     while(i<n && j<n){

         if(arr[j]>=0){

             curr+=arr[j];

             if(curr>res || (curr==res && j-i+1>ans.second-ans.first+1)){

                 res=curr;

                 ans.first=i;

                 ans.second=j;

             }

             j++;

         }

         else{

             i=++j;

             curr=0;

         }

     }

     if(ans.first<0)

         return {-1};

     vector<int> req(arr+ans.first,arr+ans.second+1);

     return req;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends