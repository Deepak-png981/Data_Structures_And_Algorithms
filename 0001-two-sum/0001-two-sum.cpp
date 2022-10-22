class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> map;
        int n=nums.size();
        for(int i= 0; i<n ; i++){
            map[nums[i]] = i;
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(map.count(target - nums[i]) and i != map[target - nums[i]]){
                ans.push_back(i);
                ans.push_back(map[target - nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};