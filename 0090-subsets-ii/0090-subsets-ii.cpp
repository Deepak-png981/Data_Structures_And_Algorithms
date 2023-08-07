class Solution {
private:
    void fun(vector<int>&nums , int i , vector<int>ds , set<vector<int>>&st){
        if(i == nums.size()){
            sort(ds.begin() , ds.end());
            st.insert(ds);
            return;
        }
        ds.push_back(nums[i]);
        fun(nums , i + 1 , ds , st);
        ds.pop_back();
        fun(nums , i + 1 , ds , st);
        
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        set<vector<int>>st;
        vector<int>ds;
        fun(nums , 0 , ds , st);
        for(auto it = st.begin() ; it != st.end(); it++){
            res.push_back(*it);
        }
        return res;
    }
};