//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        bool prime[10000]={0};
        for(int i = 2;i<=9999;i++){
            if(prime[i]==0)
            for(int j = i+i;j<=9999;j+=i)
            prime[j] = 1;
        }
        queue<int>pq;
        if(Num1>Num2) swap(Num1,Num2);
        pq.push(Num1);
        int lvl = 0;
        while(pq.size()){
            int n = pq.size();
            // cout<<n<<" ";
            while(n--){
                auto top = pq.front();pq.pop();
                // cout<<top<<" ";
                if(top==Num2) return lvl;
                for(int i = 1;i<=1000;i*=10){
                    int dig = (top/i)%10;
                    for(int k = i!=1000?0:1;k<10;k++){//If thousands place, cant swap with 0
                        int neww = top + (k-dig)*i;
                        if(prime[neww]==0){
                            pq.push(neww);
                            prime[neww] = 1;
                        }
                    }
                }
            }
            // cout<<"\n"<<endl;
            lvl++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends