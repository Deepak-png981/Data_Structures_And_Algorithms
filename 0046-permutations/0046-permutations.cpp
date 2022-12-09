class Solution {
public:
    vector<vector<int>>result;
    void helper(vector<int>& nums , int i , int n){
        if(i == n){
            result.push_back(nums);
            return ;
        }
        for(int j = i; j<=n; j++){
            swap(nums[j] , nums[i]);
            helper(nums , i + 1 , n);
            swap(nums[j] , nums[i]);
            
        } return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums , 0 , nums.size() - 1);
        return result;
    }
};