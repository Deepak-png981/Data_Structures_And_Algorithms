//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> vrr;
            sort(S.begin(),S.end());
            string str=S;
            vrr.push_back(str);
            while(true){
                std::next_permutation(str.begin(),str.end());
                if (str==S) break;
                vrr.push_back(str);
                
            }
            return vrr;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends