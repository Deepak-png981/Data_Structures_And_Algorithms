class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//             for faster io operations
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        
        unordered_map<string , vector<string>>map;
        int n = strs.size();
        string temp;
        for(int i = 0; i<n; i++){
            temp = strs[i];
            sort(strs[i].begin() , strs[i].end());
            map[strs[i]].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto itr = map.begin() ; itr != map.end() ; ++itr){
            ans.push_back(itr->second);
        }
        return ans;
    }
};