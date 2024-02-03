//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool isPossible(int n , int k , vector<int>&arr , int mid){
        int cowCount = 1;
        int lastPos = arr[0];
        for(int i = 0; i<n; i++){
            if(arr[i] - lastPos >= mid){
                cowCount++;
                if(cowCount == k)
                    return true;
                lastPos = arr[i];
            }
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin() , stalls.end());
        int start = 0;
        int end = stalls[n-1];
        int ans = -1;
        int mid = start + (end - start)/2;
        while(start <= end){
            if(isPossible(n , k , stalls , mid)){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends