class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>ind(n+1 , 0);
        vector<int>ans;
        for(int i = 0; i<n; i++){
            ind[nums[i]]++;
        }
        for(int i = 1; i<n+1; i++){
            if(ind[i] > 1)
            {
                ans.push_back(i);
            }
        }
       for(int i = 1; i<n+1; i++){
           if(ind[i] == 0){
               ans.push_back(i);
               break;
           }
       }
        return ans;
    }
};