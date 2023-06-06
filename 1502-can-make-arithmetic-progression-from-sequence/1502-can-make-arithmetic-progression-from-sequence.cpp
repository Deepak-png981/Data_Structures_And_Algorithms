class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        if( n <= 2)
            return true;
        int diff = abs(arr[1] - arr[0]);
        for(int i = 2; i<n; i++){
            if(diff != abs(arr[i] - arr[i-1]))
                    return false;
        }
        return true;
    }
};