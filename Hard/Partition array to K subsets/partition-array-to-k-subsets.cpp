//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
       int dp[1029];
    int getsum;
    bool solve(int arr[],int n,int k,int currsum,int mask,int idx){
        if(currsum==getsum){
            if(k==1)return true;
            else
            return dp[mask]=solve(arr,n,k-1,0,mask,0);
        }
        if(dp[mask]!=-1)return dp[mask];
        for(int i=idx;i<n;i++){
            if((!(mask&(1<<i))) && arr[i]+currsum<=getsum && solve(arr,n,k,arr[i]+currsum,(mask|(1<<i)),i+1))
            return dp[mask]=true;
        }
        return dp[mask]=false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=a[i];
        
        if(sum%k!=0)return false;
        
        memset(dp,-1,sizeof(dp));
        getsum=sum/k;
        return solve(a,n,k,0,0,0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends