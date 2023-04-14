class Solution {
    
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i = n-1; i>=0; i--){
            int curr = prices[i];
            while(st.top() > curr)
                st.pop();
            ans[i] = st.top();
            st.push(curr);
        }
        for(int i = 0; i<n; i++)
        {
            if(ans[i] == -1)
            {
                ans[i] = prices[i];
            }else{
                ans[i] = prices[i] - ans[i];
            }
        }
        return ans;
            
    }
};