class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int , int>>st;
        int n = temp.size();
        vector<int>ans(n,0);
        st.push({temp[0] , 0});
        for(int i = 1; i<n;i++){
            while(!st.empty() and (temp[i] > st.top().first)){
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp[i] , i});
        }
        return ans;
    }
};