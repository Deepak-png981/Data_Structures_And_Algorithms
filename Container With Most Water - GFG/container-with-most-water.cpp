//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long arr[], int len)
{
    
    long long area = 0 , left = 0 , right = len - 1;
    for(long long i = 0; i<len; i++){
        area = max( area , min( arr[left] , arr[right] ) * ( right - left ) );
        ( arr[left] > arr[right] ) ? right-- : left++ ;
    }
    return area;
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends