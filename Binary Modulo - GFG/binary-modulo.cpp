//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            long long n=s.length();
            long long sum=0;
            long long base=1;
            long long power=0;
            for(int i=n-1;i>=0;i--){
                if(s[i]=='1')
                {
                    sum=(sum+ base)%m;
                }
                base=(base*2)%m;
            }
            return sum;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends