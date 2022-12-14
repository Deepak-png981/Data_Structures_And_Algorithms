//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
         bool valid=false;
        for(auto i:str)if(i=='0')valid=true;
        if(!valid)return {-1};
        
        int l=0,r=0;
        int count=0,maxCount=-1,al=-1,ar=-1;
        while(r<n){
            count+=str[r]=='1'?-1:1;
            if(count<0){
                l=r+1;
                count=0;
            }
            if(count>maxCount){
                al=l;
                ar=r;
                maxCount=count;
            }
            r++;
        }
        return {al+1,ar+1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends