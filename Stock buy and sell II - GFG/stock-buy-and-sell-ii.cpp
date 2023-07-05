//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
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
     int fun(int &profit, int &diff, int n, const vector<int>& v) {
        
        
        for (int i = 1; i < n; i++) {
            diff = v[i] - v[i-1];
            
            if ( diff > 0) {
                profit += diff;
            }
        }
        return profit;
        
    }
    
    int stockBuyAndSell(int n, vector<int> &prices) {
        int diff = 0;
        int profit = 0;
      int ans=  fun(profit, diff, n, prices);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends