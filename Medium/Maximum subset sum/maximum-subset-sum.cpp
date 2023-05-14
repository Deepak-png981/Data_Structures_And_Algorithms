//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int n,vector<int>&A,int i,vector<int>&dp)
  {
      if(i>=n)
      return 0;
      if(dp[i]!=-1)
      return dp[i];
      long long include=A[i]+solve(n,A,i+1,dp);
      long long exclude=0;
      if((i+1)<n)
      {
          exclude=A[i+1]+solve(n,A,i+2,dp);
      }
      return dp[i]=max(include,exclude);
  }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<int>dp(N+1,-1);
        return solve(N,A,0,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends