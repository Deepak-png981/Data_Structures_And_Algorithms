class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int front = 0 , end = nums.size()-1 , n = nums.size();
        int countZero = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                nums[front++] = nums[i];               
            else if(nums[i] == 0)
                countZero++;
        }
//         if(countZero == 0)
//             return;
// //         handling {0,1} exception here
//         if(countZero == 1)
            // nums[nums.size() - 1] = 0;
        for(int i = n-1; i>= (n - countZero ); i--)
            nums[i] = 0;
        
    }
};