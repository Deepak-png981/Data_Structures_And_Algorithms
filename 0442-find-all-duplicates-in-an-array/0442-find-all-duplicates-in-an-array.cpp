class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[abs(nums[i]) - 1] < 0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i]) - 1] *= -1;
        }
        return ans;
    }
};