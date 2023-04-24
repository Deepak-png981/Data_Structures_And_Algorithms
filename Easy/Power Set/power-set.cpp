//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void solve(vector<string>&ans,int i,int n,string op,string s){
        if(i==n){
            if(op!="")
            ans.push_back(op);
            return ;
        }
        solve(ans,i+1,n,op+s[i],s);//include
         solve(ans,i+1,n,op,s);//exclude
    }
	public:
		vector<string> AllPossibleStrings(string s){
		   vector<string>ans;
            solve(ans,0,s.length(),"",s);
            sort(ans.begin(),ans.end());
            return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends