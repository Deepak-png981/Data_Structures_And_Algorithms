//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int>num(arr.begin() , arr.end());
        unsigned long long sum = 0;
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
        }
        vector<long long>result(n , 0);
        //sorting in desc order
        sort(arr.begin() , arr.end() , greater<int>());
        unordered_map<int , long long>temp;
        for(int i = 0; i<n; i++){
            sum = sum - arr[i];
            temp[arr[i]] = sum;
        }
        for(int i = 0; i<n; i++){
            result[i] = temp[num[i]];
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends