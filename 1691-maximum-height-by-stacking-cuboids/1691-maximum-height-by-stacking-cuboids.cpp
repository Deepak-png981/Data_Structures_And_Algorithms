class Solution {
public:
    bool check(vector<int> prev, vector<int> curr){
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
            return true;
        return false;
    }
    int solve(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> currRow(n+1,0);        
        vector<int> next(n+1,0);        
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){

                int op1 = 0;
                if(prev == -1 || check(nums[prev],nums[curr])){
                    op1 = nums[curr][2] + next[curr+1];
                }
                int op2 = next[prev+1];

                currRow[prev+1] = max(op1,op2);
            }
            next = currRow;
        }
        return next[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &i : cuboids){
            sort(i.begin(),i.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return solve(cuboids);
    }
};