class Solution {
public:
    string removeDuplicates(string s) {
         string ans;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(ans.size() and ans.back() == s[i]){
                ans.pop_back();
            }else
                ans.push_back(s[i]);
        }
        return ans;
    }
};