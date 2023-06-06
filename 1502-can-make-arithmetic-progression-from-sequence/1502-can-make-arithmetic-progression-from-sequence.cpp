class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2){
            return true;
        }
//         45 85 13
        //13 45 85
        sort(arr.begin() , arr.end());
        int diff = arr[1] - arr[0];
        for(int i = 2; i<n; i++){
            if(diff != arr[i] - arr[i-1])
                    return false;
        }
        return true;
    }
};