//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int matchGame(long long N) {
        //1 A
        //2 A
        //3 A
        //4 A
        //5 A1 B4 -> B
        //6 A4 B1 A1 -> A
        //7 A1 B4 A2 -> A
        //8 A4 B1 A3 -> A
        //9 A1 B4 A4 -> A
        //10 A4 B1 A4 B1 -> B
        //13 A1 B4 A1 B4 A3 -> A
        //15 A1 B4 A1 B4 A4 B1 -> B
        if(N%5 == 0)
            return -1;
        else
         return N%5;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends