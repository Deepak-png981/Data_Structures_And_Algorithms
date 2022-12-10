class Solution {
public:
    void recursion(vector<int>&nums , vector<int>&ds , int map[] , vector<vector<int>>&ans){
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size() ;i++){
            if(!map[i]){
                ds.push_back(nums[i]);
                map[i] = 1;
                recursion(nums , ds, map , ans);
                map[i] = 0;
                ds.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        int n= nums.size();
        int map[n];
        for(int i = 0; i<n; i++)    map[i] = 0;
        vector<vector<int>>ans;
        recursion(nums, ds , map , ans);
        return ans;
    }
};