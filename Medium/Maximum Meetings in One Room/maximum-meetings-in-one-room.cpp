//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    static bool cmp(pair<int , pair<int,int> >a , pair<int, pair<int,int> >b){
        return a.second.second < b.second.second;
    }
public:
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &f){
        vector<pair<int,pair<int,int> > >v;
        for(int i = 0; i<n; i++){
            v.push_back({ i+1 , { s[i] , f[i] } });
        }
        sort(v.begin() , v.end() , cmp);
        vector<int>ans;
        int ansEnd = v[0].second.second;
        ans.push_back( v[0].first );
        for(int i = 1; i<n; i++){
            if(v[i].second.first > ansEnd){
                ans.push_back( v[i].first );
                ansEnd = v[i].second.second;
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends