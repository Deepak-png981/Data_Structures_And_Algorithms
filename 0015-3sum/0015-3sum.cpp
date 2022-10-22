class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sorting the array
        sort(nums.begin() , nums.end());
        //size 3 se chota hua to kaise chalega
        if(nums.size() < 3) return {};
        //agar sorted array ka phla element +ve nikla to kaise chalega babu bhaiya
        if(nums[0] > 0) return{};
        vector<vector<int>> ans;
        for(int i = 0 ; i<nums.size(); i++){
            if(nums[i] > 0)  //+ve elements milne shuru hogye S.A mein to zero nhi banaskte
                break;
            if(i>0 and nums[i] == nums[i-1]) // duplicate niklenge to continue kero bhaiya
                continue;
            //do pointers banao low and high or sum ko 0 se initialize kero 
            int low = i+1 , high = nums.size() - 1 , sum = 0;
            while(low < high){  //Search using two pointers, binary search ki trha
                sum = nums[i] + nums[low] + nums[high]; // sum nikala hai
                if(sum > 0)
                    high--;
                else if(sum < 0)
                    low++;
                else{   //hume wo teeno mil gye hai
                    ans.push_back({nums[i] , nums[low] , nums[high]});
                    //ab ye elements duplicate na ho isliye ish case ko handle ker rhe hai
                    int low_last = nums[low] , high_last = nums[high];
                    //duplicate na aye isiliye main low or high ko last occurence of nums[low] and nums[high]
                    //tak chodh ker aunga
                    while(low < high and nums[low] == low_last) 
                        low++;
                    while(low < high and nums[high] == high_last)
                        high--;
                }
            }
        }
        return ans;
    }
};