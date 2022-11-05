class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            nums[i] = nums[i] * nums[i];
//             16 1 0 3 10
        }
        sort(nums.begin() , nums.end());
        //0 1 3 10 16
        return nums;
    }
};