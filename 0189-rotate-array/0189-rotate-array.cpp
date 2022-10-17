class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int indx = (i + k)%n;
            temp[indx] = nums[i];
        }
        for(int i = 0; i<n; i++)
                nums[i] = temp[i];
        return;
    }
};