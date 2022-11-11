class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<int>st;
        int n = s.size();
        for(int i= 0; i<n; i++)
            st.push(s[i]);
        for(int i = 0; i<n; i++){
            s[i] = st.top();
            st.pop();
        }
    }
};