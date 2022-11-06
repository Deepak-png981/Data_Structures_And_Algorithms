class Solution {
public:
    vector<vector<int>>ans;
    void helper(int i , vector<int>& cand , int target , vector<int>&res){
        //base case
        if(target == 0){
            ans.push_back(res);
            return ;
        }
        //if the target becomes negative
        if(target<0){
            return;
        }
        //if the have come to end of the array and surely we haven't found out that the value of target == 0
        if(i == cand.size()){
            return;
        }
        //if we are skipping the first element
        helper(i+1 , cand , target , res);
        //if we are considering the first element then
        res.push_back(cand[i]);
        helper(i , cand , target - cand[i] , res);
        res.pop_back(); //backtracking
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        helper(0 , candidates , target , res);
        return ans;
    }
};