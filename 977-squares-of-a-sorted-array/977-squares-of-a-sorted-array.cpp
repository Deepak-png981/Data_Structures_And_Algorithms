class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
//         nlogn wala solution
        /*
        for(int i = 0; i< nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin() , nums.end());
        return nums;
        */
        
//         o(n) solution
        int n = nums.size();
        vector<int> arr(n);
        int left = 0 , right = n - 1 ;
        for(int i = n - 1; i>= 0; i--){
            int sq = 0;
            if(abs(nums[left]) < abs(nums[right])){
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