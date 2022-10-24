class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //size of nums
        int n = nums.size();
        for(int i = 0 ; i <n; i++){
            //finding the index so that I can multiply by -1 further
            int index = abs(nums[i]) - 1;
            //multiplying the nums[index] with -1 , if it is occuring two times
            //then it will automatically convert into positive
            nums[index] *= -1;
            //if it is positive then it is occuring two times mere bhai
            if(nums[index] >= 0)
                return abs(nums[i]);            
        }
        return -1;
                 
    }
};