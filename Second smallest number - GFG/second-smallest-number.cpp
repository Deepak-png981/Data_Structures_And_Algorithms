//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        if(S == 1 or D == 1 or S >= 9*D){
            return "-1";
        }
        string ans (D , '0');
        int sum = S;
        int last = -1;
        // 1 7 8
        // 0 1 2 ->index
        for(int i = D - 1; i >= 0; i--){
            if(sum > 9){
                ans[i] = '9';
                sum -= 9;
            }
            else if(sum > 0){
                ans[i] = '0' + sum;
                last = i;  
                sum = 0;
            }
            else{
                ans[i] = '0';
            }
        }
        //checking for the zeroth index
        if(ans[0] == '0'){
            ans[0] = '1';
            ans[last] -= 1;
        }
        //last second process
        int LASTsecond = D - 2;
        while(ans[LASTsecond] == '9'){
            LASTsecond--;
        }
        ans[LASTsecond] += 1;
        ans[LASTsecond + 1] -= 1;
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends