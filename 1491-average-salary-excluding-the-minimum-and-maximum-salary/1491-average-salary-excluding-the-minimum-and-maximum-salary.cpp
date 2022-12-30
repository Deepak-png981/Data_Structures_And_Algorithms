class Solution {
public:
    double average(vector<int>& arr) {
        if(arr.size() <= 2)
            return 0;
        sort(arr.begin() , arr.end());
        int n = arr.size();
        double sum = 0;
        for(int i = 1; i<n-1; i++){
            sum += arr[i];
        }
        return (sum/(n-2));
    }
};