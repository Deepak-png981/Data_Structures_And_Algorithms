//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        // sort kerdo phle
        sort(intervals.begin() , intervals.end());
        // size calculation
        int n = intervals.size();
        //declare an ans two D vector taki return ker ske
        vector<vector<int>>ans;
        //push kerdo first ko further comparison ke liye
        ans.push_back(intervals[0]);
        // start 1 se ker rhe hai kuki zero index phle hi inserted hai
        for(int i = 1; i<n; i++){
            //main logic
            if(ans[ans.size() - 1][1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else 
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1] , intervals[i][1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends