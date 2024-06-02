class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element , count = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(count == 0){
                count++;
                element = nums[i];
            }
            else if(element == nums[i]) count++;
            else count--;
        }
        return element;
    }
};