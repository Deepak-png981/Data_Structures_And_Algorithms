class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>left_pro(n);
        vector<int>right_pro(n);
        //for left product
        left_pro[0] = 1;
        for(int i = 1; i<n; i++){
            left_pro[i] = left_pro[i-1]*nums[i-1];
        }
        //for right product
        right_pro[n-1] = 1;
        for(int i = n-2; i>=0; i--){
            right_pro[i] = right_pro[i+1]*nums[i+1]; 
        }
        //final products
        for(int i = 0; i<n; i++){
            ans[i] = left_pro[i]*right_pro[i];
        }
        return ans;
    }
};