class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0 ,sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        for(int i = 0 ; i<n; i++){
            if(left == sum - left - nums[i])
                return i;
            left += nums[i];
        }
        return -1;
        
    }
};