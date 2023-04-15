class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            //agar index out of bond chale jaye use pop back
            while(!dq.empty() and dq.front() == i-k)
                dq.pop_front();
            
            //chote elements to pop ker rhe hai because the
            //dq should be in a decreasing fashion
            while(!dq.empty() and nums[dq.back()] <= nums[i])
                    dq.pop_back();
            dq.push_back(i);
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};