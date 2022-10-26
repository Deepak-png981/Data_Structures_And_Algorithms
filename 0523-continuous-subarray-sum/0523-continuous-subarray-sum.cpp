class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int prefixSum = 0;
        mp[0] = -1;
        for(int i = 0; i<n; i++){
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            if(mp.count(remainder)){
                int len = i - mp[remainder];
                if(len == 1)
                    continue;
                if(len > 1)
                    return true;
            }
            mp[remainder] = i;
        }
        return false;
    }
};