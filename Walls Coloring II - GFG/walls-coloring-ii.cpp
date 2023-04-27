//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
       int n = costs.size();
        int k = costs[0].size();
        
        if(k <= 1 && n > 1)
            return -1;
        else if(k == 1 && n == 1)
            return costs[0][0];
        int min1 = 1e5 + 2, min2 = 1e5 + 2;
        for(int i = 0; i < k; i++)
        {
            if(min1 == 1e5 + 2)
                min1 = costs[0][i];
            else if(costs[0][i] <= min1)
            {
                min2 = min1;
                min1 = costs[0][i];
            }
            else if(costs[0][i] < min2)
            {
                min2 = costs[0][i];
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            int newMin1 = INT_MAX, newMin2 = INT_MAX;
            for(int j = 0; j < k; j++)
            {
                if(costs[i - 1][j] == min1)
                {
                    costs[i][j] += min2;
                }
                else
                {
                    costs[i][j] += min1;
                }
                
                //for setting new minimum and new second minimum for next current row
                if(newMin1 == INT_MAX)
                    newMin1 = costs[i][j];
                    
                else if(costs[i][j] <= newMin1)
                {
                    newMin2 = newMin1;
                    newMin1 = costs[i][j];
                }
                else if(costs[i][j] < newMin2)
                {
                    newMin2 = costs[i][j];
                }
                    
            }
            min1 = newMin1;
            min2 = newMin2;
        }
        return min1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends