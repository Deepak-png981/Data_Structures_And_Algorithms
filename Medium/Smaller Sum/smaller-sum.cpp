//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        //copy create
        vector<int>num(arr.begin() , arr.end());
        //sum
        unsigned long long sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + arr[i];
        }
        //final vector
        vector<long long>result(n , 0);
        sort(arr.begin() , arr.end() , greater<int>());
        unordered_map<int , long long>temp;
        // 3 2 1
        // sum 6
        // 6 - 3 = 3 temp[3] = 3
        // 3 - 2 = 1 temp[2] = 1
        // 1 - 1 = 0 temp[1] = 0
        for(int i = 0; i<n; i++){
            sum = sum - arr[i];
            temp[arr[i]] = sum;
        }
        //num = 1 2 3
        //temp[1] 0
        //temp[2] = 1
        //temp[3] = 3
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