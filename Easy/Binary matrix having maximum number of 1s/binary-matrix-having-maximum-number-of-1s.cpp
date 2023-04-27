//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        vector<int> ones;
        for(int i=0;i<N;++i){
            int cnt = 0;
            for(int j=0;j<N;++j){
                if(mat[i][j] == 1) cnt++;
            }
            ones.push_back(cnt);
        }
        
        vector<int> ans;
        int maxCnt = -1,rowNum = -1;
        for(int i=0;i<ones.size();++i){
            if(ones[i] > maxCnt){ 
                maxCnt = ones[i];
                rowNum = i;
            }
        }
        
        ans.push_back(rowNum);
        ans.push_back(maxCnt);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends