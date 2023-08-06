//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    void helper(vector<string>&ans , int left , int right , string &S){
        if(left == right)
            ans.push_back(S);
        for(int i = left ; i<= right; i++){
            swap(S[left] , S[i]);
            helper(ans , left + 1 , right , S);
            swap(S[left] , S[i]);
        }
        
    }
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>ans;
        int right = S.size() - 1;
        int left = 0;
        helper(ans , left , right , S);
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends