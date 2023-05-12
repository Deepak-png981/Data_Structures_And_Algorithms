//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
            int c=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                c++;
            }
        }
        
        if(c==n)
        {
            return 0; 
        }
        else if(c==0)
        {
            return -1;
        }
        
        
        int i=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                c--;
            }
            else
            {
                break;
            }
        }
        
        
        int j;
        for(j=n-1;j>=0;j--)
        {
            if(arr[j]==0)
            {
                c--;
            }
            else
            {
                break;
            }
        }
        
        bool t=false;
        
        int x=0;
        
        for(int k=i; k<=j; k++)
        {
            if(arr[k]==0)
            {
                if(t)
                {
                    x++;
                }
                
                t=true;
            }
            else 
            {
                t=false;
            }
            
        }
        return c+1-x;
       
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends