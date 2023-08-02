class Solution {
private:
    vector<vector<int>>ans;
    void helper(vector<int>& nums , int i , int n){
        //base case
        if(i == n){
            ans.push_back(nums);
            return;
        }
        for(int j = i; j<=n; j++){
            swap(nums[j] , nums[i]);
            helper(nums , i+1 , n);
            swap(nums[j] , nums[i]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums , 0 , nums.size()-1);
        return ans;
    }
};