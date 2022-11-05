class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0; 
        int n = nums.size();
        int countOfZeroes = 0;
        for(int i = 0; i<n ; i++){
            if(nums[i] != 0){
                nums[index++] = nums[i];
            }else{
                countOfZeroes++;
            }
        }
        for(int i = n - 1; i>= (n - countOfZeroes); i--)
            nums[i] = 0;
        return ;
    }
    
};