class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        
        int n = tokens.size();
        for(int i = 0; i<n; i++){
            if(
                tokens[i] == "+" or 
                tokens[i] == "-" or 
                tokens[i] == "*" or 
                tokens[i] == "/"
            ){
                
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                if(tokens[i] == "+"){
                    int ans = first + second;
                    st.push(ans);
                } 
                else if(tokens[i] == "-"){
                    int ans = second - first;
                    st.push(ans);
                }
                else if(tokens[i] == "*"){
                    int ans = second * first;
                    st.push(ans);
                }
                else if(tokens[i] == "/"){
                    int ans = second / first;
                    st.push(ans);
                }                
                
            }else{
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};