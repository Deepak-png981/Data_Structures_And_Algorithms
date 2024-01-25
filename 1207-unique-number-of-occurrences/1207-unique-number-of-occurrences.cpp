class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int>mp;
        unordered_set<int>cnt;
        for(auto n : arr){
            mp[n]++;
        }
        for(auto c : mp){
            cnt.insert(c.second);
        }
        return cnt.size() == mp.size();
    }
};