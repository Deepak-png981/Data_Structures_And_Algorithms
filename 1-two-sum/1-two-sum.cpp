class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int , int>map;
        for(int i = 0; i<n; i++){
            int tofind = target - nums[i];
            if(map.find(tofind) != map.end()){
                ans.push_back(i);
                ans.push_back(map[tofind]);
                return ans;
            }
            else{
                map[nums[i]] = i;
            }
        }
        return ans;
    }
};