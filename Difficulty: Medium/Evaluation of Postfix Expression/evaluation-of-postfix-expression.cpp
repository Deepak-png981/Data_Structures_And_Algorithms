//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int>st;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i] == "*" or arr[i] == "+" 
            or arr[i] == "-" or arr[i] == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int result = 0;
                if(arr[i] == "+")
                    result = b + a;
                else if(arr[i] == "-")
                    result = b-a;
                else if(arr[i] == "/")
                    result = b/a;
                else if(arr[i] =="*")
                    result = b*a;
                st.push(result);
            }else{
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends