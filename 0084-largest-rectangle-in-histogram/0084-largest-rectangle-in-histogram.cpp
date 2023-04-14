class Solution {
private:
    vector<int> nextSmallerElement(vector<int>heights){
        int n = heights.size();
        vector<int>next(n);
        stack<int>st;
        st.push(-1);
        for(int i = n-1; i>=0; i--){
            int curr = heights[i];
            while(st.top() != -1 and heights[st.top()] >= curr)
                    st.pop();
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }
    
    vector<int> prevSmallerElement(vector<int>heights){
        int n = heights.size();
        vector<int>prev(n);
        stack<int>st;
        st.push(-1);
        for( int i = 0; i<n; i++ ){
            int curr = heights[i];
            while(st.top() != -1 and heights[st.top()] >= curr)
                    st.pop();
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n);
        next = nextSmallerElement(heights);
        vector<int>prev(n);
        prev = prevSmallerElement(heights);
        int maxArea = INT_MIN;
        for(int i = 0 ; i<n; i++){
            
            if(next[i] == -1)
                next[i] = n;
            int length = next[i] - prev[i] - 1;
            int breadth = heights[i];
            int newArea = length * breadth;
            maxArea = max(maxArea , newArea);
        }
        return maxArea;
    }
};