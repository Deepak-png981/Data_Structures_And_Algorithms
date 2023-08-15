//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
   int maxOnes(int a[], int n)
    {
        int flips = 0;
        int temp = 0;
        
        for(int i=0; i<n; i++)
        {
            a[i]==1 ? temp-- : temp++;
            
            if(temp<0)
            {
                temp=0;
            }
            else
            {
                flips = max(flips, temp);
            }
        }
        
        flips = max(flips, temp);
        
        int ans = flips;
        for(int i=0; i<n; i++)
        {
            if(a[i]==1)ans++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends