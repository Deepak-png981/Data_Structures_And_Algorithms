class Solution {
public:
    int trap(vector<int>& arr) {
       //brute force
        int n = arr.size();
        int ans = 0;
        int prefix[n] , suffix[n];
        //calculating prefix[i]
        prefix[0] = arr[0];
        for(int i = 1; i<n; i++){
            prefix[i] = max(prefix[i-1] , arr[i]);
        }
        //calculating suffix[i]
        suffix[n-1] = arr[n-1];
        for(int i = n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1] , arr[i]);
        }
        //final step
        for(int i = 0; i<n; i++){
            ans += min(prefix[i] , suffix[i]) - arr[i];
        }
        return ans;
    }
};