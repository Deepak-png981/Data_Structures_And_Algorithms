class Solution {
private:
    void helper(int index , vector<int>&ds , vector<vector<int>>&ans ,int target , vector<int>&candidates){
        if(index == candidates.size()){
               if(target == 0){
                   ans.push_back(ds);
               }
            return;                  
        }
        //pick up the element
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            helper(index , ds , ans , target - candidates[index] , candidates);
            ds.pop_back();
        }
        //not picking up the element
        helper(index + 1 , ds , ans , target , candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0 , ds , ans , target , candidates);
        return ans;
        
}
};