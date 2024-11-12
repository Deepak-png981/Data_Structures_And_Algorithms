class Solution {
private:
    bool isValid(string str){
        if(str[0] == ')')
            return false;
        stack<char>st;
        int n = str.size();
        for(int i = 0; i<n; i++){
            if(str[i] == '('){
                st.push(str[i]);
            }else if(st.empty() and str[i] == ')')
                return false;
            else if(str[i] == ')')
                st.pop();
        }
        return st.empty();
    }
public:
    vector<string> generateParenthesis(int n) {
        string st = "";
        vector<string>ans;
        for(int i = 0; i<n; i++){
            st += '(';
        }
        for(int i = 0; i<n; i++){
            st += ')';
        }
        ans.push_back(st);
        while(next_permutation(st.begin() , st.end())){
            if(isValid(st))
                ans.push_back(st);
        }
        return ans;
    }
};