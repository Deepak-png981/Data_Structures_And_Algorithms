//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // 3 0 3
        int r[n] = {0} , c[n] = {0};
        int mx = INT_MIN;
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = 0; j<n; j++){
                r[i] += matrix[i][j];
                c[i] += matrix[j][i];
            }
            mx = max(mx , max(r[i] , c[i]));
        }
        int sum = 0;
        
        for(int i = 0; i<n; i++){
            sum += mx - r[i];
            sum += mx - c[i];
        }
        
        return sum/2;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends