class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0 , right = n-1;
        vector<int>unsort = nums;
        sort(nums.begin() , nums.end());
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target)
                break;
            else if(sum < target){
                left++;
            }else
                right--;
        }
        vector<int>ans;
        for(int i = 0 ; i<n; i++){
            if(unsort[i] == nums[left] or unsort[i] == nums[right]){
                ans.push_back(i);
            }
        }
        return ans;
       
    }
};