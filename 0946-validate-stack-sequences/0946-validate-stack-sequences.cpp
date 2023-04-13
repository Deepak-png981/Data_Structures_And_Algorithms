class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int l = 0;
        for (int i : pushed) {
            st.push(i);
            while (!st.empty() && st.top() == popped[l]) {
                st.pop();
                l++;
            }
        }
        return st.empty();
    }
};
