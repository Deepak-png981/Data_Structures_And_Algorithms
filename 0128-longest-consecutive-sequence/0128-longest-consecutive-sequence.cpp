class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin() , nums.end());
        int ans = 0;
        // if(nums.size() == 0)    return 1;
        for(auto it : numSet){
            if(numSet.find(it-1) == numSet.end()){ //start of the sequence
                int num = it;
                int currentStreak = 1;
                while(numSet.find(num + 1) != numSet.end()){
                    num++;
                    currentStreak++;
                }
                ans = max(currentStreak , ans);
            }
        }
        return ans;
    }
};