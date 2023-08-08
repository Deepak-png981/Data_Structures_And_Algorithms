class Solution {
private:
    void helper(vector<int>&nums , int i , set<vector<int>>&st , vector<int>res){
        if(i == nums.size()){
            sort(res.begin() , res.end());
            st.insert(res);
            return;
        }
        res.push_back(nums[i]);
        helper(nums , i + 1 , st , res);
        res.pop_back();
        helper(nums , i + 1 , st , res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>res;
        helper(nums , 0 , st , res);
        for(auto it = st.begin(); it != st.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};