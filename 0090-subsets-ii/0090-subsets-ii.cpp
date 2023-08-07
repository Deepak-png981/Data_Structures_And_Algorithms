class Solution {
private:
    void fun(vector<int>&nums , int index , vector<int>ds , set<vector<int>>&st){
        if(index == nums.size()){
            sort(ds.begin() , ds.end());
            st.insert(ds);
            return;
        }
        fun(nums , index + 1 , ds , st);
        ds.push_back(nums[index]);
        fun(nums , index + 1 , ds , st);
        
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>ds;
        fun(nums , 0 , ds , st);
        for(auto it = st.begin() ; it != st.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};