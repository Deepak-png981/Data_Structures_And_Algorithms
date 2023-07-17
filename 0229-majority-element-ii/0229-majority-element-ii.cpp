class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0 , cnt2 = 0;
        int ele1 = INT_MIN , ele2 = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(cnt1 == 0 and ele2 != nums[i]){
                cnt1++;
                ele1 = nums[i];
            }else if(cnt2 == 0 and ele1 != nums[i]){
                cnt2++;
                ele2 = nums[i];
            }else if(ele1 == nums[i]){
                cnt1++;
            }else if(ele2 == nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
                
        }
        vector<int>ans;
        int mini = (int)n/3;
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == ele1){
                cnt1++;
            }else if(nums[i] == ele2){
                cnt2++;
            }
        }
        if(cnt1 > mini){
            ans.push_back(ele1);
        }
        if(cnt2 > mini){
            ans.push_back(ele2);
        }
        return ans;
    }
};