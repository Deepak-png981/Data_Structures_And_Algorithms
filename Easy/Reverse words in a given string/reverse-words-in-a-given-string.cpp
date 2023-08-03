//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string str) 
    { 
        string ans = "";
        string temp = "";
        int n = str.length();
        for(int i = n-1; i>=0; i--){
            if(str[i] == '.'){
                reverse(temp.begin() , temp.end());
                ans += temp;
                ans.push_back('.');
                temp = "";
            }else{
                temp += str[i];
            }
        }
        reverse(temp.begin() , temp.end());
        ans += temp;
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends