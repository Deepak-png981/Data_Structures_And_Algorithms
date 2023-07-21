class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]] = i;
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(mp.count(target - nums[i]) and i != mp[target - nums[i]]){
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};