class Solution {
public:
     vector<vector<int>>res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        solve(nums,0,temp);
        return res;
    }
    void solve(vector<int>&nums,int idx,vector<int>temp){
        if(idx == nums.size()){
            //checking size of subsequence > 1
            if(temp.size()>1){
                res.push_back(temp);
            }
            return;
        }
        if(!temp.size() || temp[temp.size()-1]<=nums[idx]){
            temp.push_back(nums[idx]);
            solve(nums,idx+1,temp);
            temp.pop_back();
        }
        //ignoring duplicate elements
        if(idx>0 && temp.size()>0 && nums[idx] == temp[temp.size()-1]){
            return;
        }
        solve(nums,idx+1,temp);}
};