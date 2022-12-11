//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
          int n = nums.size();
        
        if(n < 2 or (n&1) != 0)
            return false;
        unordered_map<int , int>map;
        for(int x : nums){
            if(x % k != 0)
                map[x % k]++;
        }
        for(int i =0; i<n ; i++){
            int x = nums[i]%k;
            if(map.find(k-x) != map.end()){
                map[x]--;
                map[k-x]--;
                if(map[x] == 0)
                    map.erase(x);
                if(map[k-x] == 0)
                    map.erase(k-x);
            }
        }
        return map.size() == 0 ? true : false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends