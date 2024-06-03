class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int>mp;
        int n = nums.size();
        int count = n/3 + 1;
        vector<int>ans;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == count){
                ans.push_back(nums[i]);
            }
            if(ans.size() == 2)
                return ans;
        }
        return ans;
    }
};