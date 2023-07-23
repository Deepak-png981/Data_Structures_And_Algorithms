//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      void fun(int start,string s,string a,vector<string> &ans,set<string> st)
    {
        if(start==s.length())
        {
            ans.push_back(a.substr(0,a.length()-1));
            return;
        }
        string w="";
        for(int i=start;i<s.length();i++)
        {
            w+=s[i];
            if(st.find(w)!=st.end())
            {   
                fun(i+1,s,a+w+" ",ans,st);
            }
        }
        return;
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {   
        vector<string> ans;
        set<string> st;
        
        for(int i=0;i<n;i++)
            st.insert(dict[i]);
        fun(0,s,"",ans,st);
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends