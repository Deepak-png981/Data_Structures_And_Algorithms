//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> st;
        for(int i=0;i<N;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                bool a=true;
                while(st.size() and st.top()<=abs(asteroids[i]) and st.top()>0){
                    if(st.top()==abs(asteroids[i])){
                        st.pop();
                        a=false;
                        break;
                    }
                st.pop();
                }
                if((st.empty() or st.top()<0) and a)st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(st.size()){
            int temp = st.top();
            st.pop();
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends