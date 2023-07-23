class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        sort(nums.begin() , nums.end());
        int count = 0 , longest = 1 , lastsq = INT_MIN;
        for(int i = 0; i<n; i++){
            if(nums[i] == lastsq + 1){
                count++;
                lastsq++;
            }else if(nums[i] != lastsq){
                count = 1;
                lastsq = nums[i];
            }
            longest = max(longest , count);
                
        }
        return longest;
    }
};