//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
         int size=0 , start=0;
        for(int i=0 ; i<S.length() ; i++)
        {
            /* for odd sizes */
            int left = i , right = i;
            while(left>=0 && right<S.length())
            {
                if(S[left] != S[right]) break;
                left-- ;
                right++ ;
            }
            
            if((right-left-1) > size)
            {
                size = right - left - 1;
                start = left + 1;
            }
            
            /* for even sizes */
            left = i ; right = i+1;
            while(left>=0 && right<S.length())
            {
                if(S[left] != S[right]) break;
                left-- ;
                right++ ;
            }
            
            if((right-left-1) > size)
            {
                size = right - left - 1;
                start = left + 1;
            }
        }
        
        return S.substr(start,size);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends