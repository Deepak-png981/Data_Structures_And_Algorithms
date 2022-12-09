class Solution {
public:
    bool rec(vector<char>&str , int i){
        if(i >= str.size()/2)
            return true;
        if(str[i] == str[str.size() - 1 - i]){
            return rec(str , i+1);
        }
        else
            return false;
    }
    bool isPalindrome(string s) {
        vector<char>str ;
        for(auto &i : s){
            i = tolower(i);
            if(ispunct(i) or i == ' '){
                continue;
            }
            str.push_back(i);

        }
        return rec(str , 0);
    }
    
};