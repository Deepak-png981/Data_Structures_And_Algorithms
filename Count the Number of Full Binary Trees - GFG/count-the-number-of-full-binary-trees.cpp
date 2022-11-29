//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    const int mod=1e9+7;

    const int N=1e5+1;

    long long int numoffbt(long long int arr[], int n){

       

        vector<int>dp(N,0);

        int maxm=-1e9,minm=1e9;

        long long ans=0;

        for(int i=0;i<n;i++){

            dp[arr[i]]=1;

            int t=arr[i];

            maxm=max(maxm,t);

            minm=min(minm,t);

        }

        

        for(int i=minm;i<=maxm;i++){

            // dp[i]!=1 means we have evaluate the node

            // so skip 

            if(dp[i]!=1 || dp[i]==0)continue;

            // find factors

            //        16

            //       /  \

            //      8    2

            // if we find 2 and 8 then it will be 2* of it

            // because two permutation possibe

            // there is overlapping sum problem

            // so need to find for 8 again use it;

            for(int j=minm;j*j<=i;j++){

                if(i%j==0 and dp[i/j]!=0 and dp[j]!=0){

                    // factors are 8 and 2

                    if(i/j !=j){

                        // so twice of dp[8]* dp[2]

                        dp[i]+=2*(dp[i/j]*dp[j]);

                    }

                    else{

                        // two permutation possible 

                        // so need of mulptipy twice

                        dp[i]+=dp[j]*dp[j];

                    }

                    dp[i]%=mod;

                }

            }

            ans+=dp[i];

            ans%=mod;

        }

        return ans;

    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends