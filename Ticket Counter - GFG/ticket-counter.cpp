//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int start = 1 , end = N;
        // {1, 2, 3, 4, 5, 6, 7, 8, 9}
        while(end > start){
            start = start + K;
            //start = 7 , end = 6
            if(start > end){
                return end;
            }
            end = end - K;
            //end = 3 , start = 4
            if(start > end){
                return start;
            }
            
        }
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends