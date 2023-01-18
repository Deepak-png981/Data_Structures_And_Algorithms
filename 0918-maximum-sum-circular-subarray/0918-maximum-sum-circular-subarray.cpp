class Solution {
private :
    int maxSum(vector<int>&nums){
        int sum = 0;
        int ans = INT_MIN;
        for(auto it : nums){
            sum += it;
            ans = max(sum , ans);
            if(sum < 0)
                sum = 0;
        }
        return ans;
    }
    int minSum(vector<int>&nums){
        int sum = 0;
        int ans = INT_MAX;
        for(auto it : nums){
            sum += it;
            ans = min(sum , ans);
            if(sum > 0)
                sum = 0;
        }
        return ans;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        //checking for the negative array
        bool check = true;
        int maxm = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] >= 0 ){                
                check = false;
                break;
            }
            maxm = max(maxm , nums[i]);
        }
        if(check)
            return maxm;
        //calc ans1;
        int ans1 = maxSum(nums);
        
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        int ans2 = sum - minSum(nums);
        return max(ans1 , ans2);
    }
    
    
    
    
    
    
    
    
    
    
    
    
};