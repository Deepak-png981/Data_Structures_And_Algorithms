class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int left = 0 , right = n-1;
        for(int i = n-1; i>=0; i--){
            int sq = 0;
            if(abs(nums[left]) < abs(nums[right])){
                sq = nums[right]*nums[right];
                right--;
            }
            else{
                sq = nums[left]*nums[left];
                left++;
            }
            ans[i] = sq;
        }
        return ans;
    }
};