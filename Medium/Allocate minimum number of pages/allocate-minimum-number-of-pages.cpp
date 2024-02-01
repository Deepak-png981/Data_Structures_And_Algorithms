//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    int isPossible(int arr[] , int n , int m , int mid){
        int studentCount = 1;
        int pageSum = 0;
        for(int i = 0; i<n; i++){
            if(pageSum + arr[i] <= mid){
                pageSum += arr[i];
            }else{
                studentCount++;
                if(studentCount > m or arr[i] > mid){
                    return false;
                }
                pageSum = arr[i]; 
            }
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        int start = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        int end = sum;
        int ans = -1;
        if(m > n)
            return ans;
        int mid = start + (end - start)/2;
        while(start <= end){
            if(isPossible(arr , n , m , mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends