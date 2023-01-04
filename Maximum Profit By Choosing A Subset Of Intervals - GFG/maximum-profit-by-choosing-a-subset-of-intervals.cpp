//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        //sorting the array on the basis of ending point
        //                                          Annonymus function 
        sort(intervals.begin() , intervals.end() , []( vector<int>&a , vector<int>&b ){
            return a[1] != b[1] ? a[1] < b[1] : ( a[0] != b[0] ? a[0] < b[0] : a[2] > b[2]) ;
        });
        //creating a map
        map<int , int>profits;
        //lower bound : x or greater than x
        //upper bound : greater than x
        //prev(upper bound) : value less than x
        profits[-1] = 0;
        for(auto &it : intervals){
            int start = it[0] , end = it[1] , profit = it[2];
            int maxprofit = max( (prev( profits.upper_bound(end) ))->second , 
                            (prev( profits.upper_bound(start) ))->second+ profit ) ;
            profits[end] = maxprofit;
        }
        return profits.rbegin()->second;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends