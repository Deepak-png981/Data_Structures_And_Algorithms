class Solution {
public:
    double average(vector<int>& arr) {
        //nlogn
        // if(arr.size() <= 2)
        //     return 0;
        // sort(arr.begin() , arr.end());
        // int n = arr.size();
        // double sum = 0;
        // for(int i = 1; i<n-1; i++){
        //     sum += arr[i];
        // }
        // return (sum/(n-2));
        
        
        //o(n)
        if(arr.size() <= 2)
            return 0;
        int mx = INT_MIN , mn = INT_MAX;
        int n = arr.size();
        double sum = 0.00000;
        for(int i = 0; i<n; i++){
            mx = max(mx , arr[i]);
            mn = min(mn , arr[i]);
            sum += arr[i];
        }
        return (sum - (mx + mn))/(n-2);
        
    }
};