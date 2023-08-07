//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int size, int n[], int d[])
    {
        int ans=0;
        map<pair<int,int>,int>m;
        for(int i=0;i<size;i++){
            int divide=__gcd(n[i],d[i]);
            if(n[i]==d[i]) continue;
            int up=n[i]/divide;
            int down=d[i]/divide;
            int need_up=down-up;
            if(m[{need_up,down}]) ans+=m[{need_up,down}];
            m[{up,down}]++;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends