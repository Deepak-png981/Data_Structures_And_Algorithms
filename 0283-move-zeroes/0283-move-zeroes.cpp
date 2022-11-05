class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int front = 0 , n = nums.size();
        int countZero = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                nums[front++] = nums[i];               
            else if(nums[i] == 0)
                countZero++;
        }
        for(int i = n-1; i>= (n - countZero ); i--)
            nums[i] = 0;
        
    }
};