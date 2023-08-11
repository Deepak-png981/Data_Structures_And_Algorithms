class Solution {
private:
    void helper(int index , int target ,vector<int>&arr, vector<int>&ds , vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i<arr.size() ; i++){
            if(i > index and arr[i] == arr[i-1])
                continue;
            if(arr[i] > target)
                break;
            ds.push_back(arr[i]);
            helper(i + 1 , target - arr[i] , arr , ds , ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(candidates.begin() , candidates.end());
        helper(0 , target , candidates , ds , ans);
        return ans;
    }
};