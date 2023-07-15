class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //using cycle detection
        //step 1 : slow -> one step , fast -> two step
        int slow = nums[0] , fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        //step 2 : place fast at initial point and start movind one step both
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};