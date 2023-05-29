//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
         vector<string>v;
        for(int i = 0 ; i<N; i++){
            string temp = "";
            for(int j = 0; j<Dictionary[i].size(); j++){
                if(Dictionary[i][j] >= 'A' and Dictionary[i][j] <= 'Z'){
                    temp += Dictionary[i][j];
                }
                if(temp == Pattern)
                {
                    v.push_back(Dictionary[i]);
                    break;
                }
            }
        }
        if(v.size()==0)
            return {"-1"};
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends