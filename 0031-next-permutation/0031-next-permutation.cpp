class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        next_permutation(nums.begin() , nums.end());
        // next_permutation(nums , nums + n );
        
    }
};