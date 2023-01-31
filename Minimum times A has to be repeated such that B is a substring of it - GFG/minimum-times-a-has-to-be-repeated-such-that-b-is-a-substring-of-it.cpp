//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
             int x = 0, na = A.size(), nb = B.size();

        int cnt = 1;

        while( x < na ) {

            if( A[x] == B[0] ) {

                int i = x, j = 0;

                while( j<nb ) {

                    if( i == na ) {

                        cnt++;

                        i = 0;

                    }

                    if( A[i] == B[j] ) {

                        i++;

                        j++;

                    }

                    else    

                        break;

                }

                if( j >= nb ) 

                    return cnt;

            }

            x++;

        }

        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends