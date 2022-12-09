//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    int dx[] = {2 , 2, 1,1 , -1, -1 , -2 , -2};
    int dy[] = {-1 , 1 , -2 , 2 , -2 , 2, -1, 1};
    long long mod = 1000000007;
    long long total = ( ((n*m)%mod) * ((n*m - 1)%mod) )%mod;
    long long attack = 0;
    for(int i= 0; i<n; i++){
        for(int j = 0; j<m; j++){
            for(int k = 0; k<8; k++){
                int newx = i+dx[k];
                int newy = j+dy[k];
                if(newx >= 0 and newx < n and newy >= 0 and newy <m){
                    attack++;
                }
            }
        }
    }
    return (total%mod - attack%mod)%mod;
}