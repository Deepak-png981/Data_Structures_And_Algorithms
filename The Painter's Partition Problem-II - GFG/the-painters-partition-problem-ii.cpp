//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    bool isPossible(int a[] , int n , int m , long long mid){
        unsigned int  totalPages = 0;
        unsigned int noOfStudent = 1;
        for(unsigned int i = 0; i<n; i++){
            if(totalPages + a[i] <= mid){
                totalPages += a[i];
            }else{
                noOfStudent++;
                if(noOfStudent > m or a[i] > mid )
                    return false;
                totalPages = a[i];
            }
        }
        return true;
    }
  public:
    long long minTime(int a[], int n, int m)
    {
        unsigned int s = 0;
        unsigned int sum = 0;
        for(long long int i = 0; i<n; i++){
            sum += a[i];
        }
        unsigned int e = sum;
        unsigned int mid = s + ( e - s )/2;
        unsigned int ans = -1;
        // if(n<m)
        //     return ans;
        while(s <= e){
            if(isPossible(a , n , m , mid)){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
            mid = s + ( e - s )/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends