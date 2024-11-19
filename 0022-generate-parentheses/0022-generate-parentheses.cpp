class Solution {
private: 
    void backtrack(
        int openN , 
        int closedN ,
        int n ,
        vector<string>&result , 
        string& stack
    )
    {
        if(openN == closedN and openN == n){
            result.push_back(stack);
            return;
        }
        if(openN < n){
            stack += '(';
            backtrack(openN + 1 , closedN , n , result , stack);
            stack.pop_back();
        }
        if(closedN < openN){
            stack += ')';
            backtrack(openN , closedN+1 , n , result , stack);
            stack.pop_back();
        }
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        backtrack(0 , 0 , n , ans, s);
        return ans;
    }
};