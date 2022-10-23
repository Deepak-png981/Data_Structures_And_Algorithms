class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1 and nums[0] == k)   return 1;
        int n = nums.size() , sum = 0 , ans = 0;
        unordered_map<int, int>count;
        count[sum] = 1;
        for(int element : nums){
            sum += element;
            if(count[sum - k] > 0)
                ans += count[sum - k];
            count[sum]++;
        }
        return ans;
    }
};