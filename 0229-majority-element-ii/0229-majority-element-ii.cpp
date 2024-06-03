class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0 , count2 = 0;
        int element1 = INT_MIN , element2 = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(count1 == 0 and nums[i] != element2){
                count1++;
                element1 = nums[i];
            }else if(count2 == 0 and nums[i] != element1){
                count2++;
                element2 = nums[i];
            }else if(element1 == nums[i])   count1++;
            else if(element2 == nums[i])    count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0 , count2 = 0;
        for(int i = 0; i<n;i++){
            if(nums[i] == element1)
                count1++;
            else if(nums[i] == element2)
                count2++;
        }
        vector<int>ans;
        if(count1 > n/3)
            ans.push_back(element1);
        if(count2 > n/3)
            ans.push_back(element2);
        return ans;
    }
};