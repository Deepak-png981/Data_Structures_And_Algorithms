//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int isDivisible(string s){
	    vector<vector<int>> v={{0,1},{2,0},{1,2}};
	    int cur=0;
	    for(auto c:s) {
	        cur=v[cur][c-'0'];
	    }
	    return cur==0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends