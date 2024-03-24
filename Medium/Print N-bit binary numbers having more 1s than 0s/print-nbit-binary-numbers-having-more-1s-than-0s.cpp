//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    // n=2
    // 11
    // 10
public:	
    void recursiveFunc(vector<string>&ans , string temp , int extraOnes , int numOfPlaces){
        //
        if(numOfPlaces == 0){
            ans.push_back(temp);
            return;
        }
        recursiveFunc(ans , temp + "1" , extraOnes + 1,  numOfPlaces-1);
        if(0 < extraOnes)
            recursiveFunc(ans , temp + "0" , extraOnes - 1, numOfPlaces - 1);
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string>ans;
	    recursiveFunc(ans , "" , 0 , n);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends