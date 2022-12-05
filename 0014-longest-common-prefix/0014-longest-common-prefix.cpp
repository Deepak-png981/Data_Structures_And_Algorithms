class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        string res = "";
        for(int i = 0; i<first.size() ; i++){
            if(first[i] != last[i]){
                break;
            }
            res += first[i];
        } 
        return res;
    }
};