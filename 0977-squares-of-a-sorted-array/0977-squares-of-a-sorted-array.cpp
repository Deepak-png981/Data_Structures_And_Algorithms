class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = n-1;
        vector<int>arr(n);
        for(int i = n-1 ; i>=0 ;  i--){
            int sq = 0;
        
            if( abs(nums[left]) < abs(nums[right]) ){
                sq = nums[right];
                right--;
            }else{
                sq = nums[left]; 
                left++;
            }
            arr[i] = sq*sq;   
        }
        return arr;
    }
};