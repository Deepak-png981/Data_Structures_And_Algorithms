//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{  
private:
    bool isPalindrone(string str){
        int i = 0 , j = str.length()-1;
        while(i < j){
            if(str[i] != str[j])
                return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
public:
    int addMinChar(string str){    
        if(isPalindrone(str))
            return 0;
        for(int i = str.size() - 1; i>= 0; i--){
            if(isPalindrone(str.substr(0 , i))){
                return str.length() - i;
            }
        }
        return str.length();
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends