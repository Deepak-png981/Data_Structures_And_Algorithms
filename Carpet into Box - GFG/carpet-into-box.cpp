//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
          int ans =0;

        while(max(A,B)>max(C,D)){

            if(A>B){

                A = A/2;

                ans++;

            }

            else{

                B =B/2;

                ans++;

            }

        }

        while(min(A,B)>min(C,D)){

            if(A<B){

                A/=2;

                ans++;

            }

            else{

                B/=2;

                ans++;

            }

        }

        return ans ;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends