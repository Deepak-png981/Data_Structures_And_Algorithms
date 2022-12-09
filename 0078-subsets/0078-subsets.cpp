class Solution {
public:
    vector<vector<int>> helper(vector<int>&nums , int i){
        if(i == nums.size())
            return {{}};
        vector<vector<int>> partialans = helper(nums , i+1);
        vector<vector<int>> ans;
        for(vector<int>x : partialans){
            ans.push_back(x);
        }
        for(vector<int>x : partialans){
            x.push_back(nums[i]);
            ans.push_back(x);
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums , 0);
    }
};