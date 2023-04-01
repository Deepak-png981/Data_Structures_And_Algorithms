class Solution {
    vector<int>nextSmallest(vector<int> heights , int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i = n-1; i>=0; i--){
            int curr = heights[i];
            while(st.top() != -1 and heights[st.top()] >= curr)
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmallest(vector<int>heights , int n){
        vector<int> ans(n);
        stack<int>st;
        st.push(-1);
        for(int i = 0; i<n; i++){
            int curr= heights[i];
            while(st.top() != -1 and heights[st.top()] >= curr)
                st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n);
        next = nextSmallest(heights , n);
        vector<int>prev(n);
        prev = prevSmallest(heights, n);
        
        int mx = INT_MIN;
        for(int i =0;i<n; i++){
            if(next[i] == -1)
                next[i] = n;
            mx = max( mx , heights[i] * ( next[i] - prev[i] - 1 ));
        }
        return mx;
    }
};