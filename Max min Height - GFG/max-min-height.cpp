//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        bool isPossible(int curr,int n,int k,int w,vector <int> a)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]<curr)
                {
                    if(curr-a[i]>k)
                    {
                        return false;
                    }
                    int start=i;
                    int inc=curr-a[i];
                    k-=inc;
                    if(start+w>=n)
                    {
                        start=max(0,n-w);
                    }
                    for(int ind=start;ind<min(n,start+w);ind++)
                    {
                        a[ind]+=inc;
                    }
                }
            }
            return true;
        }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            long long int low=*min_element(a.begin(),a.end()),high=*max_element(a.begin(),a.end())+k;
            long long ans=0;
            while(low<=high)
            {
                long long int middle=(low+high)>>1;
                if(isPossible(middle,n,k,w,a))
                {
                    ans=middle;
                    low=middle+1;
                }
                else
                {
                    high=middle-1;
                }
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
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends