class Solution {
private:
    bool palindrome(string s , int start , int end){
        while(start <= end)
            if(s[start++]  != s[end--])
                return false;
        return true;
    }
    void helper(int index , string s , vector<string>&ds, vector<vector<string>>&ans){
        if(index == s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i<s.size(); i++){
            if(palindrome(s , index , i)){
                ds.push_back(s.substr(index , i - index + 1));
                helper(i + 1, s , ds , ans);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        helper(0 , s ,ds , ans);
        return ans;
    }
};