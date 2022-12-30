class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int ,int>map;
        for(auto it : nums){
            map[it]++;
        }
        for(auto it : map){
            if(it.second >= 2)
                return true;
        }
        return false;
    }
};