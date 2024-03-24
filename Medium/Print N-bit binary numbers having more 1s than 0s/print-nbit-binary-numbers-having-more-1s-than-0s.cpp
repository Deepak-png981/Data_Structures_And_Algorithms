//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
//4
// 1111
// 1110
// 1101
// 1011
// 1010
    void recursiveFunc(vector<string>&ans , string temp , int extraOnes , int remainingPlaces){
        if(remainingPlaces == 0){
            ans.push_back(temp);
            return;
        }
        //add 1 to the string and move on
        recursiveFunc(ans , temp + "1" ,extraOnes + 1 , remainingPlaces-1);
        //add 0 from the string and move on
        if(0 < extraOnes){
            recursiveFunc(ans , temp + "0" , extraOnes - 1 , remainingPlaces -1);
        }
        
        
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string>ans;
	    string temp="";
	    recursiveFunc(ans , temp , 0 , n);
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